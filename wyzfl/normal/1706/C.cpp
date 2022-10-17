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

const int N = 1e5 + 5;

int a[N], val[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 2, n - 1) val[i] = max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
		if (n % 2 == 1) {
			long long ans = 0;
			for (int i = 2; i <= n - 1; i += 2) {
				ans += val[i];
			}
			printf("%lld\n", ans);
		} else {
			long long ans = 1e18, sum = 0;
			for (int i = 3; i <= n - 1; i += 2) {
				sum += val[i];
			}
			ans = sum;
			for (int i = 2; i <= n - 2; i += 2) {
				sum += val[i];
				sum -= val[i + 1];
				ans = min(ans, sum);
			}
			printf("%lld\n", ans);
		}
	}
}