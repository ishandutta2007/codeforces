#include<bits/stdc++.h>
#define X first
#define Y second
#define N 1001000
using namespace std;
vector<int> g[N];
int v[N],idr[N],idc[N],dp[N],f[N];
int n,m;
bool cmp(int a,int b)
{
	return v[a]<v[b]||v[a]==v[b]&&a<b;
}
inline int tp(int x)
{
	return (x/n)+(x%n)*m;
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline void uni(int x,int y)
{
	if(find(x)!=find(y)) 
		f[f[x]]=f[y];
}
int go(int u)
{
	if(dp[u]) 
		return dp[u];
	int mx=1;
	for(int i=0;i<g[u].size();i++)
	{
		mx=max(mx,1+go(g[u][i]));
	}
	return dp[u]=mx;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&v[i]);
		f[i]=i;
		idr[i]=i;
		idc[i]=tp(i);
	}
	for(int i=0;i<n;i++)
	{
		sort(idr+m*i,idr+m*(i+1),cmp);
		for(int j=m*i+1;j<m*(i+1);j++)
		{
			if(v[idr[j]]==v[idr[j-1]]) 
				uni(idr[j],idr[j-1]);
		}
	}
	for(int i=0;i<m;i++)
	{
		sort(idc+n*i,idc+n*(i+1),cmp);
		for(int j=n*i+1;j<n*(i+1);j++)
		{
			if(v[idc[j]]==v[idc[j-1]]) 
				uni(idc[j],idc[j-1]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=m*i+1;j<m*(i+1);j++)
		{
			if(v[idr[j]]!=v[idr[j-1]]) 
				g[find(idr[j])].push_back(find(idr[j-1]));
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=n*i+1;j<n*(i+1);j++)
		{
			if(v[idc[j]]!=v[idc[j-1]]) g[find(idc[j])].push_back(find(idc[j-1]));
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j) putchar(' ');
			printf("%d",go(find(i*m+j)));
		}
		putchar('\n');
	}
	return 0;
}