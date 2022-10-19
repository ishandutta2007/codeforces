#include<bits/stdc++.h>
using namespace std;
const int N=25,M=300005;
int n,a[N][N];
long long f[M],g[N][M],d[N][M],dp[N][M];
map<long long,long long>mp;
string st;
inline int bp(int x){return __builtin_popcount(x);}
void dfs(int p,int s,int x,long long m)
{
	if(s==n)
	{
		long long w=0;
		for(int i=0;i<(1<<n);i++)
		{
			if((n+bp(i))&1)
				w-=d[x][i];
			else
				w+=d[x][i];
		}
		mp[m]=w;
		return;
	}
	if(s+p>n)
		return;
	for(int i=0;i<(1<<n);i++)
		d[x+1][i]=d[x][i]*g[p][i];
	dfs(p,s+p,x+1,m*10+p);
	dfs(p+1,s,x,m);
}
long long ch(int x)
{
	vector<int>v;
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(x>>i&1)
			s++;
		else
		{
			v.push_back(s+1);
			s=0;
		}
	}
	sort(v.begin(),v.end());
	long long y=0;
	for(auto i:v)
		y=y*10+i;
	return y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>st;
		for(int j=0;j<n;j++)
			a[i][j]=(st[j]=='1');
	}
	for(int i=0;i<n;i++)
		dp[i][1<<i]=1;
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[j][i])
			{
				g[bp(i)][i]+=dp[j][i];
				for(int k=0;k<n;k++)
					if(!(i>>k&1)&&a[j][k])
						dp[k][i|(1<<k)]+=dp[j][i];
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			for(int s=0;s<(1<<n);s++)
				if(s>>j&1)
					g[i][s]+=g[i][s^(1<<j)];
	for(int i=0;i<(1<<n);i++)
		d[0][i]=1;
	dfs(1,0,0,0);
	for(int i=0;i<(1<<(n-1));i++)
		f[i]=mp[ch(i)];
	for(int i=0;i<n-1;i++)
		for(int j=0;j<(1<<(n-1));j++)
			if(!(j>>i&1))
				f[j]-=f[j^(1<<i)];
	for(int i=0;i<(1<<(n-1));i++)
		printf("%lld ",f[i]);
	return 0;
}