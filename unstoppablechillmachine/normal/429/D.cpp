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
const int N = 1e5 + 10;
int a[N];
ll pref[N];
signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  ll ans = 1e18;
  for (int len = 2; len <= min(3000, n); len++) {
    if (len * len > ans) {
      break;
    }
    for (int l = 1; l + len - 1 <= n; l++) {
      ans = min(ans, (pref[l + len - 1] - pref[l]) * (pref[l + len - 1] - pref[l]) + (len - 1) * (len - 1));
    }
  }
  cout << ans << '\n';
}