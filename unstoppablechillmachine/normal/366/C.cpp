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

bitset<10010> can[10010];
int a[110], b[110];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  can[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int wasa = 100 * (i - 1); wasa >= 0; wasa--) {
      can[wasa + a[i]] |= can[wasa] << b[i];
    }
  }
  int ans = -1;
  for (int i = 1; i <= n * 100; i++) {
    if (i % k == 0 && can[i][i / k]) {
      ans = max(ans, i);
    }
  }
  cout << ans << '\n';
}