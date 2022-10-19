#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,g0,x,y,z,q[3003],mp[3003][3003],dp[3003][3003];
void calc(int x,int n,int m) 
{
	int l=1,r=0;
	for(int i=1;i<=n;i++) 
	{
		if(i-q[l]+1>m&&l<=r)
			l++;
		while(mp[i][x]<mp[q[r]][x]&&l<=r)
			r--;
		q[++r]=i;
		dp[i][x]=mp[q[l]][x];
	}
}
void calc2(int x,int n,int m) 
{
	int l=1,r=0;
	for(int i=1;i<=n;i++) 
	{
		if(i-q[l]+1>m&&l<=r)
			l++;
		while(dp[x][i]<dp[x][q[r]]&&l<=r)
			r--;
		q[++r]=i;
		mp[x][i]=dp[x][q[l]];
	}
}
int main() 
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>a>>b>>g0>>x>>y>>z;
	for(int i=1;i<=n;i++)
		for(int j=1; j<=m; j++)
			mp[i][j]=g0,g0=(1LL*g0*x+y)%z;
	for(int i=1;i<=m;i++)
		calc(i,n,a);
	for(int i=1;i<=n;i++)
		calc2(i,m,b);
	long long ans=0;
	for(int i=a;i<=n;i++)
		for(int j=b;j<=m;j++)
			ans+=mp[i][j];
	cout<<ans<<endl;
	return 0;
}