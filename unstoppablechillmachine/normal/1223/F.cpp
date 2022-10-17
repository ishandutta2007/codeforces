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

const int N = 3e5 + 10;
int a[N], to[N], dp[N];
bool was[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      was[i] = false;
    }
    to[n] = n + 1;
    was[a[n]] = true;
    for (int i = 1; i <= n + 1; i++) {
      dp[i] = 0;
    }
    ll ans = 0;
    for (int i = n - 1; i >= 1; i--) {
      if (!was[a[i]]) {
        was[a[i]] = true;
        to[i] = n + 1;
        continue;
      }
      to[i] = i;
      while (to[i] < n && a[to[i] + 1] != a[i]) {
        to[i] = to[to[i] + 1];
      }
      if (to[i] >= n) {
        to[i] = n + 1;
      }
      else {
        to[i]++;
        dp[i] = dp[to[i] + 1] + 1;
        ans += dp[i];
      }
    }
    cout << ans << '\n';
  }  
}