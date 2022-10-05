#include<bits/stdc++.h>

const int N = 60;
const int M = 6010;

double dp[N][M];
int f[N], s[N], p[N], suf[N];
int n, r;

double getdp(int i, int j, double mid){
    return j > r ? mid : dp[i][j];
}

int main(){
    scanf("%d%d", &n, &r);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d", &f[i], &s[i], &p[i]);
        sum += s[i];
    }
    double left = 0, right = 1e9;
    for (int _ = 0; _ < 70; ++ _){
        double mid = (left + right) / 2;
        double x;
        for (int i = n - 1; i >= 0; -- i){
            for (int j = 0; j <= r; ++ j){
                if (j > r){
                    dp[i][j] = mid;
                }
                else{
                    double tmp = p[i] / 100.0 * (f[i] + getdp(i + 1, j + f[i], mid))
                                + (1 - p[i] / 100.0) * (s[i] + getdp(i + 1, j + s[i], mid));
                    if (i == 0 && j == 0){
                        x = tmp;
                    }
                    dp[i][j] = std::min(mid, tmp);
                }
            }
        }
        if (x < mid){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    printf("%.15f\n", left);
    return 0;
}