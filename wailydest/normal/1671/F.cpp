#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <numeric>

const int md = 998244353;

inline int add(int a, int b) {
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int mul(int a, int b) {
	return (long long)a * b % md;
}
int po(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) {
	return po(a, md - 2);
}
inline int di(int a, int b) {
	return mul(a, inv(b));
}

const int N = 13;
int t, change[N][N][N], p[N], amt[N][N][N][N];
bool u[N];

void run(int sum, int cnt, int inv, int ch, int prod = 1) {
	amt[sum][cnt][inv][ch] = add(amt[sum][cnt][inv][ch], prod);
	for (int i = 2; i < N; ++i) for (int j = 1; j < N; ++j) for (int k = 1; k < N; ++k) if (change[i][j][k] && inv + j <= 11 && ch + k <= 11) run(sum + i - 1, cnt + 1, inv + j, ch + k, mul(prod, change[i][j][k]));
}

int calc(int n, int r) {
	int ans = 1;
	for (int i = 0; i < r; ++i) ans = mul(ans, n - i);
	for (int i = 2; i <= r; ++i) ans = di(ans, i);
	return ans;
}

int main() {
	for (int i = 2; i < N - 1; ++i) {
		std::iota(p, p + i, 0);
		do {
			bool ok = 1;
			memset(u, 0, i);
			for (int j = 0; j < i - 1 && ok; ++j) {
				ok = 0;
				u[p[j]] = 1;
				for (int k = 0; k <= j; ++k) if (!u[k]) ok = 1;
			}
			if (ok) {
				int inv = 0, chn = 0;
				for (int j = 0; j < i; ++j) {
					chn += j && p[j] < p[j - 1];
					for (int k = j + 1; k < i; ++k) inv += p[k] < p[j];
				}
				if (inv < N) ++change[i][inv][chn];
			}
		} while (std::next_permutation(p, p + i));
	}
	change[12][11][1] = 11;
	change[12][11][2] = 165;
	change[12][11][3] = 462;
	change[12][11][4] = 330;
	change[12][11][5] = 55;
	change[12][11][6] = 1;
	run(0, 0, 0, 0);
	scanf("%d", &t);
	while (t--) {
		int n, k, x;
		scanf("%d%d%d", &n, &k, &x);
		int ans = 0;
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (n - i >= j) if (amt[i][j][k][x]) ans = add(ans, mul(amt[i][j][k][x], calc(n - i, j)));
		printf("%d\n", ans);
	}
	return 0;
}