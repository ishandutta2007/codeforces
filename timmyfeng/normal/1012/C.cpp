#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 2;
const int OO = 1e9;

int a[N];
int ans[N];
int dp[N][N / 2];
int dp_no[N][N / 2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[++n] = 0;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n / 2; ++j) {
      ans[j] = OO;
      dp[i][j] = OO;
      dp_no[i][j] = OO;
    }
  }

  dp_no[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n / 2; ++j) {
      if (j >= 1) {
        if (i >= 2) {
          dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + max(0, a[i - 1] - min(a[i], a[i - 2]) + 1));
        }
        dp[i][j] = min(dp[i][j], dp_no[i - 1][j - 1] + max(0, a[i - 1] - a[i] + 1));
      }
      dp_no[i][j] = min(dp_no[i - 1][j], dp[i - 1][j] + max(0, a[i] - a[i - 1] + 1));
      ans[j] = min(ans[j], dp_no[i][j]);
    }
  }

  for (int i = 1; i <= n / 2; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}