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

const int INF = 1e9 + 10;

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(n + 1)), d(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    a[u][v] = a[v][u] = 2 * c;
  }
  int LIM = n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        if (a[i][j]) {
          d[i][j] = a[i][j];
        }
        else {
          d[i][j] = INF;
        }
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int best = INF;
  for (int v = 1; v <= n; v++) {
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      mx = max(mx, d[v][i]);
    }
    best = min(best, mx);
    for (int u = 1; u <= n; u++) {
      if (a[u][v]) {
        int lol = 0, iter = 0;
        while (lol <= a[u][v]) {
          iter++;
          if (iter > LIM) {
            break;
          }
          int mx = 0, ind = 0;
          for (int i = 1; i <= n; i++) {
            int vl = min(d[v][i] + lol, d[u][i] + a[u][v] - lol);
            if (vl > mx) {
              mx = vl;
              ind = i;
            }
          }
          best = min(best, mx);
          int l = lol, r = a[u][v] + 1;
          while (r - l > 1) {
            int mid = (l + r) / 2;
            int mx = 0;
            for (int i = 1; i <= n; i++) {
              int vl = min(d[v][i] + mid, d[u][i] + a[u][v] - mid);
              mx = max(mx, vl);
            }
            int f = min(d[v][ind] + mid, d[u][ind] + a[u][v] - mid);
            if (f == mx) {
              l = mid;
            }
            else {
              r = mid;
            }
          }
          mx = 0;
          for (int i = 1; i <= n; i++) {
            int vl = min(d[v][i] + l, d[u][i] + a[u][v] - l);
            if (vl > mx) {
              mx = vl;
              ind = i;
            }
          }
          best = min(best, mx);
          lol = l + 1;
        }
      }
    }
  }
  cout << fixed << setprecision(6) << (ld)best / 2.0 << '\n';
}