#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

const int md = 998244353;

inline int add(int a, int b) {
	return a + b < md ? a + b : a + b - md;
}
inline int mul(int a, int b) {
	return (long long)a * b % md;
}
int po(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) {
	return po(a, md - 2);
}
inline int di(int a, int b) {
	return mul(a, inv(b));
}

const int N = 200005;
int t, n, fact[N], c[N];
std::pair<int, int> a[N];

int ncr(int n, int r) {
	return mul(fact[n], inv(mul(fact[r], fact[n - r])));
}

const int B = N * 4;
int b[B];
void add(int i) {
	while (i < B) {
		++b[i];
		i |= i + 1;
	}
}

int get(int i) {
	int s = 0;
	while (i >= 0) {
		s += b[i];
		i = (i & i + 1) - 1;
	}
	return s;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i].first);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i].second);
	std::sort(a, a + n);
	int side;
	for (side = 0; side < n && a[n - 1 - side] == a[n - 1] && a[n - 1].second == 1; ++side);
	if (side < 2) side = 0;
	int ans = mul(ncr(n, side), fact[side]);
	if (side == n) {
		printf("%d\n", ans);
		return 0;
	}
	for (int i = 0; i < n - side;) {
		int cnt = 0, fi = i;
		do {
			c[i] = fi;
			++cnt;
			++i;
		} while (i < n - side && a[i] == a[i - 1]);
		ans = mul(ans, fact[cnt]);
		if (a[fi].second && cnt > 1) ans = 0;
	}
	int g;
	if (!a[0].second) g = a[0].first;
	else g = a[0].first + n - 1;
	if (side && g != a[n - 1].first) ans = 0;
	if (!side && g == a[n - 1].first && a[n - 1].second) ans = mul(ans, n);
	for (int i = 0; i < n - side && ans; ++i) {
		int x;
		if (a[i].second) x = g - a[i].first - (n - i - 1);
		else x = c[i] + a[i].first - g;
		if (x < 0) ans = 0;
		else if (get(x - 1) < x) ans = 0;
		else add(x);
	}
	printf("%d\n", ans);
	return 0;
}