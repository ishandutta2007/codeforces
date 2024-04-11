#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 505;

int dp[N][N] , n , m;
int num[N];
bool is[N][N];
bool vis[N][N];
int doit(int l , int r) {
	if(dp[l][r]) return dp[l][r];
	dp[l][r] = 2e9;
	for(int i = l;i <= r - 1;i ++) {
		dp[l][r] = min(dp[l][r] , doit(l , i) + doit(i + 1 , r));
	}
	if(num[l] == num[r]) {
		if(abs(r - l) < 2) return dp[l][r] = 1;
		dp[l][r] = min(dp[l][r] , doit(l + 1 , r - 1));
	}
	return dp[l][r];
}

int main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;i ++) scanf("%d" , &num[i]);
	printf("%d\n" , doit(1 , n));
}