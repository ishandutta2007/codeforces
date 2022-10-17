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

const int N = 2010;
char c[N][N];
int d[N][N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
    }
  }  
  for (int i = 1; i <= n; i++) {
    int f = 0, e = 0;
    for (int j = 1; j <= n; j++) {
      if (c[i][j] == 'B') {
        if (!f) {
          f = j;
        }
        e = j;
      }
    }
    if (!f) {
      //cout << i << '\n';
      for (int i2 = 1; i2 <= n; i2++) {
        d[i2][1]++;
        d[i2][n + 1]--;
      }
      continue;
    }
    if (e - f >= k) {
      continue;
    }
    //cout << f << ' ' << e << '\n';
    int l = max(e - k + 1, 1), r = f;
    for (int i2 = max(1, i - k + 1); i2 <= i; i2++) {
      //cout << i << ' ' << i2 << ' ' << l << ' ' << r << '\n';
      d[i2][l]++;
      d[i2][r + 1]--;
    }
  }
  for (int j = 1; j <= n; j++) {
    int f = 0, e = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i][j] == 'B') {
        if (!f) {
          f = i;
        }
        e = i;
      }
    }
    if (e - f >= k) {
      continue;
    }
    if (!f) {
      for (int i2 = 1; i2 <= n; i2++) {
        d[i2][1]++;
        d[i2][n + 1]--;
      }
      continue;
    }
    //cout << j << ' ' << f << ' ' << e << '\n';
    int l = max(e - k + 1, 1), r = f;
    int l2 = max(1, j - k + 1), r2 = j;
    for (int i2 = l; i2 <= r; i2++) {
      d[i2][l2]++;
      d[i2][r2 + 1]--;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = 1; j <= n; j++) {
      cur += d[i][j];
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
}