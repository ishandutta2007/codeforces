#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int N = 5005;

int n , m , dp[N][N] , col[N] , nxt[N][26];
char s[N];

main(void) {
	scanf("%lld",&n); 
	scanf("%s",s + 1); 
	for(int i = 0;i < 26;i ++) nxt[n + 1][i] = n + 1;
	for(int i = n;i >= 1;i --) {
		for(int j = 0;j < 26;j ++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	dp[1][1] = 1;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) if(dp[i][j]){
			dp[i][j] %= mod;
			for(int k = 0;k < 26;k ++) if(nxt[j][k] <= n)dp[i + 1][nxt[j][k]] += dp[i][j];
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i ++) ans += dp[n + 1][i];
	cout<<ans % mod<<endl; 
}