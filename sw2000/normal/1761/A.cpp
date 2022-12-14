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

bool solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a == n && b == n) return true;
  return a + b + 1 < n;
};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  freopen("a.in", "r", stdin);
  int _ = 1;
  cin >> _;
  while (_--) {
    cout << (solve() ? "Yes" : "No");
    cout << endl;
  }
}