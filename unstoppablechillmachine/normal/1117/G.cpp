#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

#define next nextt
#define prev prevv

const int N = 1e6 + 10;
int a[N], prev[N], next[N], l[N], r[N];
ll ans[N];
vector<pair<int, int>> q1[N], q2[N];

struct ST {
  vector<ll> f1, f2;
  ST(int n) {
    f1.resize(4 * n + 10);
    f2.resize(4 * n + 10);
  }
  void push(int v) {
    f1[2 * v] += f1[v];
    f1[2 * v + 1] += f1[v];
    f1[v] = 0;
    f2[2 * v] += f2[v];
    f2[2 * v + 1] += f2[v];
    f2[v] = 0;
  }
  void update1(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      f1[v] += delta;
      return;
    }
    push(v);
    int mid = (l + r) / 2;
    update1(2 * v, l, mid, a, b, delta);
    update1(2 * v + 1, mid + 1, r, a, b, delta);
  }
  void update2(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      f2[v] += delta;
      return;
    }
    push(v);
    int mid = (l + r) / 2;
    update2(2 * v, l, mid, a, b, delta);
    update2(2 * v + 1, mid + 1, r, a, b, delta);  
  }
  ll get(int v, int l, int r, int need) {
    if (l == r) {
      return l * f2[v] + f1[v];
    }
    int mid = (l + r) / 2;
    push(v);
    if (need <= mid) {
      return get(2 * v, l, mid, need);
    }
    return get(2 * v + 1, mid + 1, r, need);
  }
};

void source() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> st;
  for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[i] > st.back().F) {
      st.pop_back();
    }
    if (st.empty()) {
      next[i] = n + 1;
    }
    else {
      next[i] = st.back().S - 1;
    }
    st.pb({a[i], i});
  }
  st = {};
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[i] > st.back().F) {
      st.pop_back();
    }
    if (st.empty()) {
      prev[i] = 0;
    }
    else {
      prev[i] = st.back().S + 1;
    }
    st.pb({a[i], i});
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> r[i];
  }
  for (int i = 0; i < m; i++) {
    q1[l[i]].pb({r[i], i});
    q2[r[i]].pb({l[i], i});
    ans[i] = r[i] - l[i] + 1;
  }
  ST tree(n);
  for (int i = n; i >= 1; i--) {
    tree.update1(1, 1, n, next[i], n, next[i]);
    tree.update2(1, 1, n, i, next[i] - 1, 1);
    for (auto it : q1[i]) {
      ans[it.S] += tree.get(1, 1, n, it.F);
    }
  }
  ST tree2(n);
  for (int i = 1; i <= n; i++) {
    tree2.update1(1, 1, n, 1, prev[i], prev[i]);
    tree2.update2(1, 1, n, prev[i] + 1, i, 1);
    for (auto it : q2[i]) {
      ans[it.S] -= tree2.get(1, 1, n, it.F);
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << ' ';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}