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

#define ll long long
#define vi vector <int>
#define size(v) (int(v.size()))
const int MAXN = 100100, lim = 1e5;

vi d[MAXN];
int pr[MAXN], tp, mu[MAXN]; bool np[MAXN];
void sieve () {
	int i, j; mu[1] = 1;
	for (i = 2; i <= lim; i++) {
		if (!np[i]) pr[++tp] = i, mu[i] = -1;
		for (j = 1; j <= tp; j++) if (i * pr[j] <= lim) {
			np[i * pr[j]] = 1;
			if (i % pr[j] == 0) { mu[i * pr[j]] = 0; break; }
			mu[i * pr[j]] = -mu[i];
		} else break;
	}
	for (i = 1; i <= lim; i++) for (j = i; j <= lim; j += i) d[j].push_back(i);
}

ll ans;
int n, a[MAXN]; bool vis[MAXN];

int cur[MAXN], s[MAXN], top;
bool chk (int x) {
	int ret = 0;
	for (auto i: d[x]) ret += cur[i] * mu[i];
	return ret;
}
ll solve (vi &v) {
	reverse(v.begin(), v.end()); int i, j;
	ll ret = 0;
	for (auto x: v) {
		int las = 0;
		while (chk(x)) {
			for (auto i: d[s[top]]) --cur[i];
			las = s[top--];
		}
		ret = max(ret, 1ll * x * las);
		for (auto i: d[x]) ++cur[i];
		s[++top] = x;
	}
	while (top) { for (auto i: d[s[top]]) --cur[i]; --top; }
	return ret;
}
vi v[MAXN];

int main () {
	sieve(); n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read(), vis[a[i]] = 1;
	sort(a + 1, a + n + 1); n = unique(a + 1, a + n + 1) - a - 1; ans = a[n];
	for (i = 1; i <= lim; i++) for (j = i; j <= lim; j += i) if (vis[j]) v[i].push_back(j / i);
	for (i = 1; i <= lim; i++) if (size(v[i]) >= 2)
		ans = max(ans, solve(v[i]) * i);
	printf("%lld\n", ans);
	return 0;
}