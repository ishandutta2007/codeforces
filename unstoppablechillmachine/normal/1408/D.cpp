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

const int N = 1e6 + 10;
int up[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(n + 1), c(m + 1), d(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  } 
  for (int j = 1; j <= m; j++) {
    cin >> c[j] >> d[j];
  }  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] <= c[j] && b[i] <= d[j]) {
        up[c[j] - a[i]] = max(up[c[j] - a[i]], d[j] - b[i] + 1);
      }
    }
  }
  int ans = 1e9;
  for (int i = 1e6; i >= 0; i--) {
    up[i] = max(up[i], up[i + 1]);
    ans = min(ans, i + up[i]);
  }
  cout << ans << '\n';
}