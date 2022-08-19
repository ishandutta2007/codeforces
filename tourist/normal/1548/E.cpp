/**
 *    author:  tourist
 *    created: 01.08.2021 19:21:22       
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

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = min(a[i], x);
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i] = min(b[i], x);
  }
  long long V = 0;
  long long E = 0;
  long long F = 0;
  { // V
    auto sa = a;
    sort(sa.begin(), sa.end());
    auto sb = b;
    sort(sb.begin(), sb.end());
    int j = m;
    for (int i = 0; i < n; i++) {
      while (j > 0 && sb[j - 1] + sa[i] > x) {
        --j;
      }
      V += j;
    }
  }
  { // E
    { // ver
      vector<int> sa(n - 1);
      for (int i = 0; i < n - 1; i++) {
        sa[i] = max(a[i], a[i + 1]);
      }
      sort(sa.begin(), sa.end());
      auto sb = b;
      sort(sb.begin(), sb.end());
      int j = m;
      for (int i = 0; i < n - 1; i++) {
        while (j > 0 && sb[j - 1] + sa[i] > x) {
          --j;
        }
        E += j;
      }
    }
    { // hor
      auto sa = a;
      sort(sa.begin(), sa.end());
      vector<int> sb(m - 1);
      for (int i = 0; i < m - 1; i++) {
        sb[i] = max(b[i], b[i + 1]);
      }
      sort(sb.begin(), sb.end());
      int j = m - 1;
      for (int i = 0; i < n; i++) {
        while (j > 0 && sb[j - 1] + sa[i] > x) {
          --j;
        }
        E += j;
      }
    }
  }
  { // F
    auto Make = [&](const vector<int>& v) {
      int sz = (int) v.size();
      vector<int> pr(sz), ne(sz);
      for (int i = 0; i < sz; i++) {
        pr[i] = i - 1;
        ne[i] = i + 1;
      }
      vector<int> order(sz);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int i, int j) {
        return v[i] > v[j];
      });
      SparseTable<int> st(v, [&](int i, int j) { return max(i, j); });
      vector<tuple<int, int, int>> ret;
      for (int i = 0; i < sz - 1; i++) {
        ret.emplace_back(max(v[i], v[i + 1]), x, max(v[i], v[i + 1]));
      }
      for (int i : order) {
        if (pr[i] >= 0 && ne[i] < sz) {
          int v0 = max(v[pr[i]], v[ne[i]]);
          int v1 = v[i];
          int v2 = st.get(pr[i], ne[i]);
          if (v0 < v1) {
            ret.emplace_back(v0, v1, v2);
          }
        }
        if (pr[i] != -1) {
          ne[pr[i]] = ne[i];
        }
        if (ne[i] != sz) {
          pr[ne[i]] = pr[i];
        }
      }
      return ret;
    };
    vector<tuple<int, int, int>> r = Make(a);
    vector<tuple<int, int, int>> c = Make(b);
    debug(r);
    debug(c);
    vector<vector<pair<int, int>>> qs(x + 1);
    for (auto& q : c) {
      qs[x - get<2>(q)].emplace_back(x - get<1>(q) + 1, x - get<0>(q));
    }
    vector<vector<int>> ev(x + 1);
    for (auto& p : r) {
      ev[get<0>(p)].push_back(get<2>(p));
      ev[get<1>(p)].push_back(~get<2>(p));
    }
    fenwick<int> fenw(x + 1);
    for (int i = 1; i <= x; i++) {
      for (int e : ev[i]) {
        if (e >= 0) {
          fenw.modify(e, +1);
        } else {
          fenw.modify(~e, -1);
        }
      }
      for (auto& q : qs[i]) {
        F += fenw.get(q.second) - fenw.get(q.first - 1);
      }
    }
  }
  cout << V - E + F << '\n';
  return 0;
}