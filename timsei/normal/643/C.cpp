#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 211111;
const int Kk = 55;

int n, k, T[N], S[N];
double dp[Kk][N], fo[N], K[N];

double get(int a, int b) {
	return (S[b] - S[a - 1]) * fo[b] - K[b] + K[a - 1];
}

void solve(int x, int l, int r, int ml, int mr) {
	if(l > r) return;
	int mid = (l + r) >> 1;
	int it = 0;
	double ans = 1e18, res;
	for(int i = ml; i <= min(mr, mid - 1); ++ i) {
		if((res = dp[x - 1][i] + get(i + 1, mid)) < ans) {
			ans = res; it = i;
		}
	}
	dp[x][mid] = ans;
	solve(x, l, mid - 1, ml, it);
	solve(x, mid + 1, r, it, mr);
}

main(void) {
	scanf("%lld%lld",&n, &k);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &T[i]);
	for(int i = 1; i <= n; ++ i) {
		S[i] = S[i - 1] + T[i];
		fo[i] = fo[i - 1] + (1.0) / T[i];
		dp[1][i] = dp[1][i - 1] + (double)S[i] / (double)T[i];
	}
	
	for(int i = 1;i <= n; ++ i) {
		K[i] = K[i - 1] + fo[i - 1] * T[i];
	}
	
	double zrf = dp[1][n];
	
	for(int i = 2; i <= k; ++ i) 
	solve(i, 1, n, 1, n), zrf = min(zrf, dp[i][n]);
	printf("%.12lf\n", zrf);
}