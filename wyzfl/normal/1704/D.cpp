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

const int N = 3e5 + 5;

unsigned long long sum[N];
int T, n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		rep(i, 1, n) {
			sum[i] = 0;
			rep(j, 1, m) {
				long long x;
				scanf("%lld", &x);
				sum[i] += (unsigned long long)x * j;
			}
		}
		unsigned long long tmp;
		if (sum[1] == sum[2])
			tmp = sum[1];
		else if (sum[1] == sum[3])
			tmp = sum[1];
		else
			tmp = sum[2];
		rep(i, 1, n) {
			if (sum[i] != tmp) {
				printf("%d %llu\n", i, sum[i] - tmp);
			}
		}
	}
}