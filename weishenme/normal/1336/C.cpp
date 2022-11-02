#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3005,M=998244353;
char s1[N],s2[N];
int num[N],dp[N][N],ans,f[N][N];
signed main(){
	scanf("%s%s",s1+1,s2+1);
	int n=strlen(s1+1),m=strlen(s2+1);
	dp[n+1][0]=1;
	for (int i=n;i;i--){
		dp[i][0]=n-i+2;
		for (int j=1;j<=m;j++)
			dp[i][j]=(dp[i+1][j]+(s1[i]==s2[j]?dp[i+1][j-1]:0))%M;
	}
	for (int i=m;i;i--){
		f[i][i]=(s2[i]==s1[1]);
		for (int j=i+1;j<=m;j++)f[i][j]=((s1[j-i+1]==s2[j]?f[i][j-1]:0)+(s1[j-i+1]==s2[i]?f[i+1][j]:0))%M;
	}
	for (int i=1;i<m;i++)
		(ans+=f[m-i+1][m]*dp[i+2][m-i])%=M;
	for (int i=2,s=1;i<=n;i++,(s*=2)%=M)(ans+=(dp[i][m]-dp[i+1][m]+M)*s)%=M;
	printf("%lld\n",(ans+f[1][m]*(n-m+1))*2%M);
}