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

const int N = 2e5 + 5;

char s[N];
long long l[45], r[45];
int T, n, c, q;

char solve(long long x) {
	if (x <= n) return s[x];
	x -= n;
	rep(i, 1, c) {
		if (x <= r[i] - l[i] + 1) return solve(l[i] + x - 1);
		x -= (r[i] - l[i] + 1);
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		c = read();
		q = read();
		scanf("%s", s + 1);
		rep(i, 1, c) scanf("%lld%lld", &l[i], &r[i]);
		rep(i, 1, q) {
			long long x;
			scanf("%lld", &x);
			putchar(solve(x));
			putchar('\n');
		}
	}
}