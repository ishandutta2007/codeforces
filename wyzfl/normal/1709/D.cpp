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

const int N = 2e5 + 5;

int a[N], st[N][19], lg[N];
int n, m, q;

int query(int l, int r) {
	int k = lg[r - l + 1];
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	rep(i, 1, m) a[i] = read(), st[i][0] = a[i];
	lg[0] = -1;
	rep(i, 1, m) lg[i] = lg[i >> 1] + 1;
	rep(j, 1, 18) rep(i, 1, m - (1 << j) + 1) st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	q = read();
	while (q--) {
		int a = read(), b = read(), c = read(), d = read(), k = read();
		swap(a, b);
		swap(c, d);
		if ((a - c) % k != 0 || (b - d) % k != 0) {
			printf("NO\n");
			continue;
		}
		int pos = (n - b) / k * k + b;
		if (a > c) swap(a, c);
		if (query(a, c) < pos)
			printf("YES\n");
		else
			printf("NO\n");
	}
}