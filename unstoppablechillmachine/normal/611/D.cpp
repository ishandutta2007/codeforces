#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int MOD = 1e9 + 7;
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

const int N = 5010;
short lcp[N][N];
int dp[N][N], pref[N][N];
char c[N];  

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int l = n; l >= 1; l--) {
    for (int r = n; r >= l; r--) {
      if (c[l] != c[r]) {
        lcp[l][r] = 0;
      }
      else {
        lcp[l][r] = lcp[l + 1][r + 1] + 1;
      }
    }
  }
  for (int r = 1; r <= n; r++) {
    for (int l = r; l >= 1; l--) {
      if (c[l] == '0') {
        dp[l][r] = 0;
        continue;
      }
      if (l == 1) {
        dp[l][r] = 1;
      }
      else {
        int len = r - l + 1;
        dp[l][r] = pref[l - 1][len - 1];
        if (l - 1 >= len) {
          if (lcp[l - len][l] < len && c[l - len + lcp[l - len][l]] < c[l + lcp[l - len][l]]) {
            add(dp[l][r], dp[l - len][l - 1]);
            //cout << "KEK " << l << ' ' << r << '\n';
          }
        }
      }
    }
    for (int len = 1; len <= n; len++) {
      pref[r][len] = pref[r][len - 1];
      if (len <= r) {
        add(pref[r][len], dp[r - len + 1][r]);
      }
    }
  }
  cout << pref[n][n] << '\n';
}