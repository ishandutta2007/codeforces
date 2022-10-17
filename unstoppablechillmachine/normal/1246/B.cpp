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
bool p[N];
int cnt[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> primes;
  for (int i = 2; i <= 1e5; i++) {
  	if (!p[i]) {
  		primes.pb(i);
  		if (i * 1ll * i <= 1e5) {
  			for (int j = i * i; j <= 1e5; j += i) {
  				p[j] = true;
  			}
  		}
  	}
  }
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
  	int x;
  	cin >> x;
  	int cur_vl = 1;
  	ll obr_vl = 1;
  	for (int j : primes) {
  		if (j * j > x) {
  			break;
  		}
  		if (x % j == 0) {
  			int cnt = 0;
  			while (x % j == 0) {
  				cnt++;
  				x /= j;
  			}
  			cnt %= k;
  			if (cnt != 0) {
  				for (int p = 0; p < cnt; p++) {
  					cur_vl *= j;
  				}
  				for (int p = 0; p < k - cnt; p++) {
  					if (obr_vl > 1e5) {
  						break;
  					}
  					obr_vl *= j;
  				}
  			}
  		}
  	}
  	if (x != 1) {
  		cur_vl *= x;
  		for (int p = 0; p < k - 1; p++) {
  			if (obr_vl > 1e5) {
  				break;
  			}
  			obr_vl *= x;
  		}
  	}
  	if (obr_vl <= 1e5) {
  		ans += cnt[obr_vl];
  	}
  	cnt[cur_vl]++;
  }
  cout << ans << '\n';
}