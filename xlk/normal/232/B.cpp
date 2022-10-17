#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
long long m,z;
int n,k,rm,p=1000000007;
int f[105][10005];
int g[105][10005];
int fc[105][105];
int gc[105][105];
int c[105][105];
long long pw(long long x,long long y)
{
	long long _=1;
	for(;y;y>>=1)
	{
		if(y&1)
			_=_*x%p;
		x=x*x%p;
	}
	return _;
}
int main()
{
	cin>>n>>m>>k;
	rm=m%n;
	m/=n;
	f[0][0]=1;
	g[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			fc[i][j]=pw(c[i][j],m);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			gc[i][j]=pw(c[i][j],m+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
		{
			for(int k=0;k<=min(j,n);k++)
			{
				f[i][j]=(f[i][j]+(long long)f[i-1][j-k]*fc[n][k])%p;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
		{
			for(int k=0;k<=min(j,n);k++)
			{
				g[i][j]=(g[i][j]+(long long)g[i-1][j-k]*gc[n][k])%p;
			}
		}
	for(int i=0;i<=k;i++)
		z=(z+(long long)f[n-rm][k-i]*g[rm][i])%p;
	cout<<z;
	return 0;
}