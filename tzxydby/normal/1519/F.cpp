#include<bits/stdc++.h>
using namespace std;
const int N=20005,inf=0x3f3f3f3f;
int p[10],t[N],k[N][10],n,m,a[10],b[10],s,c[10][10],h,dp[N],ans=inf;
int main()
{
	p[0]=1;
	for(int i=1;i<=6;i++)
		p[i]=p[i-1]*5;
	for(int b=0;b<15625;b++)
		for(int j=0;j<6;j++)
			t[b]+=k[b][j]=b/p[j]%5;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		s-=b[i];
	}
	if(s>0)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&c[i][j]);
	s=0;
	for(int j=m-1;j>=0;j--)
		h=h*5+b[j],s+=b[j];
	memset(dp,inf,sizeof(dp));
	dp[h]=0;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			for(int h=0;h<15625;h++)
			{
				if(dp[h]>=inf)
					continue;
				for(int l=1;l<=k[h][j];l++)
					dp[h-l*p[j]]=min(dp[h-l*p[j]],dp[h]+c[i][j]);
			}
		}
		s-=a[i];
		for(int h=0;h<15625;h++)
			if(t[h]!=s)
				dp[h]=inf;
	}
	for(int h=0;h<15625;h++)
		ans=min(ans,dp[h]);
	printf("%d\n",ans);
	return 0;
}