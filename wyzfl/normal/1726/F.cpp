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

set<pair<int, long long> > all;
int g[N], c[N], d[N], l[N], r[N];
int n, t;
long long ans = 1e18, sum;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	t = read();
	for (int i = 1; i <= n; i++) {
		g[i] = read();
		c[i] = read();
	}
	for (int i = 1; i < n; i++) {
		d[i] = read();
		sum += d[i];
		d[i] = (d[i - 1] + d[i]) % t;
	}
	for (int i = 1; i <= n; i++) {
		l[i] = g[i];
		r[i] = 0;
		l[i] += t - c[i];
		r[i] += t - c[i];
		l[i] %= t;
		r[i] %= t;
		l[i] = (l[i] - d[i - 1] + t) % t;
		r[i] = (r[i] - d[i - 1] + t) % t;
		all.insert(make_pair((l[i] + t - 1) % t, 0));
		all.insert(make_pair(r[i], 0));
		// fprintf(stderr, "l = %d, r = %d\n", l[i], r[i]);
	}
	for (int i = 1; i <= n; i++) {
		long long minn = ans;
		if (l[i] <= r[i]) {
			while (1) {
				auto it = all.lower_bound(make_pair(l[i], 0));
				if (it != all.end() && it->first <= r[i]) {
					minn = min(minn, it->second + (r[i] - it->first));
					all.erase(it);
				} else
					break;
			}
		} else {
			while (1) {
				auto it = all.lower_bound(make_pair(l[i], 0));
				if (it != all.end()) {
					minn = min(minn, it->second + (r[i] + t - it->first));
					all.erase(it);
				} else
					break;
			}
			while (all.size()) {
				auto it = all.begin();
				if (it->first <= r[i]) {
					minn = min(minn, it->second + (r[i] - it->first));
					all.erase(it);
				} else
					break;
			}
		}
		if (minn != ans) all.insert(make_pair(r[i], minn));
	}
	for (auto i: all) ans = min(ans, i.second);
	printf("%lld\n", ans + sum);
}