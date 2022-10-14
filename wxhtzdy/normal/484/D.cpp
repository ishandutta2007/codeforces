/**
 *    author:  wxhtzdy
 *    created: 25.01.2022 07:16:33
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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

// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   SparseTable<int, decltype(fun)> st(a, fun);
// or:
//   SparseTable<int> st(a, [&](int i, int j) { return min(i, j); });
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SparseTable<int> mn(a, [&](int i, int j) { return min(i, j); });
  SparseTable<int> mx(a, [&](int i, int j) { return max(i, j); });
  vector<long long> dp(n);                    
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int ptr = i;
    while (ptr + 1 < n && a[ptr + 1] > a[ptr]) {
      g[ptr].push_back(i);
      ptr += 1;
    }
    int nxt = ptr;     
    g[ptr].push_back(i);
    ptr = i;
    while (ptr + 1 < n && a[ptr + 1] < a[ptr]) {
      g[ptr].push_back(i);
      ptr += 1;
    }
    g[ptr].push_back(i);
    i = max(nxt, ptr) + 1;
  }
  for (int i = 0; i < n; i++) {
    g[i].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      dp[i] = dp[i - 1];
    }    
    for (int x : g[i]) {
      for (int j = x - 5; j <= x + 5; j++) {
        if (j < 0 || j > i) {
          continue;
        } 
        dp[i] = max(dp[i], (j > 0 ? dp[j - 1] : 0LL) + mx.get(j, i) - mn.get(j, i));
      }
    }
  }
  debug(dp);
  cout << dp[n - 1] << '\n';
  return 0;
}