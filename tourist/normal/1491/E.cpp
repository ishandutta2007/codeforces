/**
 *    author:  tourist
 *    created: 28.02.2021 17:54:19       
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> fib = {1, 1};
  while (fib.back() < n) {
    int x = fib.back();
    int y = fib[fib.size() - 2];
    fib.push_back(x + y);
  }
  if (fib.back() != n) {
    cout << "NO" << '\n';
    return 0;
  }
  vector<int> me(n, -1);
  int T = 0;
  vector<int> sz(n);
  vector<int> pv(n, -1);
  vector<int> all;
  function<void(int, int)> Dfs = [&](int v, int pr) {
    all.push_back(v);
    pv[v] = pr;
    sz[v] = 1;
    for (int u : g[v]) {
      if (me[u] == T && u != pr) {
        Dfs(u, v);
        sz[v] += sz[u];
      }
    }
  };
  function<bool(vector<int>, int pt)> Solve = [&](vector<int> a, int pt) {
    debug(a, fib[pt]);
    assert((int) a.size() == fib[pt]);
    if (fib[pt] == 1) {
      return true;
    }
    ++T;
    for (int x : a) {
      me[x] = T;
    }
    all.clear();
    Dfs(a[0], -1);
    assert(sz[a[0]] == fib[pt]);
    for (int x : a) {
      if (sz[x] == fib[pt - 1] || sz[x] == fib[pt - 2]) {
        int got = sz[x];
        all.clear();
        Dfs(x, pv[x]);
        assert(sz[x] == got);
        int new_pt = (sz[x] == fib[pt - 1] ? pt - 1 : pt - 2);
        auto go = all;
        bool ret = Solve(all, new_pt);
        if (!ret) {
          return false;
        }
        ++T;
        for (int y : go) {
          me[y] = T;
        }
        all.clear();
        for (int y : a) {
          if (me[y] != T) {
            all.push_back(y);
          }
        }
        new_pt = (new_pt ^ (pt - 1) ^ (pt - 2));
        ret &= Solve(all, new_pt);
        return ret;
      }
    }
    return false;
  };
  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  bool res = Solve(a, (int) fib.size() - 1);
  cout << (res ? "YES" : "NO") << '\n';
  return 0;
}