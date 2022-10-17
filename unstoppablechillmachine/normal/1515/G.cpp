#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

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
 
#ifdef PC
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n), rg(n);
  for (int i = 0; i < m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    u--, v--;
    g[u].pb({v, l});
    rg[v].pb({u, l});
  }
  vector<int> used(n), len(n), order;
  vector<pair<int, int>> cycles;
  function<void(int)> dfs1 = [&](int v) {
    used[v] = 1;
    for (auto u : g[v]) {
      if (!used[u.first]) {
        len[u.first] = len[v] + u.second;
        dfs1(u.first);
      }
    }
    order.pb(v);
    used[v] = 2;
  };
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs1(i);
    }
  }
  reverse(all(order));
  vector<int> color(n);
  function<void(int, int)> dfs2 = [&](int v, int cl) {
    color[v] = cl;
    for (auto u : rg[v]) {
      if (!color[u.first]) {
        dfs2(u.first, cl);
      }
    }
  };

  int comps = 0;
  for (int v : order) {
    if (!color[v]) {
      dfs2(v, ++comps);
    }
  }
  
  vector<int> can(comps + 1, 0);
  for (int i = 0; i < n; i++) {
    for (auto it : g[i]) {
      if (color[i] == color[it.first]) {
        can[color[i]] = __gcd(can[color[i]], abs(it.second + len[i] - len[it.first]));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    debug(color[i], can[color[i]]);
  }

  int q;
  cin >> q;
  while (q--) {
    int v, vl, mod;
    cin >> v >> vl >> mod;
    v--;
    if (vl == 0) {
      cout << "YES\n";
      continue;
    }
    if (can[color[v]] == 0 || (mod - vl) % __gcd(mod, can[color[v]]) != 0) {
      cout << "NO\n";
    }      
    else {
      cout << "YES\n";
    }
  }
}