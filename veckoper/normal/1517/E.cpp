#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int p = 998244353;
int Case, n, a[N], s1[N], s2[N];
inline int Solve(int st, int ed, int psm, int csm) {
	int ans = 0;
	for (int i = st; i <= ed; ++i) {
		int tmp = -1;
		for (int l = 0, r = (ed - (ed == n ? 0 : 2) - i + 2) / 2 - 1; l <= r; ) {
			int mid = (l + r) >> 1;
			int ps = i + mid * 2;
			if (csm + s1[i] - s1[st - 1] + s2[ps] - s2[i] < psm + s1[ed] - s1[ps] + s2[ps - 1] - s2[i - 1]) 
				tmp = mid, l = mid + 1; 
			else r = mid - 1;
		}
		ans += tmp + 1;
	}
	// printf("%lld %lld   %lld\n", st, ed, ans);
	return ans;
}
signed main() {
	scanf("%lld", &Case);
	while (Case--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			s1[i] = a[i] + s1[i - 1];
			s2[i] = a[i] + (i >= 2 ? s2[i - 2] : 0);
		}
		if (n == 1) { puts("1"); continue; }
		int ans = Solve(1, n, 0, 0);
		ans += Solve(1, n - 1, 0, a[n]);
		ans += Solve(2, n, a[1], 0);
		ans += Solve(2, n - 1, a[1], a[n]);
		for (int i = 2; i <= n; ++i) if (s1[n] - s1[i] < s1[i]) ++ans;
		printf("%lld\n", ans % p);
	}
	return 0;
}