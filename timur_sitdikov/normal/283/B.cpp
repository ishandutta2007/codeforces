#include <iostream>
#include <vector>
using namespace std;

class CowProgramSolver {
 public:
  void ReadInputData() {
    int n;
    cin >> n;
    offset_.resize(n + 1);
    for(int i = 2; i <= n; i++) {
      cin >> offset_[i];
    }
  }

  vector<int64_t> Solve() {
    int n = offset_.size() - 1;
    accumulated_sum_[0].resize(n + 1);
    accumulated_sum_[1].resize(n + 1);
    visited_[0].resize(n + 1);
    visited_[1].resize(n + 1);
    vector<int64_t> solutions(n);
    for(int i = 1; i < n; i++) {
      offset_[1] = i;
      visited_[1][1] = 0;
      solutions[i] = RecursiveGo(1, 1);
    }
    return solutions;
  }

  int64_t RecursiveGo(int position, int direction) {
    if (position <= 0 || position >= (int)offset_.size()) {
      return 0;
    }
    if (visited_[direction][position] == 1) {
      visited_[direction][position] = 2;
      accumulated_sum_[direction][position] = -1;
      return -1;
    }
    if (visited_[direction][position] == 2) {
      return accumulated_sum_[direction][position];
    }
    visited_[direction][position] = 1;
    int multiplier = (direction ? 1 : -1);
    accumulated_sum_[direction][position] = RecursiveGo(
      position + offset_[position] * multiplier, direction ^ 1);
    if (accumulated_sum_[direction][position] != -1) {
      accumulated_sum_[direction][position] += offset_[position];
    }
    visited_[direction][position] = 2;
    return accumulated_sum_[direction][position];
  }

 private:
  vector<int> offset_;
  vector<int64_t> accumulated_sum_[2];
  vector<int> visited_[2];
};

// To execute C++, please define "int main()"
int main() {
  CowProgramSolver solver;
  solver.ReadInputData();
  vector<int64_t> solution = solver.Solve();
  for(size_t i = 1; i < solution.size(); i++) {
    cout << solution[i] << endl;
  }
  return 0;
}

/*
Test case #1:
4
2 4 1

Answer:
3 6 8 

Test case #2:
3
1 2

Answer:
-1 -1
*/