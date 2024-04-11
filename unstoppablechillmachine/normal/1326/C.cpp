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

const int MOD = 998244353;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n, k;
  cin >> n >> k;
  int ans = 0;
  vector<int> pos;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a >= n - k + 1) {
      pos.pb(i);
      ans += a;
    }
  }  
  int cnt = 1;
  for (int i = 0; i + 1 < SZ(pos); i++) {
    cnt = (cnt * (pos[i + 1] - pos[i])) % MOD;
  }
  cout << ans << ' ' << cnt << '\n';
}