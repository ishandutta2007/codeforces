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

int a[N], b[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		vector<int> vec[2];
		long long ans = 0;
		rep(i, 1, n) a[i] = read();
		rep(i, 1, n) b[i] = read(), vec[a[i]].push_back(b[i]), ans += b[i];
		if (vec[0].size() > vec[1].size()) swap(vec[0], vec[1]);
		if (vec[0].size() == vec[1].size()) {
			int minn = 1e9;
			rep(i, 1, n) minn = min(minn, b[i]);
			printf("%lld\n", ans * 2 - minn);
			continue;
		}
		for (auto i: vec[0]) ans += i;
		sort(vec[1].begin(), vec[1].end());
		reverse(vec[1].begin(), vec[1].end());
		rep(i, 0, (int)vec[0].size() - 1) ans += vec[1][i];
		printf("%lld\n", ans);
	}
}