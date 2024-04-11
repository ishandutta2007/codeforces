#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

const int N = 1e6 + 10;
const int BINF = 1e18 + 10;
int t[4 * N], f[4 * N];

inline void push(int v) {
  t[2 * v] += f[v];
  t[2 * v + 1] += f[v];
  f[2 * v] += f[v];
  f[2 * v + 1] += f[v];
  f[v] = 0;
}

void update(int v, int l, int r, int a, int b, int delta) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    t[v] += delta;
    f[v] += delta;
    return;
  }
  push(v);
  int mid = (l + r) / 2;
  update(2 * v, l, mid, a, b, delta);
  update(2 * v + 1, mid + 1, r, a, b, delta);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get_max(int v, int l, int r, int a, int b) {
  if (l > b || r < a) {
    return -BINF;
  }
  if (l >= a && r <= b) {
    return t[v];
  }
  push(v);
  int mid = (l + r) / 2;
  return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
}

vector<int> check[N];
vector<pair<int, int>> upd[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
      int x, cost;
      cin >> x >> cost;
      check[x - 1].pb(cost);
    }
    vector<pair<int, int>> kek(m);
    for (int i = 0; i < m; i++) {
      cin >> kek[i].F >> kek[i].S;
    }
    sort(all(kek));
    vector<pair<int, int>> kek2;
    kek2.pb(kek[0]);
    for (int i = 1; i < m; i++) {
      if (kek[i].F != kek2.back().F) {
        kek2.pb(kek[i]);
      }
    }
    for (auto it : kek) {
      while (!kek2.empty() && it.S <= kek2.back().S) {
        kek2.pop_back();
      }
      kek2.pb(it);
    }
    kek = kek2;
    for (int i = 1; i <= p; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      upd[x].pb({y, z});
    }
    int prv = 0, sz = SZ(kek);
    int ptr = 0;
    for (auto it : kek) {
      update(1, 1, sz, ++ptr, sz, -abs(prv - it.S)) ;
      prv = it.S;
    }
    int ans = -BINF;
    for (int i = 0; i <= 1e6; i++) {
      for (auto it : upd[i]) {
        int pos = lower_bound(all(kek), make_pair(it.F, BINF)) - kek.begin() + 1;
        if (pos <= SZ(kek)) {
          update(1, 1, sz, pos, sz, it.S);
        }
      }
      for (auto it : check[i]) {
        ans = max(ans, t[1] - it);
      }
    }
    cout << ans << '\n';
}