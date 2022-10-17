#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int N = 21 * 1e5 + 10;
const int MX = 25;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int len[N], vl[N], vl2[N], cnt;
int up[N][MX], digit[N];
vector<pair<int, int>> g[N];

void connect(int u, int v, int cost) {
  vector<int> arr;
  int cur = cost;
  if (cur == 0) {
    arr = {0};
  }
  while (cur > 0) {
    arr.pb(cur % 10);
    cur /= 10;
  }
  reverse(all(arr));
  int prv = len[u];
  for (int i = 0; i + 1 < SZ(arr); i++) {
    prv++;
    cnt++;
    len[cnt] = prv;
    up[cnt][0] = (i ? cnt - 1 : u);
    vl[cnt] = (vl[up[cnt][0]] * 1ll * 10 + arr[i]) % MOD;
    vl2[cnt] = (vl2[up[cnt][0]] * 1ll * 10 + arr[i]) % MOD2;
    digit[cnt] = arr[i];
    for (int j = 1; j < MX; j++) {
      up[cnt][j] = up[up[cnt][j - 1]][j - 1];
    }
  }

  len[v] = prv + 1;
  up[v][0] = (SZ(arr) > 1 ? cnt : u);
  vl[v] = (vl[up[v][0]] * 1ll * 10 + arr.back()) % MOD;
  vl2[v] = (vl2[up[v][0]] * 1ll * 10 + arr.back()) % MOD2;
  for (int j = 1; j < MX; j++) {
    up[v][j] = up[up[v][j - 1]][j - 1];
  }
  digit[v] = arr.back();
}

int add_fake(int u, int cost) {
  vector<int> arr;
  int cur = cost;
  if (cur == 0) {
    arr = {0};
  }
  while (cur > 0) {
    arr.pb(cur % 10);
    cur /= 10;
  }
  reverse(all(arr));
  int prv = len[u];
  for (int i = 0; i < SZ(arr); i++) {
    prv++;
    cnt++;
    len[cnt] = prv;
    up[cnt][0] = (i ? cnt - 1 : u);
    vl[cnt] = (vl[up[cnt][0]] * 1ll * 10 + arr[i]) % MOD;
    vl2[cnt] = (vl2[up[cnt][0]] * 1ll * 10 + arr[i]) % MOD2;
    digit[cnt] = arr[i];
    for (int j = 1; j < MX; j++) {
      up[cnt][j] = up[up[cnt][j - 1]][j - 1];
    }
  }
  return cnt; 
}

inline bool isLess(int u, int v) {
  if (len[u] != len[v]) {
    return len[u] < len[v];
  }  
  if (vl[u] == vl[v]) {
    return u < v;
  }
  for (int i = MX - 1; i >= 0; i--) {
    if (vl[up[u][i]] != vl[up[v][i]] || vl2[up[u][i]] != vl2[up[v][i]]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return (digit[u] != digit[v] ? digit[u] < digit[v] : u < v);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  cnt = n;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb({v, i + 1});
    g[v].pb({u, i + 1});
  }
  connect(0, 1, 0);
  for (int i = 2; i <= n; i++) {
    len[i] = INF;
  }
  auto cmp = [](int u, int v) {
    return isLess(u, v);  
  };
  set<int, decltype(cmp)> st(cmp);
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }
  vector<int> parent(n + 1);
  vector<bool> used(n + 1);
  while (!st.empty()) {
    int v = *st.begin();
    st.erase(v);
    used[v] = true;
    for (auto u : g[v]) {
      if (used[u.F]) {
        continue;
      }
      if (!parent[u.F] || isLess(add_fake(v, u.S), u.F)) {
        st.erase(u.F);
        parent[u.F] = v;
        connect(v, u.F, u.S);
        st.insert(u.F);
      }
    }
  }
  for (int  i = 2; i <= n; i++) {
    assert(used[i]);
    cout << vl[i] << '\n';
  }
}