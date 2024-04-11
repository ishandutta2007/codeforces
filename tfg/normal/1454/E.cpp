/**
 *    author:  morato
 *    created: 24.11.2020 12:17:43
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int vis[N], mark[N], anterior[N];
long long subtree[N];

void dfs(int v, int p = -1) {
  vis[v] = 1;
  for (int u : adj[v]) if (u != p) {
    if (!vis[u]) {
      anterior[u] = v;
      dfs(u, v);
    } else if (vis[u] == 1) {
      int x = v;
      while (x != u) {
        mark[x] = 1;
        x = anterior[x];
      }
      mark[x] = 1;
    } 
  }
  vis[v] = 2;
}

void dfs2(int v, int p = -1) {
  subtree[v] = 1;
  for (int u : adj[v]) if (u != p) {
    if (!mark[u]) {
      dfs2(u, v);
      subtree[v] += subtree[u];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      vis[i] = mark[i] = anterior[i] = 0;
      subtree[i] = 0ll;
      adj[i].clear();
    }
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(1);
    vector<int> linha;
    for (int i = 1; i <= n; i++) {
      if (mark[i]) {
        linha.push_back(i);
      }
    }
    long long ans = (long long) n * (n - 1);
    for (int rt : linha) {
      dfs2(rt);
      ans -= subtree[rt] * (subtree[rt] - 1LL) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}