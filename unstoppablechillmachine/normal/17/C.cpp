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

const int N = 155;
int dp[N][N][N][3], dp2[N][N][N][3], nxt[N][3];

const int MOD = 51123987;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string s2;
  for (auto it : s) {
    if (s2.empty() || s2.back() != it) {
      s2.pb(it);
    }
  }
  int sz = SZ(s2);
  s2.insert(s2.begin(), ' ');
  nxt[sz][0] = nxt[sz][1] = nxt[sz][2] = sz + 1;
  for (int i = sz - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][s2[i + 1] - 'a'] = i + 1;
  }
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int cnta = 0; cnta <= i; cnta++) {
      for (int cntb = 0; cnta + cntb <= i; cntb++) {
        for (int lpos = 0; lpos <= sz; lpos++) {
          for (int lst = 0; lst < 3; lst++) {
            int npos;
            if (i == 0 || lst != 0) npos = nxt[lpos][0];
            else npos = lpos;
            if (npos <= sz) {
              add(dp2[cnta + 1][cntb][npos][0], dp[cnta][cntb][lpos][lst]);
            }
            if (i == 0 || lst != 1) npos = nxt[lpos][1];
            else npos = lpos;
            if (npos <= sz) {
              add(dp2[cnta][cntb + 1][npos][1], dp[cnta][cntb][lpos][lst]);
            }
            if (i == 0 || lst != 2) npos = nxt[lpos][2];
            else npos = lpos;
            if (npos <= sz) {
              add(dp2[cnta][cntb][npos][2], dp[cnta][cntb][lpos][lst]);
            }
          }
        }
      }
    }
    for (int cnta = 0; cnta <= i + 1; cnta++) {
      for (int cntb = 0; cnta + cntb <= i + 1; cntb++) {
        for (int lpos = 0; lpos <= sz; lpos++) {
          for (int lst = 0; lst < 3; lst++) {
            dp[cnta][cntb][lpos][lst] = dp2[cnta][cntb][lpos][lst];
            dp2[cnta][cntb][lpos][lst] = 0;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int cnta = 0; cnta <= n; cnta++) {
    for (int cntb = 0; cnta + cntb <= n; cntb++) {
      int cntc = n - cnta - cntb;
      if (max({cnta, cntb, cntc}) - min({cnta, cntb, cntc}) <= 1) {
        for (int lpos = 0; lpos <= sz; lpos++) {
          for (int lst = 0; lst < 3; lst++) {
            add(ans, dp[cnta][cntb][lpos][lst]);
          }
        }
        //cout << cnta << ' ' << cntb << ' ' << cntc << ' ' << ans << '\n';
      }
    }
  }
  cout << ans << '\n';
}