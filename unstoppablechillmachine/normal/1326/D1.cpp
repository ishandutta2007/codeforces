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

const int N = 5010;
bool seg[N][N], gr_pal[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = SZ(s);
    for (int i = 0; i <= n; i++) {
      gr_pal[i] = false;
      for (int j = 0; j <= n; j++) {
        seg[i][j] = false;
      }
    }
    for (int i = 0; i < n; i++) {
      seg[i][i] = true;
      for (int j = 1; i - j >= 0 && i + j < n; j++) {
        if (s[i - j] != s[i + j]) {
          break;
        }
        seg[i - j][i + j] = true;
      }
      if (i + 1 < n && s[i] == s[i + 1]) {
        seg[i][i + 1] = true;
        for (int j = 1; i - j >= 0 && i + 1 + j < n; j++) {
          if (s[i - j] != s[i + 1 + j]) {
            break;
          }
          seg[i - j][i + 1 + j] = true;
        }
      }
    }
    gr_pal[0] = true;
    for (int i = 1; i <= n / 2; i++) {
      if (s[i - 1] != s[n - i]) {
        break;
      }
      gr_pal[i] = true;
    }
    if (seg[0][n - 1]) {
      cout << s << '\n';
      continue;
    }
    int ans = 0;
    pair<int, int> best;
    for (int len1 = 0; len1 < n; len1++) {
      for (int len2 = 0; len2 + len1 < n; len2++) {
        if (len1 == len2) {
          if (gr_pal[len1] && len1 * 2 > ans) {
            ans = len1 * 2;
            best = {len1, len2};
          }
        }
        else if (len1 > len2) {
          if (gr_pal[len2] && seg[len2][len1 - 1]) {
            if (len1 + len2 > ans) {
              ans = len1 + len2;
              best = {len1, len2};
            }
          }
        }
        else {
          if (gr_pal[len1] && seg[n - len2][n - len1 - 1]) {
            ans = len1 + len2;
            best = {len1, len2};
          }
        }
      }
    }
    for (int i = 1; i <= best.F; i++) {
      cout << s[i - 1];
    }
    for (int i = best.S; i >= 1; i--) {
      cout << s[n - i];
    }
    cout << '\n';
    //cout << best.F << ' ' << best.S << '\n';
  }  
}