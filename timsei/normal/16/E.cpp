#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n , m , vis[1 << N];
double a[N][N] , dp[1 << N];

double DP(int x) {
    if(x == (1 << n) - 1) return 1;
    if(vis[x]) return dp[x];
    dp[x] = 0; vis[x] = 1;
    int all = 0;
    for(int i = 0;i < n;++ i) if((1 << i) & x) ++ all;
    for(int i = 1;i <= n;++ i) if((1 << (i - 1)) & x) {
	    for(int j = 1;j <= n;++ j) if(!((1 << (j - 1) & x))) {
		    dp[x] += DP(x | (1 << (j - 1))) * a[i][j] / all / (all + 1) * 2;
		}
	}
    return dp[x];
}

int main(void) {
    scanf("%d" , &n);
    for(int i = 1;i <= n;++ i) {
	for(int j = 1;j <= n;++ j) scanf("%lf" , &a[i][j]);
    }
    for(int i = 1;i <= n;++ i) printf("%.20lf " , DP(1 << (i - 1)));
}