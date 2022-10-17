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

const int N = 1005;

pii st[N * 2], tmp[N * 2];
char c[N][N];
int a[N][N], dp[N][N], mx[N][N], ans[N][N], xx[N * 2], yy[N * 2];
int T, n, k, top, len;

bool cmp(pii a, pii b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		k = read();
		--k;
		rep(i, 1, n) {
			scanf("%s", c[i] + 1);
			rep(j, 1, n) a[i][j] = c[i][j] - '0', ans[i][j] = 0;
		}
		int maxn = 0;
		rep(i, 1, n) rep(j, 1, n) {
			dp[i][j] = 0;
			if (a[i][j] == 0) {
				dp[i][j] = mx[i - 1][j - 1] + 1;
			}
			mx[i][j] = max(max(mx[i - 1][j], mx[i][j - 1]), dp[i][j]);
			maxn = max(maxn, dp[i][j]);
		}
		if (maxn > k) {
			printf("No\n");
			continue;
		}
		rep(i, 1, k) {
			rep(j, n - k + i, n) {
				ans[i][j] = ans[j][i] = 1;
				a[i][j] = a[j][i] = 1;
			}
		}
		xx[n] = yy[n] = 1;
		rep(i, 2, n) xx[i + n - 1] = 1, yy[i + n - 1] = i;
		rep(i, 2, n) xx[n - i + 1] = i, yy[n - i + 1] = 1;
		rep(i, 1, k) {
			int x = i, y = n - k + i;
			int gx = n - k + i, gy = i;
			ans[gx][gy] = 0;
			auto go = [&](int tx, int ty) {
				while (x != tx || y != ty) {
					if (y - 1 >= ty && !ans[x][y - 1]) {
						--y;
					} else {
						++x;
					}
					ans[x][y] = 1;
				}
			};
			len = 0;
			for (int j = y - x + n; j >= gy - gx + n; j--) {
				while (xx[j] <= n && yy[j] <= n && a[xx[j]][yy[j]] == 1) ++xx[j], ++yy[j];
				if (xx[j] <= n && yy[j] <= n && xx[j] >= x && xx[j] <= gx && yy[j] <= y && yy[j] >= gy) {
					tmp[++len] = make_pair(xx[j], yy[j]);
				}
			}
			top = 0;
			sort(tmp + 1, tmp + len + 1, cmp);
			for (int j = 1; j <= len; j++) {
				if (top && tmp[j].first > st[top].first && tmp[j].second > st[top].second) continue;
				st[++top] = tmp[j];
			}
			for (int j = top; j >= 1; j--) {
				go(st[j].first, st[j].second);
				++xx[st[j].second - st[j].first + n];
				++yy[st[j].second - st[j].first + n];
			}
			go(gx, gy);
		}
		printf("Yes\n");
		rep(i, 1, n) {
			rep(j, 1, n) printf("%d", ans[i][j]);
			printf("\n");
		}
	}
}