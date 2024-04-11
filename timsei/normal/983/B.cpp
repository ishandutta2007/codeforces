#include <bits/stdc++.h>
using namespace std;

const int N = 5555;

int n , m , A[N] , l , r;

void read(int &x) {
	x = 0;
	char ch = getchar();
	while(!isdigit(ch))
	ch = getchar();
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
}

int ans[N][N] , dp[N][N];
bool vis[N][N];

main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%d" , &A[i]);
	}
	for(int i = 1;i <= n;++ i)
	dp[i][i] = A[i] , ans[i][i] = dp[i][i];
	for(int len = 1;len < n;++ len) {
		for(int i = 1;i <= n - len;++ i) {
			int j = i + len;
			dp[i][j] = dp[i + 1][j] ^ dp[i][j - 1];
			ans[i][j] = dp[i][j];
			ans[i][j] = max(ans[i][j] , ans[i + 1][j]);
			ans[i][j] = max(ans[i][j] , ans[i][j - 1]);
		}
	}
	int t;
	for(scanf("%d" , &t);t --;) {
		read(l); read(r);
		printf("%d\n" , ans[l][r]);
	}
}