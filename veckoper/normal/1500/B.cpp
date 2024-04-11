#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k, pa[N], pb[N], a[N], b[N];
int vg, vl;
vector<int> ps;
int Exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = Exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return d;
}
inline int CountSame(int tm) {
	int ans = tm / vl * ps.size();
	tm %= vl;
	for (auto x: ps) ans += (x <= tm);
	return ans;
}
signed main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	memset(pa, -1, sizeof pa);
	memset(pb, -1, sizeof pb);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
		pa[a[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%lld", b + i);
		pb[b[i]] = i;
	}
	vg = __gcd(n, m);
	vl = n * m / vg;
	for (int i = 0; i < N; ++i) if (pa[i] != -1 && pb[i] != -1) {
		int delta = pb[i] - pa[i];
		if (delta % vg) continue;
		int x, y;
		Exgcd(n, m, x, y);
		x *= delta / vg;
		int np = (n * x + pa[i]) % vl;
		if (np < 0) np += vl;
		ps.push_back(np);
	}
	int ans = -1;
	for (int l = 0, r = 1e18; l <= r; ) {
		int mid = (l + r) >> 1;
		if (mid + 1 - CountSame(mid) >= k) ans = mid, r = mid - 1; else l = mid + 1;
	}
	printf("%lld\n", ans + 1);
	return 0;
}