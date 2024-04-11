#include <iostream>
using namespace std;

int main() {
  int a[100000];
  int n;
  cin >> n;
  int dp[100000];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0] = 1;
  int max = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i - 1]) {
      dp[i] = dp[i - 1] + 1;
      if (max < dp[i]) {
        max = dp[i];
      }
    } else {
      dp[i] = 1;
    }
  }
  cout << max << endl;
  return 0;
}