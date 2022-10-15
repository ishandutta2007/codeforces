#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define mp make_pair
vector<int>v[100005],v2[100005];
int inherit[100005],comp[100005],parent[100005][25],height[100005];
int parr[100005];
int findpar(int node)
{
	return parr[node]==node ? node : parr[node]=findpar(parr[node]);
}
void dfs(int node, int par, int inh, int com)
{
	parent[node][0]=par;
	inherit[node]=inh;
	comp[node]=com;
	height[node]=height[par]+1;
	for(int i=1;i<=20;i++)
	{
		parent[node][i]=parent[parent[node][i-1]][i-1];
	}
	for(int i=0;i<v[node].size();i++)
	{
		if(v[node][i]==par)
			continue;
		if(v2[node][i]==0)
			dfs(v[node][i],node,inh+1,com);
		else
			dfs(v[node][i],node,inh,com+1);
	}
}
int findlca(int u, int v)
{
	if(height[u]>height[v])
		swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(height[parent[v][i]]>=height[u])
		{
			v=parent[v][i];
		}
	}
	if(u!=v)
	{
		for(int i=20;i>=0;i--)
		{
			if(parent[u][i]!=parent[v][i])
			{
				u=parent[u][i];
				v=parent[v][i];
			}
		}
		u=parent[u][0];
		v=parent[v][0];
	}
	return u;
}
int main()
{
	int i,j,k;
	int n,q;
	sd(n);
	for(i=1;i<=n;i++)
		parr[i]=i;
	for(i=1;i<=n;i++)
	{
		sd(j);
		sd(k);
		if(j==-1 && k==-1)
			continue;
		v[i].pb(j);
		v[j].pb(i);
		v2[i].pb(k);
		v2[j].pb(k);
		int x=findpar(i);
		int y=findpar(j);
		if(x!=y)
			parr[x]=y;
	}
	for(i=1;i<=n;i++)
	{
		if(parent[i][0]==0)
		{
			dfs(i,i,0,0);
		}
	}
	sd(q);
	while(q--)
	{
		sd(i);
		sd(j);
		sd(k);
		int x=findpar(j);
		int y=findpar(k);
		if(x!=y)
		{
			printf("NO\n");
			continue;
		}
		x=findlca(j,k);
		if(i==1)
		{
			if(x!=j || comp[k]-comp[x]!=0 || j==k)
			{
				printf("NO\n");
			}
			else
				printf("YES\n");
		}
		else
		{
			if(inherit[k]-inherit[x]!=0 || comp[j]-comp[x]!=0 || x==k)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}