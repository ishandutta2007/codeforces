#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int n;
ll a[200111], ans = 1 << 20;

void go(ll p) {
	ll cur = 0;
	rep(i, 0, n) {
		ll r = a[i] % p;
		if (r < a[i])
			cur += min(r, p - r);
		else
			cur += p - r;
	}
	ans = min(ans, cur);
}

void solve(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			go(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x > 1)
		go(x);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	srand(233);

	cin >> n;
	rep(i, 0, n)
		cin >> a[i];
	random_shuffle(a, a + n);
	rep(i, 0, min(n, 26)) {
		solve(a[i] - 1);
		solve(a[i]);
		solve(a[i] + 1);
	}
	cout << ans << endl;
	return 0;
}