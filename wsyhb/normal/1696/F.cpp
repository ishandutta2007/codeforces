#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=100+5;
char str[max_n];
#define equal equ
bool equal[max_n][max_n][max_n];
int fath[max_n];
bool vis[max_n];
int dis[max_n];
vector<int> edge[max_n];
inline void add_edge(int x,int y)
{
	edge[x].push_back(y);
	edge[y].push_back(x);
}
vector<vector<int> > G[max_n];
void dfs(int x,int fa)
{
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dis[y]=dis[x]+1;
			dfs(y,x);
		}
	}
}
inline bool check()
{
	for(int i=1;i<=n;++i)
		edge[i].clear();
	for(int i=2;i<=n;++i)
		add_edge(i,fath[i]);
	for(int z=1;z<=n;++z)
	{
		dis[z]=0;
		dfs(z,0);
		for(int i=0;i<int(G[z].size());++i)
		{
			for(int j=0;j+1<int(G[z][i].size());++j)
			{
				if(dis[G[z][i][j]]!=dis[G[z][i][j+1]])
					return false;
			}
		}
		int mx=0;
		for(int i=1;i<=n;++i)
			mx=max(mx,dis[i]);
		if(int(G[z].size())!=mx+1)
			return false;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n-1;++i)
			for(int j=1;j<=n-i;++j)
			{
				scanf("%s",str+1);
				for(int k=1;k<=n;++k)
					equal[k][i][i+j]=equal[k][i+j][i]=str[k]^'0';
			}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				equal[k][i][i]=true;
		for(int i=1;i<=n;++i)
			G[i].clear();
		bool ok=true;
		for(int z=1;z<=n&&ok;++z)
		{
			for(int i=1;i<=n;++i)
				vis[i]=false;
			for(int x=1;x<=n&&ok;++x)
			{
				if(vis[x])
					continue;
				vector<int> now;
				for(int y=1;y<=n;++y)
				{
					if(equal[z][x][y])
					{
						if(vis[y])
						{
							ok=false;
							break;
						}
						now.push_back(y);
						vis[y]=true;
					}
				}
				for(int i=0;i<int(now.size())&&ok;++i)
					for(int j=0;j<int(now.size());++j)
					{
						if(!equal[z][now[i]][now[j]])
						{
							ok=false;
							break;
						}
					}
				G[z].push_back(now); 
			}
			for(int i=0;i<int(G[z].size())&&ok;++i)
				for(int j=0;j<int(G[z].size())&&ok;++j)
					for(int a=0;a<int(G[z][i].size())&&ok;++a)
						for(int b=0;b<int(G[z][j].size());++b)
						{
							if((i==j)!=equal[z][G[z][i][a]][G[z][j][b]])
							{
								ok=false;
								break;
							}
						}
		}
		if(!ok)
		{
//			fprintf(stderr,"type 1\n");
			puts("No");
			continue;
		}
		bool ans=false;
		for(int son=2;son<=n;++son)
		{
			for(int i=1;i<=n;++i)
				vis[i]=false;
			queue<int> q;
			for(int i=1;i<=n;++i)
			{
				if(equal[1][son][i])
				{
					vis[i]=true;
					fath[i]=1;
					q.push(i);
				}
			}
			vis[1]=true,fath[1]=0;
			ans=true;
			while(!q.empty())
			{
				int x=q.front();
				q.pop();
				for(int i=1;i<=n;++i)
				{
					if(equal[x][fath[x]][i]&&i!=fath[x])
					{
						if(vis[i])
						{
							ans=false;
							break;
						}
						fath[i]=x;
						q.push(i);
						vis[i]=true;
					}
				}
				if(!ans)
					break;
			}
			if(!ans)
				continue;
			for(int i=1;i<=n;++i)
			{
				if(!vis[i])
				{
					ans=false;
					break;
				}
			}
			if(!ans)
				continue;
//			fprintf(stderr,"son=%d\n",son);
			if(check())
				break;
			ans=false;
		}
		if(ans)
		{
			puts("Yes");
			for(int i=2;i<=n;++i)
				printf("%d %d\n",fath[i],i);
		}
		else
			puts("No");
	}
	return 0;
}