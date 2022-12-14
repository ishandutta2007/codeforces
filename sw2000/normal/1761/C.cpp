#include <bits/stdc++.h>
#ifdef SW2000
#include "debug_info.h"
#else
using namespace std;
#define freopen(a, b, c)
#define D(...)
#endif
#define endl '\n'
#define fi first
#define se second
template <class T>
void Min(T& a, const T b) {
  if (a > b) a = b;
}
template <class T>
void Max(T& a, const T b) {
  if (a < b) a = b;
}
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e5 + 10, M = 100;

void solve() {
  int n;
  cin >> n;
  vector<string> ar(n);
  for (auto& i : ar) {
    cin >> i;
  }
  vector<vi> ans(n, vi(n, 0));
  for (int i = 0; i < n; i++) {
    vi vis(n);
    vi stk{i};
    while (!stk.empty()) {
      int u = stk.back();
      stk.pop_back();
      if (vis[u]) continue;
      vis[u] = 1;
      ans[u][i] = 1;
      for (int j = 0; j < n; j++) {
        if (ar[u][j] == '1') {
          stk.push_back(j);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    vi v;
    for (int j = 0; j < n; j++) {
      if (ans[i][j]) v.push_back(j);
    }
    cout << v.size();
    for (auto j : v) {
      cout << " " << j + 1;
    }
    cout << endl;
  }
};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  freopen("a.in", "r", stdin);
  int _ = 1;
  cin >> _;
  while (_--) {
    // cout <<
    (solve());
    // cout << endl;
  }
}