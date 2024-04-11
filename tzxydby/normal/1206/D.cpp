#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
long long a[maxn];
long long val[maxn];
int t=0;
long long dp[400][400];
long long dis[400][400];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if(a[i]!=0)val[++t]=a[i];
	}
	if(t>3*64){printf("3\n");return 0;}
	long long minn=0x3f3f3f3f;
	for(int i=1;i<=t;i++)
	for(int j=1;j<=t;j++)
	if(i!=j&&((val[i]&val[j])!=0))dis[i][j]=1,dp[i][j]=1;
	else dp[i][j]=dis[i][j]=0x3f3f3f3f;
	for(int k=1;k<=t;k++)
	{
		for(int i=1;i<k;i++)
		for(int j=i+1;j<k;j++)
		minn=min(dp[i][j]+dis[i][k]+dis[k][j],minn);
		for(int i=1;i<=t;i++)
		for(int j=1;j<=t;j++)
		dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
	}
	if(minn==0x3f3f3f3f)printf("-1\n");
	else printf("%d\n",minn);
}