#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int dp[N][5];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      dp[i][j] = -1;
      if (i == 0) {
        dp[i][j] = -2;
      } else {
        for (int k = 0; k < 5; ++k) {
          if (dp[i - 1][k] != -1) {
            if ((a[i - 1] < a[i] && k < j) || (a[i - 1] > a[i] && k > j) || (a[i - 1] == a[i] && k != j)) {
              dp[i][j] = k;
            }
          }
        }
      }
    }
  }

  int b = 0;
  while (b < 5 && dp[n - 1][b] == -1) {
    ++b;
  }

  if (b == 5) {
    cout << -1 << "\n";
  } else {
    vector<int> ans = {b};
    int i = n - 1;
    while (i > 0) {
      b = dp[i][b];
      ans.push_back(b);
      --i;
    }

    reverse(ans.begin(), ans.end());
    for (int j : ans) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
}