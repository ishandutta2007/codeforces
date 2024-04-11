#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N],c[N],n,m,k,t,s[N][3],dp[N][3];
inline void chmin(int &a,int b){if(a>b)a=b;}
int main()
{
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d%d",&n,&m,&k);
	t=n+m+k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[a[i]][0]++;
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),s[b[i]][1]++;
	for(int i=1;i<=k;i++)
		scanf("%d",&c[i]),s[c[i]][2]++;
	dp[0][0]=0;
	for(int i=0;i<=t;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(j<2) chmin(dp[i][j+1],dp[i][j]);
			chmin(dp[i+1][j],dp[i][j]+1-s[i+1][j]);
		} 
	}
	printf("%d\n",dp[t][2]);
	return 0;
}