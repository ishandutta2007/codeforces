#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 110;
const int INF = 1e9 + 10;
int dp[N][N][26][26], c[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c = 'z'; c > 'a'; c--) {
      char need = c - 1;
      for (;;) {
        string to_c;
        int id = -1;
        for (int i = 0; i < SZ(s); i++) {
          if (s[i] != c) {
            continue;
          }
          bool ok = false;
          if (i + 1 < SZ(s)) {
            if (s[i + 1] == need) ok = true;
          }
          if (i  > 0) {
            if (s[i - 1] == need)
            ok = true;
          }
          if (ok) {
            id = i;
            break;
          }
        }
        if (id == -1) {
          break;
        }
        for (int i = 0; i < id; i++) {
          to_c.pb(s[i]);
        }
        for (int i = id + 1; i < SZ(s); i++) {
          to_c.pb(s[i]);
        }
        s = to_c;
      }
    }
    //cout << s << '\n';
    cout << n - SZ(s) << '\n';
}