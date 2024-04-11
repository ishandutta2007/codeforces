#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double a[50],ans=0;
int e[50][50],n,dp[1100000],dp2[1100000];
int E[50];
inline double cal()
{
	double rtn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(e[i][j]) rtn+=a[i]*a[j];
		}
	}
	return rtn;
}
int cnt[1100000];
int bl;
int main(int argc, char** argv) {
	int k;
	cin >> n >> k;
	for(int i=1;i<=1050000;i++) cnt[i]=cnt[i^(i&(-i))]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> e[i][j];
	int mx=0;
	bl=n/2;
	for(int i=1;i<=bl;i++)
	{
		for(int j=1;j<=bl;j++)
		{
			if(i==j||e[i][j])
				E[i]|=(1<<j-1);
		}
	}
	dp[0]=1;
	for(int i=0;i<(1<<bl);i++)
	{
		if(!dp[i]) continue;
		for(int j=1;j<=bl;j++)
		{
			if(i&(1<<j-1)) continue;
			if((E[j]&i)==i) dp[i|(1<<j-1)]|=1;
		}
	}dp[0]=0;
	for(int i=1;i<(1<<bl);i++)
	{
		if(dp[i]) dp[i]=cnt[i];
		for(int j=1;j<=bl;j++)
		{
			if(!(i&(1<<j-1))) continue;
			dp[i]=max(dp[i],dp[i^(1<<j-1)]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		E[i]=0;
		for(int j=bl+1;j<=n;j++)
		{
			if(i==j||e[i][j])
				E[i]|=(1<<j-bl-1);
		}
	}dp2[0]=1;
	for(int i=0;i<(1<<n-bl);i++)
	{
		if(!dp2[i]) continue;
		for(int j=bl+1;j<=n;j++)
		{
			if(i&(1<<j-bl-1)) continue;
			if((E[j]&i)==i) dp2[i|(1<<j-bl-1)]|=1;
		}
		int t=0;
		for(int j=1;j<=bl;j++)
			if((E[j]&i)==i) t|=(1<<j-1);
		mx=max(mx,cnt[i]+dp[t]);
	}
	memset(e,0,sizeof e);
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=mx;j++)
			if(i!=j) e[i][j]=1;
		a[i]=(double)1/(double)mx;
	}
	printf("%.10lf",(mx-1)*k*k/(double)mx/2);
	return 0;
}