#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int MOD = 998244353;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int sum(int a, int b) {
  a += b;
  return (a >= MOD ? a - MOD : a);
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

const int N = 3610;
int dpx[N][N], dpy[N][N], c[N][N], f[N];
bool x[N], y[N];

int C(int n, int k) {
  if (n < 0 || k < 0 || k > n) {
    return 0;
  }
  return c[n][k];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  f[0] = 1;
  for (int i = 1; i <= max(n, m); i++) {
    f[i] = mult(f[i - 1], i);
  }
  c[0][0] = 1;
  for (int i = 1; i <= 3600; i++) {
    c[i][0] = 1;
    c[i][1] = i;
    for (int j = 2; j <= i; j++) {
      c[i][j] = sum(c[i - 1][j - 1], c[i - 1][j]);
    }
  }
  x[0] = y[0] = true;
  for (int i = 0; i < k; i++) {
    int a, b, a2, b2;
    cin >> a >> b >> a2 >> b2;
    x[a] = x[a2] = true;
    y[b] = y[b2] = true;
  }
  int hx = 0, hy = 0;
  for (int i = 1; i <= n; i++) {
    if (!x[i]) {
      hx++;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!y[i]) {
      hy++;
    }
  }

  dpx[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dpx[i][j] = dpx[i - 1][j];
      if (!x[i] && !x[i - 1]) {
        add(dpx[i][j], dpx[i - 2][j - 1]);
      }
    }
  }

  dpy[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      dpy[i][j] = dpy[i - 1][j];
      if (!y[i] && !y[i - 1]) {
        add(dpy[i][j], dpy[i - 2][j - 1]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int cur = 1;
      cur = mult(cur, dpx[n][j]);
      cur = mult(cur, dpy[m][i]);
      cur = mult(cur, f[i]);
      cur = mult(cur, f[j]);
      cur = mult(cur, C(hx - 2 * j, i));
      cur = mult(cur, C(hy - 2 * i, j));
      add(ans, cur);
    }
  }
  cout << ans << '\n';
}