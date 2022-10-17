#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
 
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

const int N = 5e5 + 10;
vector<int> g[N];

mt19937 rnd(time(0));

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      g[i] = {};
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    set<pair<int, int>> st;
    vector<int> neig(n + 1);
    for (int i = 1; i <= n; i++) {
      sort(all(g[i]));
      neig[i] = n - SZ(g[i]) - 1;
      st.insert({neig[i], i});
    }    
    vector<bool> alive(n + 1, true);
    int ptr = 1, cnt_alive = n;
    auto del = [&](int v) {
      if (!alive[v]) {
        return;
      }
      cnt_alive--;
      alive[v] = false;
      st.erase({neig[v], v});
      for (auto u : g[v]) {
        if (alive[u]) {
          st.erase({neig[u], u});
          neig[u]++;
          st.insert({neig[u], u});
        }
      }
    };
    vector<int> a(n + 1), b(n + 1);
    while (!st.empty() && st.begin()->F == (n - cnt_alive)) {
      int v = st.begin()->S;
      a[v] = b[v] = ptr++;
      del(v);
    }
    auto have_edge = [&](int u, int v) {
      int pos = lower_bound(all(g[u]), v) - g[u].begin();
      return (pos < SZ(g[u]) && g[u][pos] == v);
    };
    while (!st.empty()) {
      assert(st.begin()->F > (n - cnt_alive));
      int v = 0;
      vector<int> kek;
      if (st.begin()->F - (n - cnt_alive) == 1) {
        for (auto it : st) {
          if (it.S != st.begin()->S && !have_edge(it.S, st.begin()->S)) {
            v = it.S;
            break;
          }
        }
        assert(v);
        auto it = st.begin();
        while (it != st.end() && it->F == (n - cnt_alive) + 1) {
          if (v != it->S && !have_edge(v, it->S)) {
            kek.pb(it->S);
          }
          it++;
        }
      }
      else {
        v = st.rbegin()->S;
        int u = 0;
        for (auto it : st) {
          if (it.S != v && !have_edge(it.S, v)) {
            u = it.S;
            break;
          }
        }
        assert(u);
        del(v);
        del(u);
        kek.pb(u);
        while (!st.empty() && st.begin()->F == n - cnt_alive) {
          kek.pb(st.begin()->S);
          del(st.begin()->S);
        }
      }
      assert(!kek.empty());
      a[v] = ptr;
      for (int i = 0; i < SZ(kek); i++) {
        a[kek[i]] = ptr + i + 1;
      }
      b[v] = ptr + SZ(kek);
      for (int i = 0; i < SZ(kek); i++) {
        b[kek[i]] = ptr + i;
      }
      ptr += SZ(kek) + 1;
      del(v);
      for (auto it : kek) {
        del(it);
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
}