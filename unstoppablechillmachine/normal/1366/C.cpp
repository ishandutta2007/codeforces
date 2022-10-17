#pragma GCC optimize("O3")
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
    vector<int> al(n + m), sum(n + m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int x;
        cin >> x;
        int dst = min(i + j - 2, n - i + m - j);
        al[dst]++;
        sum[dst] += x;
      }
    }
    int ans = 0;
    for (int i = 0; i <= (n + m - 3) / 2; i++) {
      ans += min(sum[i], al[i] - sum[i]);
    }
    cout << ans << '\n';
  }  
}