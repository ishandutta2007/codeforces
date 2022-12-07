#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int P = 998244353;

ll power(ll a, ll b) {
	ll res = 1;
	for (; b > 0; b /= 2, a = a * a % P)
		if (b & 1)
			res = res * a % P;
	return res;
}

int n;
ll cnt[100001], dp[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		int x, f;
		cin >> x >> f;
		cnt[x] = f;
	}
	for (int i = 100000; 1 <= i; i--) {

		auto add = [&](ll &a, ll b) {
			a = (a + b) % P; 
		};

		ll s = 0;
		ll same = 0;
		ll c = 0;

		for (ll j = i; j <= 100000; j += i) {
			c += cnt[j];
			add(s, j * cnt[j]);
			add(same, j * j % P * cnt[j]);
			if (j > i)
				add(dp[i], P - dp[j]);
		}

		ll d = c % P;
		add(dp[i], same * (d - 1 + P) % P * power(2, c - 2) % P);
		add(dp[i], (s * s % P - same + P) * ((d - 2 + P) * power(2, c - 3) % P + power(2, c - 2)));
	}

	cout << dp[1] << endl;
	return 0;
}