/**
 *    author:  tourist
 *    created: 04.06.2020 18:55:22       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

using namespace __gnu_pbds;

typedef int tp;
typedef tree<tp,null_type,less<tp>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// tp a;
// T.insert(a), T.erase(a), T.size()
// T.order_of_key(a) -- number of elements strictly less than a
// *T.find_by_order(k) -- k-th element in increasing order

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

struct Node {
  int parent;
  int from;
  int to;
  int k;
  long long inv;
  long long pairs;
  pbds L;
  pbds R;
};

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<int> w(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> w[i];
    --w[i];
  }
  vector<int> ids(n - 1);
  iota(ids.begin(), ids.end(), 0);
  SparseTable<int> st(ids, [&](int i, int j) { return (w[i] < w[j] ? i : j); });
  vector<Node> nodes(n - 1);
  {
    Node& node = nodes[0];
    node.parent = -1;
    node.from = 0;
    node.to = n - 1;
    node.k = -1;
    node.inv = 0;
    node.pairs = 0;
  }
  vector<int> leaf(n);
  long long ans = 0;
  long long total = 0;
  int ptr = 1;
  for (int b = 0; b < n - 1; b++) {
    Node& node = nodes[b];
//    debug(b, node.from, node.to);
    assert(node.from < node.to);
    node.k = st.get(node.from, node.to - 1);
    for (int i = node.k + 1; i <= node.to; i++) {
      node.R.insert(p[i]);
    }
    for (int i = node.from; i <= node.k; i++) {
      node.inv += node.R.order_of_key(p[i]);
      node.L.insert(p[i]);
    }
    total += (int) node.L.size();
    total += (int) node.R.size();
    node.pairs = (long long) (node.to - node.k) * (node.k - node.from + 1);
//    debug(node.from, node.to, node.k, node.inv, node.pairs);
    ans += min(node.inv, node.pairs - node.inv);
    if (node.from == node.k) {
      leaf[node.from] = b;
    } else {
      Node& new_node = nodes[ptr];
      ptr += 1;
      new_node.parent = b;
      new_node.from = node.from;
      new_node.to = node.k;
      new_node.k = -1;
      new_node.inv = 0;
      new_node.pairs = 0;
    }
    if (node.k + 1 == node.to) {
      leaf[node.to] = b;
    } else {
      Node& new_node = nodes[ptr];
      ptr += 1;
      new_node.parent = b;
      new_node.from = node.k + 1;
      new_node.to = node.to;
      new_node.k = -1;
      new_node.inv = 0;
      new_node.pairs = 0;
    }
  }
//  debug("done");
  debug(ans, clock(), nodes.size(), total);
//  debug(leaf);
  auto Modify = [&](int i, int val) {
    int b = leaf[i];
    while (b >= 0) {
      Node& node = nodes[b];
      ans -= min(node.inv, node.pairs - node.inv);
      if (i <= node.k) {
        node.inv -= node.R.order_of_key(p[i]);
        node.inv += node.R.order_of_key(val);
        node.L.erase(p[i]);
        node.L.insert(val);
      } else {
        node.inv += node.L.order_of_key(p[i]);
        node.inv -= node.L.order_of_key(val);
        node.R.erase(p[i]);
        node.R.insert(val);
      }
      ans += min(node.inv, node.pairs - node.inv);
      b = node.parent;
    }
    p[i] = val;
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    int px = p[x];
    int py = p[y];
    Modify(x, -1);
    Modify(y, px);
    Modify(x, py);
    cout << ans << '\n';
  }
  debug(clock());
  return 0;
}