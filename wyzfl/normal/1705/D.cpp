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

char a[N], b[N];
int la[N], ra[N], lb[N], rb[N];
int T, n, lena, lenb;

void solve(char* c, int* l, int* r, int& len) {
	len = 0;
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		if (c[j] == '0') continue;
		while (j < n && c[j + 1] == '1') ++j;
		++len;
		l[len] = i;
		r[len] = j;
	}
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		scanf("%s%s", a + 1, b + 1);
		if (a[1] != b[1] || a[n] != b[n]) {
			printf("-1\n");
			continue;
		}
		solve(a, la, ra, lena);
		solve(b, lb, rb, lenb);
		if (lena != lenb) {
			printf("-1\n");
			continue;
		}
		long long ans = 0;
		for (int i = 1; i <= lena; i++) {
			ans += abs(la[i] - lb[i]);
			ans += abs(ra[i] - rb[i]);
		}
		printf("%lld\n", ans);
	}
}