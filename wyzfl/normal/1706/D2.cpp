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

int a[N], mx[N], seq[N];
int T, n, k;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		memset(mx, 0, sizeof(mx));
		n = read();
		k = read();
		int maxn = 0;
		rep(i, 1, n) {
			a[i] = read();
			int len = 0;
			for (int l = 1, r; l <= min(a[i], k); l = r + 1) {
				r = a[i] / (a[i] / l);
				seq[++len] = a[i] / l;
			}
			if (k > a[i]) seq[++len] = 0;
			reverse(seq + 1, seq + len + 1);
			maxn = max(maxn, seq[1]);
			seq[len + 1] = 1e9;
			rep(j, 1, len) {
				mx[seq[j]] = max(mx[seq[j]], seq[j + 1]);
			}
		}
		int ans = 1e5;
		rep(i, 0, 100000) {
			ans = min(ans, maxn - i);
			maxn = max(maxn, mx[i]);
		}
		printf("%d\n", ans);
	}
}