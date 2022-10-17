#include <cstdio>
#include <vector>

const int INF = 1070000000;

const int N = 200000;
int n, a[N], size, cnt[N], start[N], d[3][N][2], id[N];
long long ans = 0;

void upd(int *d, int *pr, int cur, int prev) {
	d[0] = -INF;
	d[1] = INF;
	if (prev < cur) d[0] = pr[0];
	else d[1] = pr[1];
	if (pr[1] < cur) d[0] = std::max(d[0], prev);
	if (pr[0] > cur) d[1] = std::min(d[1], prev);
}

bool ok(int *d) {
	return d[0] != -INF || d[1] != INF;
}

void calc(int l, int r) {
	if (r - l == 1) ans += (long long)(cnt[l] - 1) * cnt[l] / 2;
	else {
		int m = l + r >> 1, p = start[m];
		for (int t = 0; t < 3; ++t) {
			if (!t) {
				d[t][p][0] = a[p - 1];
				d[t][p][1] = INF;
				d[t][p - 1][0] = a[p];
				d[t][p - 1][1] = INF;
			} else if (t == 1) {
				d[t][p][1] = a[p - 1];
				d[t][p][0] = -INF;
				d[t][p - 1][1] = a[p];
				d[t][p - 1][0] = -INF;
			} else {
				if (a[p] < a[p - 1]) {
					d[t][p][1] = a[p - 2];
					d[t][p][0] = -INF;
					d[t][p - 1][0] = INF;
					d[t][p - 1][1] = INF;
				} else {
					d[t][p][0] = a[p - 2];
					d[t][p][1] = INF;
					d[t][p - 1][0] = -INF;
					d[t][p - 1][1] = -INF;
				}
			}
			for (int i = p; i < n && id[i] < r; ++i) {
				if (i != p) upd(d[t][i], d[t][i - 1], a[i], a[i - 1]);
			}
			for (int i = p - 2; i >= 0 && id[i] >= l; --i) upd(d[t][i], d[t][i + 1], a[i], a[i + 1]);
		}
		for (int i = p - 2, j = start[r] - 1; i >= 0 && id[i] >= l; --i) {
			while (true && j >= p) {
				bool good = 0;
				for (int t = 0; t < 3; ++t) if (ok(d[t][i]) && ok(d[t][j])) good = 1;
				if (!good) --j;
				else break;
			}
			if (j < p) break;
			ans += j - p + 1;
		}
		d[0][p - 1][0] = INF;
		d[0][p - 1][1] = -INF;
		for (int i = p; i < start[r]; ++i) {
			upd(d[0][i], d[0][i - 1], a[i], a[i - 1]);
			ans += ok(d[0][i]);
		}
		calc(l, m);
		calc(m, r);
	}
}

int sign(int x) {
	if (x > 0) return 1;
	return 0;
}

int main() {
	scanf("%d", &n);
	ans = n;
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++size) {
		start[size] = i;
		id[i] = size;
		++cnt[size];
		++i;
		if (i < n) {
			do {
				++cnt[size];
				id[i] = size;
				++i;
			} while (i < n && sign(a[i] - a[i - 1]) == sign(a[i - 1] - a[i - 2]));
		}
	}
	start[size] = n;
	calc(0, size);
	printf("%lld\n", ans);
	return 0;
}