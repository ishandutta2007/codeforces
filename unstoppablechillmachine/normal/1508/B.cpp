#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
const int N = 110;
const int INF = (ll)(1e18) + 10;
int dp[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  dp[0] = 1;
  int lim = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] += dp[i - j];
      dp[i] = min(dp[i], INF);
    }
    if (dp[i] >= INF) {
      lim = i;
      break;
    }
  }  
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int lst = max(0ll, n - lim);
    for (int i = 1; i <= lst; i++) {
      cout << i << ' ';
    }
    int ost = n - lst;
    if (dp[ost] < k) {
      cout << -1 << '\n';
      continue;
    }
    int kek = lst;
    while (kek < n) {
      for (int i = 1; i <= n - kek; i++) {
        if (dp[n - kek - i] >= k) {
          for (int j = kek + i; j > kek; j--) {
            cout << j << ' ';
          } 
          kek += i;
          break;
        }
        k -= dp[n - kek - i];
      }
    }
    cout << '\n';
  }
}