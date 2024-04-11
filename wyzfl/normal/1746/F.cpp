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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 5, M = 64;

int f[M][N], a[N];
int n, q;
u64 seed;

void add(int i, int j, int k) {
	while (j <= n) {
		f[i][j] += k;
		j += (j & -j);
	}
}

int query(int i, int j) {
	int ans = 0;
	while (j) {
		ans += f[i][j];
		j &= (j - 1);
	}
	return ans;
}

u64 xor_shift(u64 x) {
	x ^= (x << 17);
	x ^= (x >> 13);
	x ^= (x << 5);
	return x;
}

void add(int i, int v) {
	u64 val = xor_shift(a[i] ^ seed);
	for (int j = 0; j < 64; j++) {
		if ((val >> j) & 1) {
			add(j, i, v);
		}
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	seed = rng();
	n = read();
	q = read();
	rep(i, 1, n) a[i] = read(), add(i, 1);
	while (q--) {
		int opt = read();
		if (opt == 1) {
			int i = read(), x = read();
			add(i, -1);
			a[i] = x;
			add(i, 1);
		}
		if (opt == 2) {
			int l = read(), r = read(), k = read(), ans = 1;
			for (int i = 0; i < 64; i++) {
				if ((query(i, r) - query(i, l - 1)) % k) {
					ans = 0;
					break;
				}
			}
			printf("%s\n", ans ? "YES" : "NO");
		}
	}
}