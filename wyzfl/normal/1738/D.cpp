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

vector<int> vec[N];
int a[N], b[N];
int T, n, k, len;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		rep(i, 0, n + 1) vec[i].clear();
		k = 0;
		rep(i, 1, n) {
			b[i] = read();
			vec[b[i]].push_back(i);
			if (b[i] > i) k = i;
		}
		int now = 0;
		if (vec[n + 1].size()) now = n + 1;
		len = 0;
		while (len < n) {
			int tmp = 0;
			for (auto i: vec[now]) {
				if (vec[i].size()) {
					tmp = i;
				} else {
					a[++len] = i;
				}
			}
			if (tmp) a[++len] = tmp, now = tmp;
		}
		printf("%d\n", k);
		rep(i, 1, n) printf("%d%c", a[i], i == n ? '\n' : ' ');
	}
}