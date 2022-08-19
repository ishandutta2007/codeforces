/**
 *    author:  tourist
 *    created: 25.08.2019 18:50:27       
**/
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 100010;

int from_leaves[N];
int from_others[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> color(n);
  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }
  vector<int> order;
  vector<int> pos(n, -1);
  vector<int> endd(n, -1);
  vector<bool> is_leaf(n, false);
  vector<int> map_to(n);
  vector<int> deg(n);
  vector<int> parent(n, -1);
  iota(map_to.begin(), map_to.end(), 0);
  function<void(int, int)> Dfs = [&](int v, int pv) {
    parent[v] = pv;
    deg[v] = (int) g[v].size() - (pv != -1);
    if (pv != -1 && deg[v] == 1 && deg[pv] == 1) {
      map_to[v] = map_to[pv];
      for (int u : g[v]) {
        if (u == pv) {
          continue;
        }
        Dfs(u, v);
      }
      return;
    }
    pos[v] = (int) order.size();
    order.push_back(v);
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      Dfs(u, v);
    }
    endd[v] = (int) order.size() - 1;
    if (deg[v] == 0) {
      is_leaf[v] = true;
      order.pop_back();
      pos[v] = endd[v] = -1;
    }
  };
  Dfs(0, -1);
  int cnt = (int) order.size();
  memset(from_leaves, 0, sizeof(int) * cnt);
  memset(from_others, 0, sizeof(int) * cnt);
  for (int i = 0; i < n; i++) {
    if (is_leaf[i]) {
      from_leaves[pos[map_to[parent[i]]]] += (color[i] == 1 ? 1 : -1);
    }
  }
  vector<int> go_to(cnt);
  for (int i = 1; i < cnt; i++) {
    go_to[i] = pos[map_to[parent[order[i]]]];
  }
  int tt;
  cin >> tt;
  vector<int> op(tt), ver(tt), val(tt), res(tt, -1);
  for (int i = 0; i < tt; i++) {
    cin >> op[i];
    if (op[i] == 1) {
      cin >> ver[i];
      --ver[i];
    }
    if (op[i] == 2) {
      cin >> ver[i] >> val[i];
      --ver[i];
    }
    if (op[i] == 3) {
      cin >> val[i];
    }
  }
  map<int, int> mp;
  int beg = 0;
  while (beg < tt) {
    int end = beg;
    while (end + 1 < tt && op[end + 1] == op[end]) {
      ++end;
    }
    if (op[beg] == 1) {
      mp.clear();
      for (int i = beg; i <= end; i++) {
        int v = ver[i];
        if (!is_leaf[v]) {
          v = map_to[v];
          from_others[pos[v]] = 0;
          mp[pos[v] + 1] += 1;
          mp[endd[v] + 1] -= 1;
        }
      }
      vector<pair<int, int>> segs;
      int balance = 0;
      int start = -1;
      for (auto& p : mp) {
        if (p.second == 0) {
          continue;
        }
        if (balance == 0) {
          start = p.first;
        }
        balance += p.second;
        if (balance == 0) {
          segs.emplace_back(start, p.first - 1);
          start = -1;
        }
      }
      for (auto& p : segs) {
        int from = p.first;
        int to = p.second;
        memset(from_others + from, 0, sizeof(int) * (to - from + 1));
        for (int i = to; i >= from; i--) {
          from_others[go_to[i]] += (from_others[i] + from_leaves[i] >= k ? 1 : -1);
        }
      }
      for (int i = beg; i <= end; i++) {
        int v = ver[i];
        if (is_leaf[v]) {
          res[i] = color[v];
        } else {
          v = map_to[v];
          res[i] = (from_others[pos[v]] + from_leaves[pos[v]] >= k);
        }
      }
    }
    if (op[beg] == 2) {
      for (int i = beg; i <= end; i++) {
        int v = ver[i];
        from_leaves[pos[map_to[parent[v]]]] -= (color[v] == 1 ? 1 : -1);
        color[v] = val[i];
        from_leaves[pos[map_to[parent[v]]]] += (color[v] == 1 ? 1 : -1);
      }
    }
    if (op[beg] == 3) {
      k = val[end];
    }
    beg = end + 1;
  }
  for (int i = 0; i < tt; i++) {
    if (op[i] == 1) {
      cout << res[i] << '\n';
    }
  }
  return 0;
}