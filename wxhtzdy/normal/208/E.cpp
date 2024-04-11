#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 100050;

vector<int> g[N], ver[N];
int dep[N], lid[N], rid[N], tid;
int par[N][20];

void dfs(int u, int p) {
  lid[u] = ++tid;
  par[u][0] = p;
  ver[dep[u]].push_back(u);
  for (int i = 1; i < 20; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (int v : g[u]) {
    if (v != p) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
  rid[u] = tid;
}

int dizi(int u, int k) {
  for (int i = 19; i >= 0; i--) {
    if (k & (1 << i)) {
      u = par[u][i];
    }
  }
  return u;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] != 0) {
      g[p[i]].push_back(i + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    if (p[i] == 0) {
      dfs(i + 1, 0);
    }
  }
  int qq;
  cin >> qq;
  while (qq--) {
    int v, p;
    cin >> v >> p;
    int u = dizi(v, p);
    if (u == 0) {
      cout << 0 << '\n';
      continue;
    }
    int x = dep[v];
    int bot = 0, top = (int) ver[x].size() - 1, l = 0;
    while (bot <= top) {
      int mid = bot + top >> 1;
      int y = ver[x][mid];
      if (lid[y] < lid[u]) {
        bot = mid + 1;
      } else {
        if (rid[y] <= rid[u]) {
          l = mid;
        }
        top = mid - 1;
      }
    }
    bot = 0, top = (int) ver[x].size() - 1;
    int r = -1;
    while (bot <= top) {
      int mid = bot + top >> 1;
      int y = ver[x][mid];
      if (rid[y] <= rid[u]) {
        bot = mid + 1;
        if (lid[y] >= lid[u]) {
          r = mid;
        }
      } else {
        top = mid - 1;
      }
    }
    cout << r - l << '\n';
  }
}