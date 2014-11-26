#ifndef QUICKRANK_LEARNING_FORESTS_MATRIXNET_H_
#define QUICKRANK_LEARNING_FORESTS_MATRIXNET_H_

#include "learning/forests/lambdamart.h"

namespace quickrank {
namespace learning {
namespace forests {

class MatrixNet : public LambdaMart {
 public:
  const unsigned int treedepth_;  //>0

 public:
  MatrixNet(unsigned int ntrees, float shrinkage, unsigned int nthresholds,
            unsigned int treedepth, unsigned int minleafsupport,
            unsigned int esr)
      : LambdaMart(ntrees, shrinkage, nthresholds, 1 << treedepth,
                   minleafsupport, esr),
        treedepth_(treedepth) {
  }

  const char *whoami() const {
    return "MATRIXNET";
  }

  void showme() {
    LambdaMart::showme();
    printf("\ttree depth = %u\n", treedepth_);
  }

  void learn();

  void write_outputtofile(const char *filename);
};

}  // namespace forests
}  // namespace learning
}  // namespace quickrank

#endif