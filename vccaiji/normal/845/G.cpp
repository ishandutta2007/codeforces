#include<bits/stdc++.h>
using namespace std;
struct ed//
{
	int x;
	int y;
	long long k;
}edg[110000];
vector <int> e[110000];
vector <long long> d[110000];
int n,m;
long long a[60];
long long dist[110000]={};
bool vis[110000]={};
void dfs(int i)
{
	vis[i]=true;
	for(int j=0;j<e[i].size();j++)
	{
		if(!vis[e[i][j]])
		{
			dist[e[i][j]]=dist[i]^d[i][j];
			dfs(e[i][j]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		long long k;
		scanf("%d%d%lld",&x,&y,&k);
		edg[i].x=x;
		edg[i].y=y;
		edg[i].k=k;
		e[x].push_back(y);
		e[y].push_back(x);
		d[x].push_back(k);
		d[y].push_back(k);
	}
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		long long aa=dist[edg[i].x]^dist[edg[i].y]^edg[i].k;
		long long bb=1;
		for(int j=59;j>=0;j--)
		{
			if(aa&(bb<<j))
			{
				if(a[j]) aa^=a[j];
				else
				{
					a[j]=aa;
					break;
				}
			}
		}
	}
	long long aa=dist[n];
	long long bb=1;
	for(int j=59;j>=0;j--)
	{
		if((a[j]>0)&&((aa&(bb<<j))>0))
		 aa^=a[j];
	}
	cout<<aa;
	return 0;
}