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
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    while (max(a, b) <= n) {
      if (a >= b) {
        b += a;
      }
      else {
        a += b;
      }
      ans++;
    }
    cout << ans << '\n';
  }   
}