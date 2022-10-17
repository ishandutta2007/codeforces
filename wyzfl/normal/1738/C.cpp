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

const int N = 105;

int a[N], dp[N][N][2];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	dp[0][0][0] = 1;
	rep(i, 0, 100) rep(j, 0, 100) rep(k, 0, 1) {
		if (i == 0 && j == 0) continue;
		int all = j & 1;
		if (i) dp[i][j][k] |= (!dp[i - 1][j][k ^ all ^ 1]);
		if (j) dp[i][j][k] |= (!dp[i][j - 1][k ^ all ^ 1]);
	}
	T = read();
	while (T--) {
		n = read();
		int cnt[2] = { 0, 0 };
		rep(i, 1, n) a[i] = read(), ++cnt[a[i] & 1];
		printf("%s\n", dp[cnt[0]][cnt[1]][0] ? "Alice" : "Bob");
	}
}