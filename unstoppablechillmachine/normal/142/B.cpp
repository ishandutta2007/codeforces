//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

vector<pair<int, int>> delta = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int solve(int n, int m) {
  vector<vector<bool> > used(n + 1, vector<bool>(m + 1));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!used[i][j]) {
        used[i][j] = true;
        ans++;
        for (auto it : delta) {
          int ii = i + it.F, jj = j + it.S;
          if (ii >= 1 && ii <= n && jj >= 1 && jj <= m) {
            used[ii][jj] = true;
          }
        }
      }
    }
  }
  return ans;
}

int solve2(int n, int m) {
  if (min(n, m) == 1) {
    return max(n, m);
  }
  n = max(n, m) * 2;
  return ((n / 8) * 4) + min(4ll, n % 8);
}

void source() {
  int n, m;
  cin >> n >> m;
  cout << max(solve2(n, m), max((n * m + 1) / 2, max(n * (m / 3 + (m % 3 != 0)), m * (n / 3 + (n % 3 != 0)))));
}
 
signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
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