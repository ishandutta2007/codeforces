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

const int N = 1e5 + 5;

int a[N];
int T, n, m;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		int m = read(), n = read();
		rep(i, 1, n) a[i] = read();
		sort(a + 1, a + n + 1);
		vector<int> seq;
		for (int i = 1; i < n; i++) seq.push_back(a[i + 1] - a[i] - 1);
		seq.push_back(m - a[n] + a[1] - 1);
		sort(seq.begin(), seq.end());
		reverse(seq.begin(), seq.end());
		int ans = 0;
		for (int i = 0; i < (int)seq.size(); i++) {
			int len = seq[i] - 2 * 2 * i;
			if (len <= 0) break;
			if (len == 1) {
				++ans;
				break;
			}
			ans += (len - 1);
		}
		printf("%d\n", m - ans);
	}
}