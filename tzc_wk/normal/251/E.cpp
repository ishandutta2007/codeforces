#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN = 2e5;
const int MOD = 1e9 + 7;
int n, deg[MAXN + 5], rt, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
vector<int> vec[MAXN + 5]; int siz[MAXN + 5], bel[MAXN + 5], dp[MAXN + 5], dep[MAXN + 5];
void dfs(int x, int f) {
	siz[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue; vec[x].pb(y); dfs(y, x);
		siz[x] += siz[y]; bel[x] = bel[y]; dep[x] = dep[y] + 1;
	}
	sort(vec[x].begin(), vec[x].end()); if (vec[x].size() == 2) bel[x] = x, dep[x] = 0;
}
int calc1(int x);
int calc2(int x, int y) {
	if (!x || !y) return calc1(x + y);
	if ((siz[x] + siz[y]) & 1) return 0;
	if (vec[x].size() >= 2 || vec[y].size() >= 2) return 0;
	if (vec[x].size() == 1 && vec[y].size() == 1) return calc2(vec[x][0], vec[y][0]);
	else if (vec[x].size() == 0 && vec[y].size() == 0) return 1;
	else if (vec[x].size() == 1 && vec[y].size() == 0) return calc1(vec[x][0]);
	else if (vec[x].size() == 0 && vec[y].size() == 1) return calc1(vec[y][0]);
	return 0;
}
int calc1(int x) {
	if (~dp[x]) return dp[x];
	if (!x) return 1; if (siz[x] & 1) return 0;
	if (!bel[x]) return siz[x] / 2; int ans = 0;
	int L = vec[bel[x]][0], R = vec[bel[x]][1];
	for (int i = 0; i < 2; i++) {
		swap(L, R);
		if (vec[R].size() == 1) ans = (ans + calc2(L, vec[R][0])) % MOD;
		if (!bel[R] && dep[R] <= dep[x]) ans = (ans + 1ll * calc1(L) * ((dep[R] != dep[x]) + 1)) % MOD;
		if (vec[R].size() == 2) {
			if (!bel[vec[R][0]] && dep[vec[R][0]] <= dep[x]) ans = (ans + calc2(L, vec[R][1])) % MOD;
			if (!bel[vec[R][1]] && dep[vec[R][1]] <= dep[x]) ans = (ans + calc2(L, vec[R][0])) % MOD;
		}
	}
	return dp[x] = ans;
}
int main() {
	scanf("%d", &n); n <<= 1;
	if (n == 2) return puts("2"), 0;
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), deg[u]++, deg[v]++, adde(u, v), adde(v, u);
	for (int i = 1; i <= n; i++) {
		if (deg[i] >= 4) return puts("0"), 0;
		if (deg[i] == 3) rt = i;
	}
	if (!rt) return printf("%d\n", (2ll * (n / 2) * (n / 2) - n + 4) % MOD), 0;
	dfs(rt, 0); memset(dp, -1, sizeof(dp)); int res = 0;
	do {
		int A = vec[rt][0], B = vec[rt][1], C = vec[rt][2]; if (vec[B].size() >= 3) continue;
		if (vec[B].empty()) res = (res + 1ll * calc1(A) * calc1(C)) % MOD;
		else if (vec[B].size() == 1) res = (res + 1ll * calc1(A) * calc2(C, vec[B][0]) + 1ll * calc1(C) * calc2(A, vec[B][0])) % MOD;
		else res = (res + 1ll * calc2(A, vec[B][0]) * calc2(C, vec[B][1]) + 1ll * calc2(A, vec[B][1]) * calc2(C, vec[B][0])) % MOD;
	} while (next_permutation(vec[rt].begin(), vec[rt].end()));
	printf("%d\n", 2ll * res % MOD);
	return 0;
}