/**
 *    author:  tourist
 *    created: 02.02.2020 17:22:03       
**/
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

class dsu {
 public:
  vector<int> p;
  vector<long long> k0;
  vector<long long> k1;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    k0.resize(n);
    k1.resize(n);
    for (int i = 0; i < n / 2; i++) {
      k0[i] = 1;
    }
    for (int i = n / 2; i < n; i++) {
      k1[i] = 1;
    }
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      k0[y] += k0[x];
      k1[y] += k1[x];
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> at(n);
  for (int i = 0; i < k; i++) {
    int foo;
    cin >> foo;
    for (int j = 0; j < foo; j++) {
      int x;
      cin >> x;
      --x;
      at[x].push_back(i);
    }
  }
  dsu d(2 * k);
  const int inf = (int) 1e9;
  long long ans = 0;
  auto P = [&](int x) {
    return x < k ? x + k : x - k;
  };
  auto Unite = [&](int u, int v) {
    u = d.get(u);
    v = d.get(v);
    if (u == v) {
      return;
    }
    ans -= min(d.k1[u], d.k1[P(u)]);
    ans -= min(d.k1[v], d.k1[P(v)]);
    d.unite(u, v);
    d.unite(P(u), P(v));
    ans += min(d.k1[v], d.k1[P(v)]);
  };
  for (int i = 0; i < n; i++) {
    if (at[i].size() == 0) {
      assert(s[i] == '1');
    } else {
      if (at[i].size() == 1) {
        int v = d.get(s[i] == '0' ? at[i][0] : at[i][0] + k);
        ans -= min(d.k1[v], d.k1[P(v)]);
        d.k1[v] = inf;
        ans += min(d.k1[v], d.k1[P(v)]);
      } else {
        int v = at[i][0];
        int u = at[i][1];
        if (s[i] == '1') {
          Unite(u, v);
        } else {
          Unite(u, v + k);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}