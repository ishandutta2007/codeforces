#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int MOD = 1e9 + 7;
const int N = 2e6 + 10;
int a[N][3], ans[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //0 - 0 ch
  //1 - 1 ch
  //2 - >= 2ch
  a[1][0] = 1;
  for (int i = 1; i < 2e6; i++) {
    a[i + 1][0] = ((2ll * a[i][1]) % MOD + a[i][0]) % MOD;
    a[i + 1][1] = a[i][0];
    a[i + 1][2] = (a[i][2] + a[i][1]) % MOD;
  }
  for (int i = 3; i <= 2e6; i++) {
    ans[i] = ((ll)ans[i - 3] + a[i][2] - a[i - 1][2] + MOD) % MOD;
    //if (i < 50) cout << ans[i] << '\n';
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << (4ll * ans[n]) % MOD << '\n';
  }
  //cout << a[n][0] << ' ' << a[n][1] << ' ' << a[n][2] << '\n';
}