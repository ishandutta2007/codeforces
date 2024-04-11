#include <bits/stdc++.h>
using namespace std;
#define int long long

const int B = 200;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;

	int p[n], x[m], d[n];
	for(int &i : p) cin >> i;
	for(int &i : x) cin >> i, i += i;

	sort(x, x + m);

	int pt {}, ans {};
	for(int i = 0; i < n; ++i) {
		int u = B * i;
		for(; pt < m && x[pt] <= u; ++pt);
		d[i] = pt ? abs(u - x[pt-1]) : 1e18;
		if(pt < m) d[i] = min(d[i], abs(u - x[pt]));
	}

	for(int i = 1; i < n; ++i)
		p[i] += p[i-1];

	auto check = [&](int u) {
		u = max(u, (int)(0));
		u = min(u, (n - 1) * B);
		int l = u / B, r = l + 1;
		if(r == n) --l, --r;

		++l, --r;
		for(int i = 1<<19; i /= 2; ) {
			if(l - i >= 0 && d[l - i] > abs((l - i) * B - u)) l -= i;
			if(r + i <  n && d[r + i] > abs((r + i) * B - u)) r += i;
		}
		if(l <= r) ans = max(ans, (p[r] - (l ? p[l-1] : 0LL)));
	};

	for(int i = 0; i < n; ++i) {
		check(i * B - d[i] + 1);
		check(i * B + d[i] - 1);
	}
	cout << ans;
}