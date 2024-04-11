#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int dp[N] , n , m , x , y;

int pr[N] , cnt  , S[N];

bool isp[N];

int Div[N];

#define lowbit(x) (x & (-x))

void add(int x , int v) {
	for(int i = x;i < N;i += lowbit(i)) S[i] = min(S[i] , v);
}

int sum(int x) {
	int A = 1e9;
	for(int i = x;i;i -= lowbit(i)) A = min(S[i] , A);
	return A;
}

main(void) {
	memset(isp , 1 , sizeof(isp));
	isp[0] = isp[1] = 0;
	for(int i = 2;i < N;++ i) {
		if(isp[i])pr[++ cnt] = i;
		for(int j = 1;j <= cnt && pr[j] * i < N;++ j) {
			isp[i * pr[j]] = 0;
			if(i % pr[j] == 0) break;
		}
	}
	scanf("%d" , &n);
	for(int i = 1;i <= cnt;++ i) {
		for(int j = 1;j <= n / pr[i];++ j) Div[pr[i] * j] = max(Div[pr[i] * j] , pr[i]);
	}
	memset(S , 127 , sizeof(S));
	dp[n] = n;
	for(int i = n - Div[n] + 1;i <= n;++ i) {
		if(isp[i]) continue;
		dp[n] = min(dp[n] , max(i - Div[i] + 1 , 3));
	}
	cout << dp[n];
}