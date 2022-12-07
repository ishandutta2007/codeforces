#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 100;

int n;
ll sum, a[N], diff[N];

ll f(ll c1) {
	return max(c1, a[n] - (c1 - sum));
} 

void solve() {
	ll L = -1e15, R = 1e15;
	while (R - L > 5) {
		ll M = (L + R) / 2;
		if (f(M + 1) - f(M) > 0)
			R = M;
		else
			L = M + 1;
	}
	ll out = 1e18;
	for (ll i = L; i <= R; ++i) {
		out = min(out, f(i));
		//~ cout << i << " = " << f(i) << " " << -i + sum << endl;
	}
	printf ("%lld\n", out);
}

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf ("%lld", a + i);
	for (int i = 1; i + 1 <= n; ++i)
		diff[i] = a[i] - a[i + 1], sum += max(diff[i], 0LL);
	solve();
	int q;
	scanf ("%d", &q);
	while (q--) {
		int l, r, x;
		scanf ("%d%d%d", &l, &r, &x);
		
		if (l > 1) {
			sum -= max(diff[l - 1], 0LL);
			diff[l - 1] -= x;
			sum += max(diff[l - 1], 0LL);
		}
		
		if (r < n) {
			sum -= max(diff[r], 0LL);
			diff[r] += x;
			sum += max(diff[r], 0LL);
		}	
		
		if (r == n) a[n] += x;
		
		solve();
	}

	return 0;
}