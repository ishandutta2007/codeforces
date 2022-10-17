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

map<pii, int> mp;
int x[4], y[4], v[2][2];
int T, n;

signed main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		memset(v, 0, sizeof(v));
		mp.clear();
		n = read();
		rep(i, 0, 2) {
			x[i] = read();
			y[i] = read();
		}
		x[3] = read();
		y[3] = read();
		auto s = [&](int a, int b) {
			if (mp.count(make_pair(a, b))) return 1;
			return 0;
		};
		if (x[0] >= 3) {
			rep(i, 0, 3) x[i] = n - x[i] + 1;
		}
		if (y[0] >= 3) {
			rep(i, 0, 3) y[i] = n - y[i] + 1;
		}
		rep(i, 0, 2) mp[make_pair(x[i], y[i])] = 1;
		if (s(1, 1) && s(1, 2) && s(2, 1)) {
			if (x[3] == 1 || y[3] == 1)
				printf("YES\n");
			else
				printf("NO\n");
			continue;
		}
		rep(i, 0, 2) v[x[i] % 2][y[i] % 2] = 1;
		if (v[x[3] % 2][y[3] % 2])
			printf("YES\n");
		else
			printf("NO\n");
	}
}