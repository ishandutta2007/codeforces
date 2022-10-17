#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define int long long
#define size(v) ((int)v.size())
const int inf = 10004205361450474;

inline int ask (vector <int> v) {
	printf("%lld ", size(v));
	for (auto i: v) printf("%lld ", i);
	putchar('\n'); fflush(stdout);
	int ret; scanf("%lld", &ret); 
	if (ret == -1) exit(0);
	return ret;
}

int f[10100][6]; bool vis[10010][6];
int calc (int lim, int left) {
	lim = min(lim, 10000ll);
	if (left == 1) return lim;
	if (vis[lim][left]) return f[lim][left];
	vis[lim][left] = 1; f[lim][left] = calc(lim, left - 1);
	for (int i = 1; i <= lim; i++) {
		if (lim + f[lim][left] + 1 >= 10000) { f[lim][left] += (lim - i + 1) * (1 + calc(10000ll, left - 1)); break; }
		f[lim][left] += 1 + calc(min(lim + f[lim][left] + 1, 10000ll), left - 1);
	}
	return f[lim][left];
}

void solve (int lim, int left) {
	vector <int> v;
	if (left == 1) {
		for (int i = 1; i <= min(lim, 10000ll); i++) if (i + lim - 1 <= inf) v.push_back(i + lim - 1); else break;
		ask(v); return;
	}
	int now = calc(lim, left - 1);
	for (int i = 1; i <= min(lim, 10000ll); i++) {
		v.push_back(lim + now);
		now += 1 + calc(lim + now + 1, left - 1);
	}
	int res = ask(v);
	if (!res) solve(lim, left - 1);
	else solve(v[res - 1] + 1, left - 1);
}

signed main () {
	solve(1, 5);
	return 0;
}