#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005 ,mod = 998244353 ;
int a[N],n,k,b[N],c[N*N],tot,s[N][N],ans;
int DP(int K)
{
	s[0][0]=1;a[0]=-1e6;
	for(int i=1,j=0;i<=n;i++)
	{
		for(;j<=n&&a[i]-a[j]>=K;j++);j--;s[i][0]=1;
		for(int t=1;t<=k;t++)s[i][t]=(s[i-1][t]+s[j][t-1])%mod;
	}
	return s[n][k];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)c[++tot]=a[j]-a[i];
	sort(c+1,c+tot+1);tot=unique(c+1,c+tot+1)-c-1;
	for(int i=1;i<=tot;i++)
		if(c[i]*(k-1)<=a[n])ans=(ans+(ll)(c[i]-c[i-1])*DP(c[i]))%mod;
	printf("%d\n",ans);
}