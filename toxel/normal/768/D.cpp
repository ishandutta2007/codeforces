#include<bits/stdc++.h>
#define ll long long

const double eps = 1e-7;
const int N = 1010;

int k, q;
double dp[2][N], p[N << 3];

int main(){
	scanf("%d%d", &k, &q);
	dp[0][1] = 1;
	p[1] = k == 1;
	int now = 1, pre = 0;
	for (int i = 2; ; ++ i){
		memset(dp[now], 0, sizeof(dp[now]));
		for (int j = 1; j <= k; ++ j){
			dp[now][j + 1] += dp[pre][j] * (k - j) / k;
			dp[now][j] += dp[pre][j] * j / k;
		}
		p[i] = dp[now][k];
		if (p[i] - 0.5 > -eps){
			break;
		}
		now ^= 1;
		pre ^= 1;
	}
	for (int i = 0, x; i < q; ++ i){
		scanf("%d", &x);
		for (int j = 1; ; ++ j){
			if (p[j] * 2000 - x > -eps){
				printf("%d\n", j);
				break;
			}
		}
	}
	return 0;
}