#include<bits/stdc++.h>
using namespace std;
const long long INF=2e9;
long long dp[36][100005];
long long h,w,a,b;
int n;
long long ans;
long long f[100005];
bool cmp(long long x,long long y){return x>y;}
long long JUST_DO_IT()
{
	memset(dp,-1,sizeof(dp));
	dp[0][min(a,h)]=w;
	for(int i=0;i<min(n,35);i++)
	for(int j=0;j<=a;j++)
	{
		if(dp[i][j]!=-1)
		{
			long long xx=j*f[i+1],yy=dp[i][j]*f[i+1];
			xx=min(xx,a);yy=min(yy,b);
			dp[i+1][xx]=max(dp[i+1][xx],dp[i][j]);
			dp[i+1][j]=max(dp[i+1][j],yy);
		}
	}
	for(int i=0;i<=min(n,35);i++)
	{
		if(dp[i][a]>=b)
		{
			return i;
		 } 
	}
	return INF;
}
int main()
{
	//wa dp 
	cin>>a>>b>>h>>w>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+n+1,cmp);
	ans=JUST_DO_IT();
	swap(a,b);
	ans=min(ans,JUST_DO_IT());
	if(ans>100000) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}