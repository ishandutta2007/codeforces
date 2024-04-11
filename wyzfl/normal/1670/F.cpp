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

const int P = 1e9 + 7;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

int C[1005][1005], f[2005][2], g[2005][2];
int n;
long long l, r, z;

int calc(int n, long long x, long long z) {
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int b = 0; b <= 60; b++) {
		memset(g, 0, sizeof(g));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 1; j++) {
				int val = add(f[i * 2][j], f[i * 2 + 1][j]);
				if (!val) continue;
				for (int k = 0; k <= n; k++) {
					if ((k & 1) == ((z >> b) & 1)) {
						int go = (i + k) & 1;
						if (go == ((x >> b) & 1)) go = j;
						g[i + k][go] = add(g[i + k][go], mul(C[n][k], val));
					}
				}
			}
		}
		memcpy(f, g, sizeof(f));
	}
	return f[0][0];
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	cin >> n >> l >> r >> z;
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}
	printf("%d\n", sub(calc(n, r, z), calc(n, l - 1, z)));
}