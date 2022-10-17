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

char c[N];
int seq[N];
int T, n, len;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		scanf("%s", c + 1);
		n = strlen(c + 1);
		int cnt[2] = { 0, 0 };
		len = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == '(') ++cnt[0];
			if (c[i] == ')') ++cnt[1];
			if (c[i] == '?') seq[++len] = i;
		}
		if (cnt[0] == n / 2 || cnt[1] == n / 2) {
			printf("YES\n");
			continue;
		}
		for (int i = 1; i <= n / 2 - cnt[0]; i++) c[seq[i]] = '(';
		for (int i = n / 2 - cnt[0] + 1; i <= len; i++) c[seq[i]] = ')';
		swap(c[seq[n / 2 - cnt[0]]], c[seq[n / 2 - cnt[0] + 1]]);
		int sum = 0, ans = 0;
		rep(i, 1, n) {
			sum += (c[i] == '(' ? 1 : -1);
			if (sum < 0) {
				ans = 1;
				break;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
}