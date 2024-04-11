#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=210;
int d[maxn][maxn],a[maxn],n,k;
vector<int>G[maxn];
int dfs(int u,int fa)
{
	d[u][0]=a[u];
	int w[maxn],son=0;
	memset(w,0,sizeof(w));
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];		
		if(v!=fa)
		{
			son++;
			dfs(v,u);
			for(int j=0;j<=n;j++)
				w[j]+=d[v][j];
			d[u][0]+=d[v][k];
		}
	}
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v!=fa)
		{
			for(int j=1;j<=n;j++)
			{
				int p=max(j-1,k-j);
				d[u][j]=max(d[u][j],d[v][j-1]+w[p]-d[v][p]);
			}
		}
	}
	for(int i=n-1;~i;i--)
	{
		d[u][i]=max(d[u][i],d[u][i+1]);
	}
	return d[u][0];
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int u,v;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<dfs(1,0)<<endl;
	return 0;
}