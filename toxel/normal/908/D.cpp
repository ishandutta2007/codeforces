#include<bits/stdc++.h>

const int moder = 1e9 + 7;
const int N = 1010;

int dp[N][N];

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * a * ret % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int main(){
	int kk, pa, pb;
	scanf("%d%d%d", &kk, &pa, &pb);
	int now = 1;
	dp[1][0] = 1;
	int ans = 0;
	int p1 = 1ll * pa * powermod(pa + pb, moder - 2) % moder;
	int p2 = 1ll * pb * powermod(pa + pb, moder - 2) % moder;
	int invp2 = powermod(p2, moder - 2) % moder; 
	for (int i = 1; i <= kk; ++ i){
		for (int j = 0; j <= kk; ++ j){
			int x = i + 1, y = j, num = 1ll * dp[i][j] * p1 % moder;
			if (x + y >= kk){
				ans = (ans + 1ll * num * (invp2 + x + y - 1)) % moder;
			}
			else{
				dp[x][y] += num;
				dp[x][y] -= dp[x][y] >= moder ? moder : 0;
			}
			x = i, y = i + j, num = 1ll * dp[i][j] * p2 % moder;
			if (y >= kk){
				ans = (ans + 1ll * num * y) % moder;
			}
			else if (x + y >= kk){
				ans = (ans + 1ll * num * (invp2 + x + y - 1)) % moder;
			}
			else{
				dp[x][y] += num;
				dp[x][y] -= dp[x][y] >= moder ? moder : 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}