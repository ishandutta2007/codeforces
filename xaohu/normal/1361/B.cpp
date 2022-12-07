#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int P = 1e9 + 7;
int t, n, p, a[1000000];

int power(int a, int b) {
	int res = 1;
	for (; b; a = 1ll * a * a % P, b /= 2)
		if (b & 1)
			res = 1ll * res * a % P;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> p;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, greater<int>());
		ll s = 0, res = 0;
		bool big = false;
		for (int i = 0; i < n; i++) {
			if (big || s > 0) {
				s--;
				res = (res - power(p, a[i]) + P) % P;
			}
			else {
				s++;
				res = (res + power(p, a[i])) % P;
			}
			if (i + 1 < n && p > 1 && s > 0 && big == false) {
				for (int j = 0; j < a[i] - a[i + 1]; j++) {
					s *= p;
					if (s > n) {
						big = true;
						break;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}