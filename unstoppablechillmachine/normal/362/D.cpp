//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

struct DSU {
  vector<int> p, sz, sum;
  DSU(int n) {
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    sum.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }
  void merge(int a, int b, int add = -1) {
    a = find(a), b = find(b);
    if (a == b) {
      sum[a] += add;
      sum[a] = min(sum[a], 1000000000ll);
      return;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    if (add == -1) {
      add = min(1000000000ll, sum[a] + sum[b] + 1);
    }
    p[b] = a;
    sum[a] += add + sum[b];
    sum[a] = min(sum[a], 1000000000ll);
    sz[a] += sz[b];
  }
};

void source() {
  int n, m, p, q;
  cin >> n >> m >> p >> q;
  DSU A(n);
  pair<int, int> lst = {-1, -1};
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    lst = {u, v};
    if (u > v) {
      swap(u, v);
    }
    A.merge(u, v, c);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (A.find(i) == i) {
      cnt++;
    }
  }
  if (cnt < q) {
    cout << "NO";
    exit(0);
  }
  if (cnt - p > q) {
    cout << "NO";
    exit(0);
  }
  set<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    if (A.find(i) == i) {
      st.insert({A.sum[i], i});
    }
  }
  vector<pair<int, int>> edge;
  while (SZ(st) > q) {
    if (p == 0) {
      cout << "NO";
      exit(0);
    }
    p--;
    int v = st.begin()->S;
    st.erase(st.begin());
    int u = st.begin()->S;
    edge.pb({u, v});
    lst = {u, v};
    st.erase(st.begin());
    A.merge(u, v);
    int rt = A.find(u);
    st.insert({A.sum[rt], rt});
  }
  if (p > 0) {
    if (lst.F == -1) {
      cout << "NO";
      exit(0);
    }
    for (int i =0 ; i < p; i++) {
      edge.pb({lst.F, lst.S});
    }
  }
  cout << "YES\n";
  for (auto it : edge) {
    cout << it.F << ' ' << it.S << '\n';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}