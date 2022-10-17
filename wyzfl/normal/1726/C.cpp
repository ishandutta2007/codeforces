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
int st[N], match[N];
int T, n, ans, top;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		n *= 2;
		scanf("%s", c + 1);
		for (int i = 1; i <= n; i++) {
			if (c[i] == '(')
				st[++top] = i;
			else {
				match[st[top]] = i;
				match[i] = st[top];
				--top;
			}
		}
		ans = n / 2;
		for (int i = 1; i < n; i++) {
			if (c[i] == ')' && c[i + 1] == '(') --ans;
		}
		printf("%d\n", ans);
	}
}