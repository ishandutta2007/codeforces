#include <bits/stdc++.h>
using namespace std;
const int Maxn=5005,p=1000000007;
int n,ans,dp[Maxn][Maxn],sum[Maxn][Maxn];
char ch[Maxn],last;
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		getchar(),ch[i]=getchar();
	dp[1][0]=1;
	last=ch[1];
	for(int i=2;i<=n;i++)
		if(ch[i]=='f'&&last=='f')
		{
			last='f';
			for(int j=1;j<=n;j++)
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%p;
		}
		else if(ch[i]=='f'&&last!='f')
		{
			last='f';
			int all=0;
			for(int j=0;j<=n;j++)
				all=(all+dp[i-1][j])%p;
			for(int j=0;j<=n;j++)
				dp[i][j]=(dp[i][j]+all)%p,all=((all-dp[i-1][j])%p+p)%p;
		}
		else if(ch[i]=='s'&&last!='f')
		{
			last='s';
			int all=0;
			for(int j=0;j<=n;j++)
				all=(all+dp[i-1][j])%p;
			for(int j=0;j<=n;j++)
				dp[i][j]=(dp[i][j]+all)%p,all=((all-dp[i-1][j])%p+p)%p;
		}
		else
		{
			last='s';
			for(int j=1;j<=n;j++)
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%p;
		}
	for(int i=0;i<=n;i++)
		ans=(ans+dp[n][i])%p;
	printf("%d",ans);
	return 0;
}