#include<bits/stdc++.h>

const int N = 60;

double inv[N];
int a[N];
double dp[N];

int main(){
	inv[0] = 1.0;
	for (int i = 1; i < N; ++ i){
		inv[i] = inv[i - 1] / i;
	}
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++ i){
		scanf("%d", &a[i]);
	}
	double ans = 0, preans = 0;
	for (int i = 1; i <= n; ++ i){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1.0;
		for (int j = 0; j < m; ++ j){
			for (int k = n; k >= 0; -- k){
				for (int u = 1, sz = std::min(n - k, i * a[j]); u <= sz; ++ u){
					dp[k + u] += dp[k] * inv[u];
				}
			}
		}
		ans += i * (dp[n] - preans);
		preans = dp[n];
	}
	for (int i = 1; i <= n; ++ i){
		ans *= i;
		ans /= m;
	}
	return printf("%.12lf\n", ans), 0;
}