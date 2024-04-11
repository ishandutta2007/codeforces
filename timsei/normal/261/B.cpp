#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 55;

double dp[N][N][N][N] , S[N][N][N][N];

int n , m , x , y , k , a[N] , p;

void get(int x) {
	dp[x][0][0][0] = 1;
	for(int i = 1;i <= n;++ i) {
		for(int j = 0;j <= n - 1;++ j) {
			for(int k = 0; k <= p;++ k) {
				dp[x][i][j][k] += dp[x][i - 1][j][k];
				if(i != x && k - a[i] >= 0 && j != 0) 
				dp[x][i][j][k] += dp[x][i - 1][j - 1][k - a[i]];
			}
		}
	}
}

double ans , P[N];

double getm(int x , int n , int i , int j) {
	double res = 0;
	j = max(j , -1);
	for(int k = j + 1;k <= p;++ k) res += dp[x][n][i][k];
	return res;
}

int main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%d" , &a[i]);
	}
	scanf("%d" , &p);
	int S = 0;
	for(int i = 1;i <= n;++ i) S += a[i];
	if(S <= p) {
		printf("%d\n" , n); return 0;
	}
	P[0] = 1;
	for(int i = 1;i <= 50;++ i) P[i] = P[i - 1] * (double) i;
	for(int i = 1;i <= n;++ i) get(i);
			
	for(int i = 1;i <= n - 1;++ i) {
		for(int j = 1;j <= n;++ j) {
			ans += P[n - i - 1] * P[i] * getm(j , n , i , p - a[j]) * i;
		}
	}
	printf("%.10lf\n" , ans / P[n]);
}