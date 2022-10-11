#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

const int mv = 3e5 + 20, me = 2 * mv;

int adj[mv], to[me], ant[me], id[me], z;
int vis[mv];

inline void add(int a, int b, int i) {
  to[z] = b, ant[z] = adj[a], id[z] = i, adj[a] = z++;
  if (i > -1) {
    swap(a, b);
  }
  to[z] = b, ant[z] = adj[a], id[z] = i, adj[a] = z++;    
}

char ans2[mv], ans1[mv];

void dfs1(int u) {
  vis[u] = 1;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    if (vis[to[i]] == 1) {
      continue;
    }
    if (id[i] > -1) {
      int dir = i & 1;
      ans1[id[i]] = dir ? '+' : '-';
    } else {
      dfs1(to[i]);
    }
  }
}

void dfs2(int u) {
  vis[u] = 2;
  for (int i = adj[u]; i > -1; i = ant[i]) {
    if (vis[to[i]] == 2) {
      continue;
    }
    if (id[i] > -1) {
      int dir = i & 1;
      ans2[id[i]] = dir ? '-' : '+';
      dfs2(to[i]);
    } else {
      dfs2(to[i]);
    }
  }
}


int main() {
  int n, m, s;
  cin >> n >> m >> s;
  memset(adj, -1, sizeof adj);
  --s;
  int cnt = 0;
  fr(i, 0, m) {
    int t, u, v;
    cin >> t >> u >> v;
    --u, --v;
    if (t == 1) {
      add(u, v, -1);
    } else {
      add(u, v, cnt++);
    }
  }
  int cnt1 = 0, cnt2 = 0;
  dfs1(s);
  fr(i, 0, n) cnt1 += vis[i] == 1;
  dfs2(s);
  fr(i, 0, n) cnt2 += vis[i] == 2;
  fr(i, 0, cnt) {
    if (ans1[i] == 0)
      ans1[i] = '+';
    if (ans2[i] == 0)
      ans2[i] = '+';
  }
  cout << cnt2 << '\n' << ans2 << '\n' << cnt1 << '\n' << ans1 << '\n';
}