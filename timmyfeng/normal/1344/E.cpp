#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int L = __lg(N) + 1;

int in[N], out[N], par[N][L], n, t;
vector<array<int, 2>> adj[N];

void dfs_par(int u) {
  for (int i = 1; i <= __lg(n); ++i) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }

  in[u] = ++t;
  for (auto [c, w] : adj[u]) {
    par[c][0] = u;
    dfs_par(c);
  }
  out[u] = t;
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int child(int u, int v) {
  for (int i = __lg(n); i >= 0; --i) {
    if (!ancestor(par[v][i], u)) {
      v = par[v][i];
    }
  }
  return v;
}

vector<array<long long, 2>> events;
vector<int> trains[N];
long long depth[N];

map<long long, int> dfs_events(int u) {
  set<array<long long, 2>> gaps;
  map<long long, int> sub;

  if (!adj[u].empty()) {
    sub[-depth[u]] = adj[u].back()[0];
  }

  for (auto [c, w] : adj[u]) {
    depth[c] = depth[u] + w;
    map<long long, int> add = dfs_events(c);
    if (add.size() > sub.size()) {
      swap(sub, add);
      gaps.clear();
    }

    for (auto [t, s] : add) {
      auto nxt = sub.lower_bound(t);
      auto prv = nxt;
      if (prv != sub.begin()) {
        --prv;
      }

      if (prv != nxt && nxt != sub.end()) {
        if (child(u, prv->second) != child(u, nxt->second)) {
          gaps.erase({prv->first, nxt->first});
        }
      }

      if (prv != nxt) {
        if (child(u, prv->second) != child(u, s)) {
          gaps.insert({prv->first, t});
        }
      }

      if (nxt != sub.end()) {
        if (child(u, nxt->second) != child(u, s)) {
          gaps.insert({t, nxt->first});
        }
      }

      sub[t] = s;
    }
  }

  for (auto [l, r] : gaps) {
    events.push_back({l + depth[u] + 1, r + depth[u]});
  }

  for (auto i : trains[u]) {
    sub[i] = u;
  }
  sub.erase(-depth[u]);
  return sub;
}

priority_queue<long long, vector<long long>, greater<long long>> que;
vector<long long> done;
long long cur;

void advance(long long nxt) {
  while (cur < nxt && !que.empty()) {
    if (que.top() < cur++) {
      int ans = 0;
      for (auto i : done) {
        ans += (i < que.top());
      }
      cout << que.top() << " " << ans << "\n";
      exit(0);
    }
    done.push_back(que.top());
    que.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m;

  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    trains[s].push_back(t);
  }

  dfs_par(1);
  out[0] = ++t;
  dfs_events(1);

  sort(events.begin(), events.end());
  for (auto [l, r] : events) {
    advance(l);
    que.push(r);
    cur = l;
  }
  advance(LLONG_MAX);

  cout << -1 << " " << done.size() << "\n";
}