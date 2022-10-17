#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

int f(int n) {
	int cnt = 0;
	for (int i = 2; i * i <= n; i++) {
		int cc = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
			cc++;
		}
		if (cc > 1) {
			return 0;
		}
	}
	if (n > 1) {
		cnt++;
	}
	return (cnt % 2 == 0 ? 1 : -1);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int a, m;
		cin >> a >> m;
		int k = __gcd(a, m);
		a /= k;
		m /= k;
		int ans = 0;
		for (int i = 1; i * i <= m; i++) {
			if (m % i == 0) {
				int ost = a % i, need = (i - ost) % i;
				int kek = m - 1;
				int csum = 0;
				if (kek != i - 1) {
					if (kek % i >= need) {
						csum++;
					}
					kek = kek - kek % i - 1;
				}
				csum += (kek + 1) / i;
				ans += csum * f(i);
				//cout << i << ' ' << csum << ' ' << f(i) << '\n';
				if (m / i != i) {
					int j = m / i;
					int ost = a % j, need = (j - ost) % j;
					int kek = m - 1;
					int csum = 0;
					if (kek != j - 1) {
						if (kek % j >= need) {
							csum++;
						}
						kek = kek - kek % j - 1;
					}
					csum += (kek + 1) / j;
					ans += csum * f(j);
					//cout << j << ' ' << csum << ' ' << f(j) << '\n';
				}
			}
		}
		cout << ans << '\n';
	}	
}