#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class MultipleFreeSolver {
  private:
    int multiplier_;
    vector<int> numbers_;

  public:

    void Read() {
      int n;
      cin >> n >> multiplier_;
      numbers_.resize(n);
      for(int i = 0; i < n; i++) {
        cin >> numbers_[i];
      }
      sort(numbers_.begin(), numbers_.end());
    }

    int GetMaximalMultipleFreeSetSize() {
      set<int> optimal_set;
      for(auto number: numbers_) {
        if (number % multiplier_ != 0 || 
            optimal_set.find(number / multiplier_) == optimal_set.end()) {
          optimal_set.insert(number);
        }
      }
      return optimal_set.size();
    }
};

// To execute C++, please define "int main()"
int main() {
  MultipleFreeSolver solver;
  solver.Read();
  cout << solver.GetMaximalMultipleFreeSetSize() << endl;
}

/*
Test case #1:
6 2
2 3 6 5 4 10

Answer: 3


Test case #2:
6 1
2 3 6 5 4 10

Answer: 6
*/