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

const int N = 2.5e5 + 10;
const int MX = 1e7 + 10;
const ll BINF = 1e18 + 10;
vector<int> h[N], cost[N];
pair<int, int> have[N];
int cc[N], to_r[MX], n;
ll dp[MX], t[MX];
inline void update(int v, ll val) {
  for (; v <= n; v += v & (-v)) {
    t[v] = min(t[v], val);
  }
}
inline ll get(int v) {
  ll res = BINF;
  for (; v > 0; v -= v & (-v)) {
    res = min(res, t[v]);
  }
  return res;
}
void source() {
  int blocks;
  cin >> blocks >> n;
  for (int i = 1; i <= n; i++) {
    t[i] = BINF;
  }
  for (int i = 1; i <= blocks; i++) {
    cin >> cc[i];
    h[i].resize(cc[i]);
    cost[i].resize(cc[i]);
    for (auto &it : h[i]) {
      cin >> it;
    }
    for (auto &it : cost[i]) {
      cin >> it;
    }
  }
  int bq;
  cin >> bq;
  for (int i = 0; i < bq; i++) {
    cin >> have[i].F >> have[i].S;
  }
  pair<int, int> ptr = {bq - 1, cc[have[bq - 1].F]};
  vector<pair<int, int>> st;
  for (int i = n; i >= 1; i--) {
    if (ptr.S > 0) {
      ptr.S--;
    }
    else {
      ptr.F--;
      ptr.S = cc[have[ptr.F].F] - 1;
    }
    int id = have[ptr.F].F, pos = ptr.S;
    to_r[i] = min(i + h[id][pos] - 1, n);
    while (!st.empty() && st.back().F <= to_r[i]) {
      to_r[i] = max(to_r[i], st.back().S);
      st.pop_back();
    }
    st.pb({i, to_r[i]});
  }
  st = {};
  ptr = {0, 0};
  for (int i = 1; i <= n; i++) {
    int id = have[ptr.F].F, mul = have[ptr.F].S, pos = ptr.S, to_l = max(i - h[id][pos] + 1, 1);
    while (!st.empty() && st.back().F >= to_l) {
      to_l = min(to_l, st.back().S);
      st.pop_back();
    }    
    st.pb({i, to_l});
    //cout << get(n - i + 1) << ' ';
    dp[i] = min(get(n - i + 1), cost[id][pos] * 1ll * mul + dp[to_l - 1]);
    //cout << dp[i] << ' ';
    update(n - to_r[i] + 1, cost[id][pos] * 1ll * mul + dp[i - 1]);
    if (pos + 1 == cc[id]) {
      ptr = {ptr.F + 1, 0};
    }
    else {
      ptr.S++;
    }
  }
  //cout << '\n';
  cout << dp[n];
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
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
  return 0;
}