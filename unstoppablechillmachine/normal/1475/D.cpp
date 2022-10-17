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
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> have(3);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      have[b[i]].pb(a[i]);
    }
    sort(have[1].rbegin(), have[1].rend());
    sort(have[2].rbegin(), have[2].rend());
    int ptr = 0, sum = 0;
    while (ptr < SZ(have[1]) && sum < m) {
      sum += have[1][ptr++];
    }
    int ans = 1e9;
    if (sum >= m) {
      ans = min(ans, ptr);
    }
    for (int i = 0; i < SZ(have[2]); i++) {
      sum += have[2][i];
      while (ptr > 0 && sum - have[1][ptr - 1] >= m) {
        sum -= have[1][--ptr];
      }
      if (sum >= m) {
        ans = min(ans, ptr + 2 * (i + 1));
      }
    }
    if (ans == 1e9) {
      cout << -1 << '\n';
    }
    else {
      cout << ans << '\n';
    }
  }
}