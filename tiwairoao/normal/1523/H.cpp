#include <bits/stdc++.h>

const int K = 31;
const int N = 20000;

inline void chkmax(short int &x, const short int &y) {x = std::max(x, y);}

short int st[15][K][14][N + 5];
int lg[N + 5], a[N + 5], n, lgn;

short int rmq(const int &x, const int &y, const int &l, const short int &r) {
	int p = lg[r - l + 1], q = (1 << p);
	if (p == 14) {
		return std::max(std::max(st[x][y][13][l], st[x][y][13][l + 8192]),
			std::max(st[x][y][13][r - 16383], st[x][y][13][r - 8191]));
	} else {
		return std::max(st[x][y][p][l], st[x][y][p][r - q + 1]);
	}
}
void build_st(const int &x, const int &y) {
	for (int j = 1; j < lgn && j < 14; j++) {
		int t = (1 << (j - 1));
		for (int i = 1; i + t <= n; i++)
			st[x][y][j][i] = std::max(st[x][y][j - 1][i], st[x][y][j - 1][i + t]);
	}
}

void build() {
	for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;

	lgn = lg[n] + 1;	
	for (int k = 0; k < K; k++) {
		for (int i = 1; i <= n; i++) st[0][k][0][i] = std::min(i + a[i] + k, n);
		build_st(0, k);
	}
	for (int j = 1; j < lgn; j++) {
		for (int k = 0; k < K; k++) {
			for (int p = 0; p <= k; p++) for (int i = 1; i <= n; i++)
				chkmax(st[j][k][0][i], rmq(j - 1, p, i, st[j - 1][k - p][0][i]));
			build_st(j, k);
		}
	}
}

int query(int l, int r, int k) {
	if (l == r) return 0;

	int ans = 0; static short int f[K];
	for (int i = 0; i <= k; i++) f[i] = l;
	for (int j = lgn - 1; j >= 0; j--) {
		short int x = -1;
		for (int i = 0; i <= k; i++) chkmax(x, rmq(j, i, l, f[i]));
		if (x < r) {
			ans |= (1 << j);
			for (int i = 0; i <= k; i++) {
				x = -1;
				for (int p = k; p >= i; p--)
					chkmax(x, rmq(j, p - i, l, f[p]));
				f[i] = x;
			}
		}
	}
	return ans + 1;
}

int main() {
	int q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build();

	for (int i = 1, l, r, k; i <= q; i++) {
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", query(l, r, k));
	}
}