#include <iostream>
#include <vector>

class SequenceProblemSolver {
 public:
  void ReadSequence() {
    int n;
    std::cin >> n;
    n = 2 * n - 1;
    sequence_.resize(n);
    for(int i = 0; i < n; i++) {
      std::cin >> sequence_[i];
    }
  }

  int GetMaximalSum() {
    int abs_min = abs(sequence_[0]), sum = 0, count_negative = 0;
    for(size_t i = 0; i < sequence_.size(); i++) {
      abs_min = std::min(abs_min, abs(sequence_[i]));
      sum += abs(sequence_[i]);
      if (sequence_[i] < 0) {
        count_negative++;
      }
    }
    if (sequence_.size() % 4 == 3 && count_negative % 2 == 1) {
      sum -= 2 * abs_min;
    }
    return sum;
  }

 private:
  std::vector<int> sequence_;
};

// To execute C++, please define "int main()"
int main() {
  SequenceProblemSolver solver;
  solver.ReadSequence();
  std::cout << solver.GetMaximalSum() << std::endl;
  return 0;
}