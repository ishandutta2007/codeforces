#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MaximumXorSecondarySolver {
  private:
    vector<int> numbers_;

  public:
    void ReadInputData() {
      int n;
      cin >> n;
      numbers_.reserve(n);
      for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers_.push_back(a);
      }
    }

    int GetMaximumXorSecondary() {
      int maximum_xor_secondary = 0;
      stack<int> suffix_maximum;
      suffix_maximum.push(numbers_[0]);
      for(size_t i = 1; i < numbers_.size(); i++) {
        while(!suffix_maximum.empty() && suffix_maximum.top() < numbers_[i]) {
          maximum_xor_secondary = max(
            maximum_xor_secondary, suffix_maximum.top() ^ numbers_[i]);
          suffix_maximum.pop();
        }
        if (!suffix_maximum.empty()) {
          maximum_xor_secondary = max(
            maximum_xor_secondary, suffix_maximum.top() ^ numbers_[i]);
        }
        suffix_maximum.push(numbers_[i]);
      }
      return maximum_xor_secondary;
    }
};

// To execute C++, please define "int main()"
int main() {
  MaximumXorSecondarySolver solver;
  solver.ReadInputData();
  cout << solver.GetMaximumXorSecondary() << endl;
  return 0;
}

/*
Test case #1:
5
5 2 1 4 3

Answer: 7

Test case #2:
5
9 8 3 5 7

Answer: 15
*/