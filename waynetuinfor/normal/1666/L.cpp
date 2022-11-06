#include <bits/stdc++.h>
using namespace std;

vector<int> Build(vector<vector<int>> g, int s) {
  int N = g.size();
  vector<vector<int>> rdom(N), r(N);
  vector<int> dfn(N, -1), rev(N, -1), fa(N, -1), sdom(N, -1), dom(N, -1), val(N, -1), rp(N, -1);

  int stamp = 0;
  auto Dfs = [&](auto self, int x) -> void {
    rev[dfn[x] = stamp] = x;
    fa[stamp] = sdom[stamp] = val[stamp] = stamp;
    stamp++;
    for (int u : g[x]) {
      if (dfn[u] == -1) {
        self(self, u);
        rp[dfn[u]] = dfn[x];
      }
      r[dfn[u]].push_back(dfn[x]);
    }
  };

  function<int(int, int)> Find = [&](int x, int c) {
    if (fa[x] == x) {
      return c ? -1 : x;
    }
    int p = Find(fa[x], 1);
    if (p == -1) {
      return c ? fa[x] : val[x];
    }
    if (sdom[val[x]] > sdom[val[fa[x]]]) {
      val[x] = val[fa[x]];
    }
    fa[x] = p;
    return c ? p : val[x];
  };

  auto Merge = [&](int x, int y) {
    fa[x] = y;
  };

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, s;
  cin >> N >> M >> s;
  s--;

  vector<vector<int>> g(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }

  vector<int> vis(N, -1);
  vector<int> from(N, -1);

  vis[s] = -2;
  for (int i = 0; i < g[s].size(); ++i) {
    auto Dfs = [&](auto dfs, int x, int p) -> void {
      vis[x] = i;
      from[x] = p;
      for (int u : g[x]) {
        if (u == s) {
          continue;
        }
        if (vis[u] == -1) {
          dfs(dfs, u, x);
        }
      }
    };
    if (vis[g[s][i]] == -1) {
      Dfs(Dfs, g[s][i], s);
    }
  }
  for (int i = 0; i < N; ++i) {
    if (i != s && vis[i] != -1) {
      for (int u : g[i]) {
        if (u != s && vis[u] != vis[i]) {
          cout << "Possible\n";
          int x = i, y = u;
          vector<int> a = {y}, b;
          while (x != s) {
            a.push_back(x);
            x = from[x];
          }
          a.push_back(s);
          while (y != s) {
            b.push_back(y);
            y = from[y];
          }
          b.push_back(s);
          reverse(a.begin(), a.end());
          reverse(b.begin(), b.end());
          cout << a.size() << "\n";
          for (int u : a) cout << u + 1 << " ";
          cout << "\n";
          cout << b.size() << "\n";
          for (int u : b) cout << u + 1 << " ";
          cout << "\n";
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < g[s].size(); ++i) {
    int u = g[s][i];
    if (vis[u] != i) {
        cout << "Possible\n";
        int x = i, y = u;
        vector<int> a = {u, s}, b;
        while (y != s) {
          b.push_back(y);
          y = from[y];
        }
        b.push_back(s);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout << a.size() << "\n";
        for (int u : a) cout << u + 1 << " ";
        cout << "\n";
        cout << b.size() << "\n";
        for (int u : b) cout << u + 1 << " ";
        cout << "\n";
        return 0;
    }
  }
  cout << "Impossible\n";
  return 0;
}