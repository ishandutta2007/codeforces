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

const int N = 2e5 + 10;
const int L = 18;
vector<int> g[N];
int up[N][L], h[N], tin[N], tout[N], sz[N], timer;

int dfs(int v, int par = 0, int ch = 0) {
  h[v] = ch;
  up[v][0] = par;
  for (int i = 1; i < L; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  tin[v] = ++timer;
  sz[v] = 1;
  for (auto u : g[v]) {
    if (u != par) {
      sz[v] += dfs(u, v, ch + 1);
    }
  }
  tout[v] = ++timer;
  return sz[v];
}

bool anc(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (anc(a, b)) {
    return a;
  }
  for (int i = L - 1; i >= 0; i--) {
    if (!anc(up[a][i], b)) {
      a = up[a][i];
    }
  }
  return up[a][0];
}

int dist(int u, int v) {
  return h[u] + h[v] - 2 * h[lca(u, v)];
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      g[i] = {};
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(0);
    auto get_size = [&n](int v, int banned_neighbour) {
      if (up[v][0] == banned_neighbour) {
        return sz[v];
      }
      return n - sz[banned_neighbour];
    };

    auto recalc = [&get_size](int v, int banned_vertex) {
      int result = 1;
      for (auto u : g[v]) {
        if (dist(v, u) + dist(u, banned_vertex) > dist(v, banned_vertex)) {
          result += get_size(u, v);
        } 
      }
      return result;
    }; 

    vector<int> mex_at_least_k(n + 1, 0);
    mex_at_least_k[1] = mex_at_least_k[0] = n * (n - 1) / 2;
    for (auto u : g[0]) {
      int subtree_size = get_size(u, 0);
      mex_at_least_k[1] -= subtree_size * (subtree_size - 1) / 2;
    }
    pair<int, int> current = {0, 1};
    pair<int, int> sizes = {recalc(0, 1), recalc(1, 0)};
    mex_at_least_k[2] = sizes.first * sizes.second;
    int cdist = dist(0, 1);
    for (int i = 2; i < n; i++) {
      int dlc = dist(current.first, i), 
      drc = dist(current.second, i);
      debug(dlc, drc, cdist);
      if (cdist == dlc + drc) {
        mex_at_least_k[i + 1] = mex_at_least_k[i];
      } else if (dlc + cdist == drc) {
        cdist = drc;
        current.first = i;
        sizes.first = recalc(current.first, current.second);
        mex_at_least_k[i + 1] = sizes.first * sizes.second;
      } else if (drc + cdist == dlc) {
        cdist = dlc;
        current.second = i;
        sizes.second = recalc(current.second, current.first);
        mex_at_least_k[i + 1] = sizes.first * sizes.second;
      } else {
        break;
      }
      debug(i, sizes);
    }
    debug(mex_at_least_k);
    vector<int> answer(n + 1);
    answer[n] = mex_at_least_k[n];
    for (int i = n - 1; i >= 0; i--) {
      answer[i] = mex_at_least_k[i] - mex_at_least_k[i + 1];
    }
    for (int i = 0; i <= n; i++) {
      cout << answer[i] << ' ';
    }
    cout << '\n'; 
  }
}