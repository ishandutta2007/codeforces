#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;
struct Flow {
  struct edge {
    int to, c, w, f;
  };
  vector<edge> arr;
  vector<vector<int>> g;
  vector<int> pnt;
  vector<ll> potential;
  vector<bool> used;
  int n, m, s, t, cnt = 0;
  Flow(int maxn, int maxm, int _s, int _t) {
    n = maxn;
    m = maxm;
    s = _s;
    t = _t;
    arr.resize(m + 1);
    g.resize(n + 1);
    pnt.resize(n + 1);
    potential.resize(n + 1);
    used.resize(n + 1);
  }
  inline void add_edge(int from, int to, int c, int w = 0, int f = 0) {
    arr[cnt] = {to, c, w, f};
    g[from].pb(cnt++);
  }
  int Ford_Fulkerson_dfs(int v, int min_f, int need = 1) {
    if (v == t) {
      return min_f;
    }
    used[v] = true;
    for (int u : g[v]) {
      if (!used[arr[u].to] && arr[u].c - arr[u].f >= need) {
        int val = Ford_Fulkerson_dfs(arr[u].to, min(min_f, arr[u].c - arr[u].f), need);
        if (val >= need) {
          arr[u].f += val;
          arr[u ^ 1].f -= val;
          return val;
        }
      }
    }
    return 0;
  }
  inline int Ford_Fulkerson() { //O(|F| * E)
    int res = 0;
    for (;;) {
      fill(all(used), false);
      int val = Ford_Fulkerson_dfs(s, INF);
      if (!val) {
        return res;
      }
      res += val;
    }
  }
  inline int Ford_Fulkerson_with_scaling(int mx = INF) { //O(E^2 * log(U)), where U is the maximum capacity
    int res = 0, up = (int)log2(mx);
    for (int k = up; k >= 0; k--) {
      for (;;) {
        fill(all(used), false);
        int val = Ford_Fulkerson_dfs(s, INF, 1 << k);
        if (!val) {
          break;
        }
        res += val;
      }
    }
    return res;
  }
  inline int Edmonds_Karp_bfs(int need = 1) {
    vector<pair<int, int>> from(n + 1);
    fill(all(used), false);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : g[v]) {
        if (arr[u].c - arr[u].f >= need && !used[arr[u].to]) {
          used[arr[u].to] = true;
          q.push(arr[u].to);
          from[arr[u].to] = {v, u};
        }
      }
    }
    if (!used[t]) {
      return 0;
    }
    int now = t, min_f = INF;
    while (now != s) {
      min_f = min(min_f, arr[from[now].second].c - arr[from[now].second].f);
      now = from[now].first;
    }
    now = t;
    while (now != s) {
      int ind = from[now].second;
      arr[ind].f += min_f;
      arr[ind ^ 1].f -= min_f;
      now = from[now].first;
    }
    return min_f;
  }
  int Edmonds_Karp() { //O(VE^2)
    int res = 0;
    for (;;) {
      int val = Edmonds_Karp_bfs();
      if (!val) {
        return res;
      }
      res += val;
    }
  }
  int Edmonds_Karp_with_scaling(int mx = INF) { // O(E^2 * log(U)), where U is the maximum capacity
    int res = 0, up = (int)log2(mx);
    for (int k = up; k >= 0; k--) {
      for (;;) {
        int val = Edmonds_Karp_bfs(1 << k);
        if (!val) {
          break;
        }
        res += val;
      }
    }
    return res;
  }
  int Dinic_dfs(int v, int min_f, int need = 1) {
    if (v == t) {
      return min_f;
    }
    used[v] = true;
    for (; pnt[v] < SZ(g[v]); pnt[v]++) {
      int u = g[v][pnt[v]];
      if (!used[arr[u].to] && arr[u].c - arr[u].f >= need) {
        int val = Dinic_dfs(arr[u].to, min(min_f, arr[u].c - arr[u].f), need);
        if (val >= need) {
          arr[u].f += val;
          arr[u ^ 1].f -= val;
          return val;
        }
      }
    }
    return 0;
  }
  inline int Dinic_bfs(int need = 1) {
    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : g[v]) {
        if (arr[u].c - arr[u].f >= need && dist[arr[u].to] == INF) {
          dist[arr[u].to] = dist[v] + 1;
          q.push(arr[u].to);
        }
      }
    }
    if (dist[t] == INF) {
      return 0;
    }
    fill(all(pnt), 0);
    int res = 0;
    for (;;) {
      fill(all(used), false);
      int val = Dinic_dfs(s, INF, need);
      if (!val) {
        return res;
      }
      res += val;
    }
  }
  int Dinic() { // O(V^2 * E), on single networks O(E * sqrt(E))
    int res = 0;
    for (;;) {
      int val = Dinic_bfs();
      if (!val) {
        return res;
      }
      res += val;
    }
  }
  int Dinic_with_scaling(int mx = INF) { // O(VE * log(U)), where U is the maximum capacity
    int res = 0, up = (int)log2(mx);
    for (int k = up; k >= 0; k--) {
      for (;;) {
        int val = Dinic_bfs(1 << k);
        if (!val) {
          break;
        }
        res += val;
      }
    }
    return res;
  }
  inline ll Ford_Bellman() {
    vector<ll> dist(n + 1, INF);
    vector<pair<int, int>> from(n + 1);
    vector<bool> already(n + 1, false);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      already[v] = false;
      for (auto it : g[v]) {
        if (dist[v] + arr[it].w < dist[arr[it].to] && arr[it].c > arr[it].f) {
          dist[arr[it].to] = dist[v] + arr[it].w;
          from[arr[it].to] = {v, it};
          if (!already[arr[it].to]) {
            q.push(arr[it].to);
            already[arr[it].to] = true;
          }
        }
      }
    }
    int now = t, mn = INF;
    while (from[now].first) {
      mn = min(mn, arr[from[now].second].c - arr[from[now].second].f);
      now = from[now].first;
    }
    now = t;
    while (from[now].first) {
      arr[from[now].second].f += mn;
      arr[from[now].second ^ 1].f -= mn;
      now = from[now].first;
    }
    return dist[t] * mn;
  }
  void init_potentials() {
    vector<ll> dist(n + 1, INF);
    vector<bool> already(n + 1, false);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      already[v] = false;
      for (auto it : g[v]) {
        if (dist[v] + arr[it].w < dist[arr[it].to] && arr[it].c > arr[it].f) {
          dist[arr[it].to] = dist[v] + arr[it].w;
          if (!already[arr[it].to]) {
            q.push(arr[it].to);
            already[arr[it].to] = true;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (dist[i] != INF) {
        potential[i] = dist[i];
      }
    }
  }
  inline ll Dijkstra_with_potentials1() {
    vector<ll> dist(n + 1, INF);
    vector<pair<int, int>> from(n + 1);
    dist[s] = 0;
    set<pair<ll, int>> st;
    for (int i = 1; i <= n; i++) {
      st.insert({dist[i], i});
    }
    while (!st.empty()) {
      int v = st.begin()->second;
      st.erase(st.begin());
      for (auto it : g[v]) {
        int u = arr[it].to;
        ll cost = arr[it].w + potential[v] - potential[u];
        if (arr[it].f < arr[it].c && dist[v] + cost < dist[u]) {
          st.erase({dist[u], u});
          dist[u] = dist[v] + cost;
          st.insert({dist[u], u});
          from[u] = {v, it};
        }
      }
    }
    int now = t, mn = INF;
    while (from[now].first) {
      mn = min(mn, arr[from[now].second].c - arr[from[now].second].f);
      now = from[now].first;
    }
    now = t;
    while (from[now].first) {
      arr[from[now].second].f += mn;
      arr[from[now].second ^ 1].f -= mn;
      now = from[now].first;
    }
    ll res = (dist[t] - potential[s] + potential[t]) * mn;
    for (int i = 1; i <= n; i++) {
      if (dist[i] < INF) {
        potential[i] += dist[i];
      }
    }
    return res;
  }
  inline ll Dijkstra_with_potentials2() {
    vector<ll> dist(n + 1, INF);
    vector<pair<int, int>> from(n + 1);
    fill(all(used), false);
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
      pair<int, int> best = {INF, INF};
      for (int j = 1; j <= n; j++) {
        if (!used[j]) {
          best = min(best, {dist[j], j});
        }
      }
      int v = best.second;
      used[v] = true;
      for (auto it : g[v]) {
        int u = arr[it].to;
        ll cost = arr[it].w + potential[v] - potential[u];
        if (arr[it].f < arr[it].c && dist[v] + cost < dist[u]) {
          dist[u] = dist[v] + cost;
          from[u] = {v, it};
        }
      }
    }
    int now = t, mn = INF;
    while (from[now].first) {
      mn = min(mn, arr[from[now].second].c - arr[from[now].second].f);
      now = from[now].first;
    }
    now = t;
    while (from[now].first) {
      arr[from[now].second].f += mn;
      arr[from[now].second ^ 1].f -= mn;
      now = from[now].first;
    }
    ll res = (dist[t] - potential[s] + potential[t]) * mn;
    for (int i = 1; i <= n; i++) {
      if (dist[i] < INF) {
        potential[i] += dist[i];
      }
    }
    return res;
  }
  ll mincost_with_FB(int flow_sz = INF) { // O(|F| * VE)
    ll res = 0;
    for (int i = 0; i < flow_sz; i++) {
      ll val = Ford_Bellman();
      if (val >= BINF) {
        return res;
      }
      res += val;
    }
    return res;
  }
  ll mincost_with_Dijkstra1(int flow_sz = INF) {// O(|F| * E log V)
    init_potentials();
    ll res = 0;
    for (int i = 0; i < flow_sz; i++) {
      ll val = Dijkstra_with_potentials1();
      if (val >= BINF) {
        return res;
      }
      res += val;
    }
    return res;
  }
  ll mincost_with_Dijkstra2(int flow_sz = INF) { // O(|F| * V^2)
    init_potentials();
    ll res = 0;
    for (int i = 0; i < flow_sz; i++) {
      ll val = Dijkstra_with_potentials2();
      if (val >= BINF) {
        return res;
      }
      res += val;
    }
    return res;
  }
};
 
