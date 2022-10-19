#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, mat[maxn][maxn], id[maxn][maxn], fa[maxn];
long long f[maxn][maxn], val[maxn][maxn], pre[maxn][maxn];
inline long long Solve(int l, int r) {
	if(l == r) {
		id[l][r] = l;
		return 0;
	}
	if(~f[l][r])
		return f[l][r];
	f[l][r] = 2e18;
	for(int rt = l; rt <= r; ++ rt) {
		long long ans = 0;
		if(rt > l)
			ans += Solve(l, rt - 1) + val[l][rt - 1];
		if(rt < r)
			ans += Solve(rt + 1, r) + val[rt + 1][r];
		if(f[l][r] > ans)
			f[l][r] = ans, id[l][r] = rt;
	}
	return f[l][r];
}
inline void Get(int l, int r) {
	if(l == r)
		return;
	int rt = id[l][r];
	if(rt > l) {
		int lrt = id[l][rt - 1];
		fa[lrt] = rt;
		Get(l, rt - 1);
	}
	if(rt < r) {
		int rrt = id[rt + 1][r];
		fa[rrt] = rt;
		Get(rt + 1, r);
	}
}
int main() {
	memset(f, -1, sizeof f);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			scanf("%d", &mat[i][j]), pre[i][j] = pre[i][j - 1] + mat[i][j];
	for(int l = 1; l <= n; ++ l)
		for(int r = l; r <= n; ++ r)
			for(int k = l; k <= r; ++ k)
				val[l][r] += pre[k][l - 1] + pre[k][n] - pre[k][r];
	long long ans = Solve(1, n);
	Get(1, n);
// cerr << ans << endl;
	for(int i = 1; i <= n; ++ i)
		printf("%d%c", fa[i], " \n"[i == n]);
}