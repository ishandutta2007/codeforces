/**
 *    author:  tourist
 *    created: 04.01.2019 18:48:28       
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

const int md = (int) 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<vector<int>> dp1(n, vector<int>(k + 1, 0));
  vector<vector<int>> dp2(n, vector<int>(k + 1, 0));
  vector<vector<int>> dp3(n, vector<int>(k + 1, 0));
  vector<int> aux1(k + 1);
  vector<int> aux2(k + 1);
  vector<int> aux3(k + 1);
  vector<int> sz(n);
  function<void(int, int)> dfs = [&](int v, int pr) {
    dp1[v][0] = 0;
    dp2[v][0] = 2;
    dp3[v][0] = 1;
    sz[v] = 1;
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      dfs(u, v);
      int bound = min(sz[v] - 1 + sz[u], k);
      for (int i = 0; i <= bound; i++) {
        aux1[i] = aux2[i] = aux3[i] = 0;
      }
      for (int i = 0; i <= min(sz[v] - 1, k); i++) {
        for (int j = 0; j <= min(sz[u], k - i); j++) {
          add(aux3[i + j], mul(dp3[v][i], dp3[u][j]));
          add(aux2[i + j], mul(dp2[v][i], dp2[u][j]));
          add(aux1[i + j], mul(dp1[v][i], dp3[u][j]));
          add(aux1[i + j], mul(dp3[v][i], dp1[u][j]));
        }
      }
      for (int i = 0; i <= bound; i++) {
        dp1[v][i] = aux1[i];
        dp2[v][i] = aux2[i];
        dp3[v][i] = aux3[i];
      }
      sz[v] += sz[u];
    }
    if (v != 0) {
      for (int j = min(k, sz[v]) - 1; j >= 0; j--) {
        add(dp3[v][j + 1], dp3[v][j]);
        add(dp1[v][j + 1], dp1[v][j]);
        add(dp1[v][j + 1], dp2[v][j]);
        add(dp2[v][j + 1], dp3[v][j]);
      }
    }
  };
  dfs(0, -1);
  const int MAX = max(n, k);
  vector<int> fact(MAX + 1);
  fact[0] = 1;
  for (int i = 0; i < MAX; i++) {
    fact[i + 1] = mul(fact[i], i + 1);
  }
  vector<int> inv_fact(MAX + 1);
  for (int i = 0; i <= MAX; i++) {
    inv_fact[i] = inv(fact[i]);
  }
  auto C = [&](int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
  };
  vector<int> v(k + 1);
  for (int i = 0; i <= k; i++) {
    v[i] = dp1[0][i];
    add(v[i], dp2[0][i]);
    sub(v[i], mul(i + 1, dp3[0][i]));
  }
  vector<int> w(k + 1);
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= i; j++) {
      int cur = v[j];
      cur = mul(cur, C(n - 1 - j, i - j));
      if (j % 2 == 1) {
        cur = (md - cur) % md;
      }
      add(w[i], cur);
    }
  }
  vector<vector<int>> stir(k + 1, vector<int>(k + 1, 0));
  stir[0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= i; j++) {
      add(stir[i + 1][j], mul(stir[i][j], j));
      add(stir[i + 1][j + 1], stir[i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    add(ans, mul(w[i], mul(stir[k][i], fact[i])));
  }
  cout << ans << '\n';
  return 0;
}