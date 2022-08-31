/**
 *    author:  tourist
 *    created: 02.05.2021 18:11:25       
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
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  long long x;
  cin >> n >> m >> x;
  vector<long long> a(n);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  debug(total, (n - 1) * x);
  if (total < (n - 1) * x) {
    cout << "NO" << "\n";
    return 0;
  }
  cout << "YES" << '\n';
  dsu d(n);
  vector<vector<pair<int, int>>> g(n);
  int comp = n;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (d.unite(x, y)) {
      g[x].emplace_back(y, i);
      g[y].emplace_back(x, i);
      comp -= 1;
    }
  }
  assert(comp == 1);
  set<pair<long long, int>> s;
  for (int i = 0; i < n; i++) {
    s.emplace(a[i], i);
  }
  d = dsu(n);
  while (s.size() > 1) {
    auto it = prev(s.end());
    if (it->first < x) {
      break;
    }
    int i = it->second;
    assert(d.get(i) == i);
    while (true) {
      assert(!g[i].empty());
      int j = d.get(g[i].back().first);
      if (i == j) {
        g[i].pop_back();
        continue;
      }
      cout << g[i].back().second + 1 << '\n';
      g[i].pop_back();
      s.erase(it);
      s.erase(make_pair(a[j], j));
      if (g[i].size() > g[j].size()) {
        swap(i, j);
      }
      a[j] += a[i] - x;
      s.emplace(a[j], j);
      d.unite(i, j);
      for (auto& p : g[i]) {
        g[j].push_back(p);
      }
      g[i].clear();
      break;
    }
  }
  debug("hi");
  int cc = 0;
  for (int i = 0; i < n; i++) {
    for (auto& p : g[i]) {
      int j = p.first;
      if (d.get(i) != d.get(j)) {
        cout << p.second + 1 << '\n';
        ++cc;
        d.unite(i, j);
      }
    }
  }
  debug(cc);
  return 0;
}