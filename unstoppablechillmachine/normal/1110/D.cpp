#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;

const int N = 1e6 + 10;
int dp[N][4][4];
void source() {
  int n, m;
  cin >> n >> m;
  vector<int> cnt(m + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  if (m == 1) {
    cout << cnt[1] / 3;
    exit(0);
  }
  if (m == 2) {
    cout << cnt[1] / 3 + cnt[2] / 3;
    exit(0);
  }
  if (m == 3) {
    int ans = 0;
    for (int i = 0; i <= 2; i++) {
      if (min(cnt[1], min(cnt[2], cnt[3])) >= i) {
        int a = cnt[1] - i, b = cnt[2] - i, c = cnt[3] - i;
        ans = max(ans, i + a / 3 + b / 3 + c / 3);
      }
    }
    cout << ans;
    exit(0);
  }
  for (int i = 0; i <= m; i++) {
    for (int c1 = 0; c1 < 3; c1++) {
      for (int c2 = 0; c2 < 3; c2++) {
        dp[i][c1][c2] = -INF;
      }
    }
  }
  for (int c1 = 0; c1 < 3; c1++) {
    for (int c2 = 0; c2 < 3; c2++) {
      if (cnt[1] >= c1 && cnt[2] >= c1 + c2 && cnt[3] >= c1 + c2 && cnt[4] >= c2) {
        dp[3][c1][c2] = c1 + c2 + (cnt[1] - c1) / 3 + (cnt[2] - c1 - c2) / 3;
      }
    }
  }
  for (int i = 3; i < m - 1; i++) {
    for (int c1 = 0; c1 < 3; c1++) {
      for (int c2 = 0; c2 < 3; c2++) {
        for (int c3 = 0; c3 < 3; c3++) {
          if (cnt[i] >= c1 + c2 + c3 && cnt[i + 1] >= c2 + c3 && cnt[i + 2] >= c3) {
            dp[i + 1][c2][c3] = max(dp[i + 1][c2][c3], dp[i][c1][c2] + c3 + (cnt[i] - c1 - c2 - c3) / 3);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int c1 = 0; c1 < 3; c1++) {
    for (int c2 = 0; c2 < 3; c2++) {
      ans = max(ans, dp[m - 1][c1][c2] + (cnt[m - 1] - c1 - c2) / 3 + (cnt[m] - c2) / 3);
    }
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}