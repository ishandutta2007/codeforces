#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 7010;
bool kek[N][N];
ll a[N], b[N];
int cnt[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
  	cin >> b[i];
  }
  ll all = (1ll << 60) - 1;
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= n; j++) {
  		if (i != j) {
  			if ((a[i] & (a[j] ^ all)) > 0) {
  				kek[i][j] = true;
  				cnt[i]++;
  			}
  		}
  	}
  }
  int cc = n;
  vector<bool> take(n + 1, true);
  while (cc > 1) {
  	pair<int, int> best = {0, 0};
  	for (int i = 1; i <= n; i++) {
  		if (take[i]) {
  			best = max(best, make_pair(cnt[i], i));
  		}
  	}
  	if (best.F < cc - 1) {
  		break;
  	}
  	take[best.S] = false;
  	for (int i = 1; i <= n; i++) {
  		if (kek[i][best.S]) {
  			cnt[i]--;
  		}
  		kek[i][best.S] = 0;
  	}
  	cc--;
  }
  if (cc == 1) {
  	cout << 0 << '\n';
  	exit(0);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
  	if (take[i]) {
  		ans += b[i];
  	}
  }
  cout << ans << '\n';
}