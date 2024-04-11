#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define MOD 998244353

ll n, t, k, x, y, m;
ll a[200500];
vector<ll> g[100500];
vector<ll> f;
ll dp[5001][5001];
ll C[5005][5005];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int i = 0; i <= 5000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
  }
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll p1 = -1;
    ll k = 0;
    f.clear();
    for (int i = n-1; i >= 0; i--) {
      if (p1 != a[i]) {
        if (k != 0) {
          f.push_back(k);
        }
        k = 1;
        p1 = a[i];
      } else {
        k++;
      }
    }
    f.push_back(k);
    for (int i = 0; i <= n / 2; i++) {
      for (int j = 0; j <= n / 2; j++) {
        dp[i][j] = 0;
      }
    }
    if (f[0] > 1) {
      cout << 0 << "\n";
      continue;
    }
    dp[f[0]][0] = 1;
    ll cur_pos = f[0];
    for (size_t i = 1; i < f.size(); i++) {
      ll value = f[i];
      for (ll small = 0; small < cur_pos - small; small++) {
        ll big = cur_pos - small;
        ll diff = big - small - 1;
        if (big == n / 2) {
          diff++;
        }
        for (int j = 0; j <= min(value, diff); j++) {
          if (value - j >= 0 && value - j <= 1)
          dp[big + value - j][small + j] = (dp[big + value - j][small + j] + dp[big][small] * C[diff][j]) % MOD;
        }
      }
      cur_pos += value;

/*      for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j <= n/ 2; j++) {
          cout << dp[i][j] << " ";
        }
        cout << "\n";
      }
      cout << "\n";*/
    }
/*    for (int i = 0; i <= n/2; i++) {
      for (int j = 0; j <= n/2; j++) {
        cout << dp[i][j] << " ";
      }
      cout << "\n";
    }*/
    cout << dp[n/2][n/2] << "\n";
  }
  return 0;
}