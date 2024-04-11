#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

int T;
long long l, r;

long long calc(long long x) {
	long long l = 1, r = 1e9, val = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (mid * mid <= x)
			val = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	long long ans = (val - 1) * 3 + 1;
	if (1ll * val * (val + 1) <= x) ++ans;
	if (1ll * val * (val + 2) <= x) ++ans;
	return ans;
}

signed main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", calc(r) - calc(l - 1));
	}
}