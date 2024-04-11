#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
vector <int> e[200005],F[200005];
int vis[200005],cnt,ans[200005],qwq[200005],d[200005];
queue <int> q;
inline void ck(int u)
{
	if(qwq[u])
		return ;
	for(auto x:e[u])
	{
		if(!qwq[x])
		{
			for(auto v:e[x])
				if(!vis[v]) q.push(v);
		}
	}
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) e[i].clear(),vis[i]=0,d[i]=qwq[i]=0,F[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v),++d[v];
			F[v].push_back(u);
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(auto x:e[i])
			{
				for(auto y:e[x])
					++qwq[y];
			}
		}
		for(int i=1;i<=n;i++)
			ck(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(vis[u]) continue;
			vis[u]=1,ans[++cnt]=u;
			for(auto x:e[u])
			{
				if(vis[x]) continue;
				for(auto y:e[x])
				{
					if(vis[y]) continue;
					--qwq[y];
				}
				qwq[x]-=d[u];
				--d[x];
			}
			for(auto x:e[u])
			{
				for(auto y:e[x])
				{
					if(!vis[y]) ck(y);
					if(!vis[y]&&!qwq[y])
					{
						for(auto X:F[y])
							ck(X);
						F[y].clear();
					}
				}
				if(!vis[x]&&!qwq[x])
				{
					ck(x);
					for(auto X:F[x])
						ck(X);
					F[x].clear();
				}
			}
		}
		cout << cnt << "\n";
		for(int i=1;i<=cnt;i++)
			cout << ans[i] << " ";
		puts("");
		if(cnt>n*4/7)
			return 1;
	}
	return 0;
}
/*
1
6 8
1 2
2 3
3 4
4 5
5 6
1 3
3 5
4 6
*/