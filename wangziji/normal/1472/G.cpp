#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dis[200005],ans[200005],qwq[200005],cnt;
vector <int> e[200005];
queue <int> q;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
		}
		for(int i=2;i<=n;i++) dis[i]=1e9;
		q.push(1);
		cnt=0;
		while(!q.empty())
		{
			int x=q.front();
			qwq[++cnt]=x;
			q.pop();
			ans[x]=dis[x];
			for(auto v:e[x])
			{
				if(dis[v]>dis[x]+1) q.push(v),dis[v]=dis[x]+1;
				if(dis[v]<=dis[x]) ans[x]=min(ans[x],dis[v]);
			}
		}
		for(int i=cnt;i>=1;i--)
		{
			int x=qwq[i];
			for(auto v:e[x])
				if(dis[v]>dis[x]) ans[x]=min(ans[x],ans[v]);
		}
		for(int i=1;i<=n;i++)
			cout << ans[i] << " ";
		puts("");
	}
	return 0;
}