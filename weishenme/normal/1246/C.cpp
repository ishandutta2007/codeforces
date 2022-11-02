#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005,M=1e9+7;
int dp1[N][N],g0[N][N],g1[N][N],dp0[N][N],n,m,down[N][N],flag[N][N],ri[N][N];
char s[N][N];
signed main(){
	scanf("%lld%lld",&n,&m);
	if (n==1&&m==1){
		puts("1");
		return 0;
	} 
	for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=m;j;j--)ri[i][j]=s[i][j]=='R'?ri[i][j+1]:ri[i][j+1]+1; 
	for (int i=1;i<=m;i++)
		for (int j=n;j;j--)down[j][i]=s[j][i]=='R'?down[j+1][i]:down[j+1][i]+1;
	dp0[n][m]=dp1[n][m]=g0[n][m]=g1[n][m]=1;
	for (int i=n;i;i--)
		for (int j=m;j;j--){
			if (i==n&&j==m)continue;
			dp0[i][j]=(g1[i][j+1]-g1[i][j+1+ri[i][j+1]]+M)%M;
			dp1[i][j]=(g0[i+1][j]-g0[i+1+down[i+1][j]][j]+M)%M;
			g0[i][j]=(g0[i+1][j]+dp0[i][j])%M;
			g1[i][j]=(g1[i][j+1]+dp1[i][j])%M;
		}
	printf("%lld\n",(dp0[1][1]+dp1[1][1])%M);	
}