#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int n,m;
char s[5013];
string uniq;
int dp[5013][5013];
int curl[26];

int main() {
	scanf("%d %s",&n,&s);
	uniq = "0";
	for (int i=0;i<n;i++) {
		m+=(s[i]!=uniq.back());
		if (s[i]!=uniq.back()) uniq+=s[i];
	}
	dp[0][1] = 1;
	for (int i=0;i<n;i++) {
		int cur = 0;
		memset(curl,0,sizeof curl);
		for (int j=1;j<=m;j++) {
			cur = add(cur,dp[i][j]);
			dp[i+1][j] = add(dp[i+1][j],cur);
			dp[i+1][j] = sub(dp[i+1][j],curl[uniq[j]-'a']);
			curl[uniq[j]-'a'] = cur;
		}
	}
	int ans = 0;
	for (int j=1;j<=m;j++) ans = add(ans,dp[n][j]);
	printf("%d\n",ans);

	return 0;
}