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

const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * b) % MOD;
}

int solve(int n, vector<int> &a) {
  vector<vector<int>> C(101, vector<int>(101));
  C[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    C[i][0] = 1;
    C[i][1] = i;
    C[i][2] = i * (i - 1) / 2;
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 3; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
  vector<vector<int>> dp(11, vector<int>(n + 1));
  dp[0][0] = 1;
  for (int i = 0; i < 10; i++) {
    for (int len = 0; len <= n; len++) {
      for (int take = 0; take + len <= n; take++) {
        if (take >= a[i]) {
          add(dp[i + 1][take + len], mult(dp[i][len], C[n - len][take]));
        }
      }
    }
  }
  return dp[10][n];
}

void source() {
  int n;
  cin >> n;
  vector<int> a(10);
  for (auto &it : a) {
    cin >> it;
  }
  int ans = 0;
  for (int i = 1; i < 10; i++) {
    a[i]--;
    for (int j = 0; j <= n - 1; j++) {
      add(ans, solve(j, a));
    }
    a[i]++;
  }
  cout << ans;
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