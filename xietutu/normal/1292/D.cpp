#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

int vis[N + 5], p[N + 5], pn, n;
int f[705][5005];
long long ans, Ans;
int val[5005], dep[5005], num[5005];
int Max[5005], Num[5005];

void work(int l, int r) {		
	int mmax = 0, Maxt = -1;
	for (int i = l; i <= r; ++ i) {
		int j;
		for (j = i; j + 1 <= r && Max[j + 1] == Max[j]; ++ j);
		if (Num[j] - Num[i - 1] > mmax) mmax = Num[j] - Num[i - 1], Maxt = i;
	}
		
	if (mmax == 0) return;
//	printf("get %d\n", mmax);
	
	ans -= mmax;
	ans += n - mmax;
	
	if (ans < Ans) Ans = ans; 

	
	int i = Maxt, j;
	for (j = i; j + 1 <= r && Max[j + 1] == Max[j]; ++ j);
	
//	printf("%d %d\n", i, j);
	
	int tt = Maxt;
	for (int k = i; k <= j; ++ k) {
		-- num[k];
		if (num[k] == 0) {
			-- Max[k];
			if (Max[k] == 0) {
				tt = k + 1;
			} else {
				num[k] = f[Max[k]][k];
			}
		}
	}
	if (tt <= r) {
		work(tt, r);
	}
}

int main() {
	
//	freopen("C.in", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int x; scanf("%d", &x);
		++ val[x];
	}
	
	for (int i = 2; i <= N; ++ i) {
		if (!vis[i]) p[++ pn] = i;
		for (int j = i + i; j <= N; j += i)
			vis[j] = 1;
	}
	
	for (int i = 1; i <= pn; ++ i) {
		for (int j = 1; j <= N; ++ j) {
			f[i][j] = f[i][j / p[i]] + j / p[i];
		}
	}
	for (int i = 1; i <= N; ++ i)
		for (int j = 1; j <= pn; ++ j) dep[i] += f[j][i];
	
	for (int i = 2; i <= 5000; ++ i) {
		for (int t = 1; t <= pn; ++ t)
			if (p[t] <= i) {
				Max[i] = t;
				num[i] = f[t][i];
			}
	}
	
	Num[0] = val[0];
	for (int i = 1; i <= 5000; ++ i) Num[i] = Num[i - 1] + val[i];
	
	for (int i = 0; i <= 5000; ++ i) ans += 1ll * val[i] * dep[i];
	Ans = ans;
	
//	printf("%d\n", ans);
	
	work(2, 5000);
	printf("%lld\n", Ans);
	return 0;
}