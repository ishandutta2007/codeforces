#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct edge {
  int w, x, y;
  bool operator <  (edge& other) const {
    return w < other.w;
  }
} e[100050];

int cale[100050];

int nadji(int u) {
  if (cale[u] == u) return u;
  return cale[u] = nadji(cale[u]);
}

void spoji(int u, int v) {
  u = nadji(u), v = nadji(v);
  if (u != v) {
    cale[u] = v;
    return;
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> sz(n, 0);
  iota(cale, cale + n, 0);
  for (int i = 0; i < k; i++) {
    int p;
    cin >> p;
    --p;
    sz[p] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].w;
    --e[i].x, --e[i].y;
  }
  sort(e, e + m);
  for (int i = 0; i < m; i++) {
    int px = nadji(e[i].x);
    int py = nadji(e[i].y);
    if (px != py) {
      spoji(px, py);
      sz[py] += sz[px];
      if (sz[py] == k) {
        for (int j = 0; j < k; j++) {
          cout << e[i].w << " ";
        }
        break;
      }
    }
  }
}