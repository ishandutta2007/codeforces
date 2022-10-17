#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 101000;
vector <int> E[MAXN];
int n, a[MAXN], dep[MAXN];

#define ll long long
ll ans = 0;

bool dfs (int x, int fa) {
	dep[x] = dep[fa] + 1;
	if ((dep[x] & 1) && a[x] == -1) return 0;
	if (!(dep[x] & 1) && a[x] != -1) return 0;
	if (dep[x] & 1) {
		for (auto i: E[x]) if (!dfs(i, x)) return 0;
		return 1;
	}
	else {
		int tmp = 1e9 + 7;
		for (auto i: E[x]) {
			if (a[i] < a[fa]) return 0;
			tmp = min(tmp, a[i]);
		}
		if (tmp > 1e9) tmp = a[fa];
		ans += tmp - a[fa];
		for (auto i: E[x]) {
			ans += a[i] - tmp;
			if (!dfs(i, x)) return 0;
		}
	}
	return 1;
}

int main () {
	n = read(); int i, j;
	for (i = 2; i <= n; i++) j = read(), E[j].push_back(i);
	for (i = 1; i <= n; i++) a[i] = read();
	if (!dfs(1, 0)) { puts("-1"); return 0; }
	ans += a[1];
	printf("%lld\n", ans);
	return 0;
}