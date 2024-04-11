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

set<pii> all;
int a[N];
int n, q;

void ins(int l, int r) {
	auto it = all.lower_bound(make_pair(l, r));
	if (it != all.end() && it->first == r + 1) {
		r = it->second;
		all.erase(it);
	}
	it = all.lower_bound(make_pair(l, r));
	if (it != all.begin()) {
		--it;
		if (it->second == l - 1) {
			l = it->first;
			all.erase(it);
		}
	}
	all.insert(make_pair(l, r));
}

void add(int x) {
	auto it = all.lower_bound(make_pair(x + 1, 0));
	if (it == all.begin()) {
		ins(x, x);
		return;
	}
	--it;
	if (it->second < x) {
		ins(x, x);
		return;
	}
	int l = it->first, r = x - 1, val = it->second + 1;
	all.erase(it);
	if (l <= r) ins(l, r);
	ins(val, val);
}

void del(int x) {
	auto it = all.lower_bound(make_pair(x + 1, 0)), it2 = it;
	if (it != all.begin()) --it2;
	if (it == all.begin() || it2->second < x) {
		int l = x, r = it->first - 1;
		int L = it->first + 1, R = it->second;
		all.erase(it);
		ins(l, r);
		if (L <= R) ins(L, R);
		return;
	}
	int l = it2->first, r = x - 1;
	int L = x + 1, R = it2->second;
	all.erase(it2);
	if (l <= r) ins(l, r);
	if (L <= R) ins(L, R);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	q = read();
	rep(i, 1, n) a[i] = read(), add(a[i]);
	rep(i, 1, q) {
		int x = read(), y = read();
		del(a[x]);
		a[x] = y;
		add(a[x]);
		printf("%d\n", (--all.end())->second);
	}
}