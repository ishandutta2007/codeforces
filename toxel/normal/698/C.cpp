#include<bits/stdc++.h>

const int N = 20;

double p[N];
double ans[N];
int bitcnt[1 << N];
double dp[1 << N][N + 1];
double ppower[100];

double power(double a, int exp){
    double ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) ret *= a;
        a *= a;
    }
    return ret;
}

int main(){
    for (int i = 1; i < 1 << N; ++ i){
        bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < 100; ++ i){
        ppower[i] = power(i / 100.0, k) / (1 - i / 100.0);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%lf", &p[i]);
    }
    for (int i = 0; i < 1 << n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (i >> j - 1 & 1){
                dp[i][j] = dp[i ^ 1 << j - 1][j - 1] + dp[i][j - 1];
            }
            else{
                dp[i][j] = dp[i][j - 1];
            }
        }
        double sum = 0;
        for (int j = 0; j < n; ++ j){
            if (i >> j & 1){
                sum += p[j];
            }
        }
        if (bitcnt[i] == k && sum > 0.999){
            for (int j = 0; j < n; ++ j){
                printf("%.10lf%c", p[j] > 0.001 ? 1.0 : 0.0, " \n"[j == n - 1]);
	        }
	        return 0;
    	}
        dp[i][0] = ppower[(int) (sum * 100 + 0.5)] - dp[i][n];
        for (int j = 1; j <= n; ++ j){
            dp[i][j] += dp[i][0];
        }
        if (bitcnt[i] == k){
            for (int j = 0; j < n; ++ j){
                if (i >> j & 1){
                    ans[j] += dp[i][0] * (1 - sum);
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%.10lf%c", ans[i], " \n"[i == n - 1]);
    }
    return 0;
}