#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 50050;
int n, a[MAXN];

vector <pair <int, int>> ans;
void op(int i, int j) {
	ans.push_back({a[i], a[j]});
	int p = a[i] + a[j], q = abs(a[i] - a[j]);
	a[i] = q, a[j] = p;
}

void simplify(int l, int r, int K) {
	// printf("simp %d %d %d\n", l, r, K);
	if (l == r) return;
	int N = 1; while (N < r - l + 1) N <<= 1;
	int i, j;
	sort(a + l, a + r + 1);
	// for (i = l; i <= r; i++) cout << a[i] << ' '; cout << endl;
	if (a[l] == N * K) return;
	for (i = l; i <= r; i++) if (!a[i]) {
		for (j = l; j <= r; j++) if (i != j) {
			while (a[j] != N * K) op(i, j);
		}
		op(i, l + (i == l)); return;
	}
	for (i = l; i < r; i++) if (a[i] != N * K && a[i] == a[i + 1]) {
		op(i, i + 1);
		for (j = l; j <= r; j++) if (i != j) {
			while (a[j] != N * K) op(i, j);
		}
		op(i, i + 1); return;
	}
	while (a[l + 1] != a[l + 2]) op(l, l + 1);
	for (i = l; i < r; i++) if (a[i] != N * K && a[i] == a[i + 1]) {
		op(i, i + 1);
		for (j = l; j <= r; j++) if (i != j) {
			while (a[j] != N * K) op(i, j);
		}
		op(i, i + 1); return;
	}
	assert(0); return;
}

void spi(int l, int r);
void sp(int l, int r) {
	if (l == r) return;
	sort(a + l, a + r + 1);
	if (r - l + 1 == 3) { op(l, r), op(l, l + 1), op(l, l + 1); return; }
	int mid = (l + r) >> 1, K = a[l + 1] - a[l];
	for (int i = l, j = r; i < j; i++, j--) op(j, i);
	spi(mid + 1, r);
	simplify(l, r, K);
}
void spi(int l, int r) {
	if (l == r) return;
	sort(a + l, a + r + 1);
	int mid = (l + r) >> 1, K = a[l + 1] - a[l];
	for (int i = l, j = r; i < j; i++, j--) op(j, i);
	spi(mid + 1, r);
}

inline bool lowbit(int x) { return (x & -x) == x; }
void solve(int l, int r) {
	if (r - l + 1 <= 2) return;
	const int _l = l, _r = r;
	int i, j;
	sort(a + l, a + r + 1);
	for (i = l + 1; i < r; i++) assert(a[i] - a[i - 1] == a[i + 1] - a[i]);
	int K = a[l + 1] - a[l];
	int N = 1; while (N < r - l + 1) N <<= 1;
	while (a[r] == N * K) --r;
	if (l < r) {
		if (lowbit(r - l + 1 + 1)) sp(l, r);
		else {
			for (i = r, j = N - (r - l + 1) + (l - 1); i > j; i--, j++) op(i, j);
			if (lowbit(r - l + 1 + 2)) {
				int mid = ((l + r) >> 1) + 1;
				for (i = mid + 1; i <= r; i++) if (a[mid] == a[i]) {
					const int tmp = a[mid]; op(i, mid);
					while (a[i] != tmp) op(l, i);
					solve(mid + 1, r); break;
				}
			}
			else {
				solve(i + 1, r);
				solve(l, N - (r - l + 1) + (l - 1) - 1);
			}
		}
	}
	simplify(_l, _r, K);
}

int main() {
	int T = read(); while (T--) {
		n = read(); int i, j;
		if (n == 1) { puts("0"); continue; }
		if (n == 2) { puts("-1"); continue; }
		for (i = 1; i <= n; i++) a[i] = i;
		solve(1, n);
		// for (i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
		for (i = 1; i < n; i++) assert(a[i] == a[i + 1]);
		printf("%d\n", ans.size());
		assert(int(ans.size()) <= n * 20);
		for (auto i: ans) printf("%d %d\n", i.first, i.second);
		ans.clear();
	}
	return 0;
}