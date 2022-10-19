#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=1505;
int n,m,a[N][N],b[N][N],k=1,l[N],tot[N*N],d[N],q[N],bg,ed,vis[N];
unordered_map<int,int>mp[N*N];
vector<int>p[N*N],e[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=n;i++)
	{
		int u=1;
		for(int j=1;j<=m;j++)
		{
			if(mp[u].find(b[i][j])==mp[u].end())
				mp[u][b[i][j]]=++k;
			u=mp[u][b[i][j]];
		}
		p[u].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int u=1;
		for(int j=1;j<=m;j++)
		{
			if(mp[u].find(a[i][j])==mp[u].end())
			{
				puts("-1");
				return 0;
			}
			u=mp[u][a[i][j]];
		}
		if(tot[u]==p[u].size())
		{
			puts("-1");
			return 0;
		}
		l[p[u][tot[u]]]=i;
		tot[u]++;
	}
	for(int j=1;j<=m;j++)
		for(int i=1;i<n;i++)
			if(b[i][j]>b[i+1][j])
				e[i].push_back(j),d[j]++;
	for(int i=1;i<n;i++)
		if(l[i]>l[i+1])
			e[i].push_back(m+1),d[m+1]++;
	for(int i=1;i<=m+1;i++)
		if(!d[i])
			q[ed++]=i;
	while(bg<ed)
	{
		int x=q[bg++];
		if(x==m+1)
		{
			printf("%d\n",bg-1);
			for(int i=bg-2;i>=0;i--)
				printf("%d ",q[i]);
			return 0;
		}
		for(int i=1;i<n;i++)
		{
			if(b[i][x]<b[i+1][x]&&!vis[i])
			{
				vis[i]=1;
				for(auto y:e[i])
				{
					d[y]--;
					if(!d[y])
						q[ed++]=y;
				}
			}
		}
	}
	puts("-1");
	return 0;
}