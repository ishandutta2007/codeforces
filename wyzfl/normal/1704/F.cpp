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

const int N = 5e5 + 5;

int sg[N], b[N], cnt[2];
char c[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	rep(i, 2, 500000) {
		if (i >= 87) {
			sg[i] = sg[i - 34];
			continue;
		}
		rep(j, 0, i) b[j] = 0;
		rep(j, 1, i - 1) b[sg[j - 1] ^ sg[i - j - 1]] = 1;
		while (b[sg[i]]) ++sg[i];
	}
	T = read();
	while (T--) {
		n = read();
		scanf("%s", c + 1);
		cnt[0] = cnt[1] = 0;
		rep(i, 1, n)++ cnt[c[i] == 'R'];
		int ans = 0;
		for (int l = 1, r; l <= n; l = r + 1) {
			r = l;
			while (r < n && c[r + 1] != c[r]) ++r;
			ans ^= sg[r - l + 1];
		}
		if (ans) ++cnt[1];
		if (cnt[1] > cnt[0])
			printf("Alice\n");
		else
			printf("Bob\n");
	}
}