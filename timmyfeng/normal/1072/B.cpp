#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int A = 4;

int dp[N][A];
int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < A; ++j) {
      if (i == 0) {
        dp[i][j] = -2;
      } else {
        dp[i][j] = -1;
        for (int k = 0; k < A; ++k) {
          if (dp[i - 1][k] != -1 && (j | k) == a[i] && (j & k) == b[i]) {
            dp[i][j] = k;
          }
        }
      }
    }
  }

  int cur = 0;
  while (cur < A && dp[n - 1][cur] == -1) {
    ++cur;
  }

  if (cur == A) {
    cout << "NO\n";
  } else {
    cout << "YES\n";

    vector<int> ans;
    while (cur != -2) {
      ans.push_back(cur);
      cur = dp[--n][cur];
    }

    while (!ans.empty()) {
      cout << ans.back() << " ";
      ans.pop_back();
    }
    cout << "\n";
  }
}