const int N = 110;
const int M = 1e5 + 10;
int have[M];
vector<int> g[N];
bool used[N], c[N];
int arr[N];
pair<int, int> par[N];
map<int, int> f[N];
 
void dfs(int v, bool color) {
  used[v] = true;
  c[v] = color;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u, color ^ 1);
    }
  }
}

#define F first
#define S second
 
void source() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> par[i].F >> par[i].S;
    g[par[i].F].pb(par[i].S);
    g[par[i].S].pb(par[i].F);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i, 0);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int cur = arr[i];
    for (int j = 2; j * j <= cur; j++) {
      if (cur % j == 0) {
        int kek = 0;
        while (cur % j == 0) {
          cur /= j;
          kek++;
        }
        f[i][j] = ++cnt;
        have[cnt] = kek;
      }
    }
    if (cur > 1) {
      f[i][cur] = ++cnt;
      have[cnt] = 1;
    }
  }
  int cs = cnt + 1, ct = cnt + 2;
  Flow F(cnt + 2, 1e5, cs, ct);
  for (int i = 1; i <= n; i++) {
    if (c[i]) {
      for (auto it : f[i]) {
        F.add_edge(cs, it.S, have[it.S]);
        F.add_edge(it.S, cs, 0);
      }
    }
    else {
      for (auto it : f[i]) {
        F.add_edge(it.S, ct, have[it.S]);
        F.add_edge(ct, it.S, 0);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!c[par[i].F]) {
      swap(par[i].F, par[i].S);
    }
    int x = __gcd(arr[par[i].F], arr[par[i].S]);
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        while (x % j == 0) {
          x /= j;
        }
        F.add_edge(f[par[i].F][j], f[par[i].S][j], INF);
        F.add_edge(f[par[i].S][j], f[par[i].F][j], 0);
      }
    }
    if (x > 1) {
      F.add_edge(f[par[i].F][x], f[par[i].S][x], INF);
      F.add_edge(f[par[i].S][x], f[par[i].F][x], 0);
    }
  }
  cout << F.Dinic() << '\n';
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}