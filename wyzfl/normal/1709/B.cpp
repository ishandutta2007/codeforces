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

long long s1[N], s2[N];
int a[N];
int n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n - 1) {
		s1[i] = s1[i - 1] + max(0, a[i] - a[i + 1]);
	}
	per(i, n - 1, 1) {
		s2[i] = s2[i + 1] + max(0, a[i + 1] - a[i]);
	}
	while (m--) {
		int l = read(), r = read();
		if (l <= r) {
			printf("%lld\n", s1[r - 1] - s1[l - 1]);
		} else {
			printf("%lld\n", s2[r] - s2[l]);
		}
	}
}