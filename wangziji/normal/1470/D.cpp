#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> e[300005],ans;
int del[300005],fa[300005],vis[300005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
queue <int> q;
int main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		ans.clear();
		for(int i=1;i<=n;i++) e[i].clear(),del[i]=0,vis[i]=0,fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			fa[ff(u)]=ff(v);
		}
		int flag=0;
		for(int i=1;i<n;i++)
		{
			if(ff(i)!=ff(i+1))
			{
				cout << "NO\n";
				flag=1;
				break;
			}
		} 
		if(flag) continue;
		del[1]=1,vis[1]=1;
		ans.push_back(1);
		for(auto v:e[1]) del[v]=1,q.push(v);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			if(del[x])
			{
				for(auto v:e[x])
					if(!vis[v]) vis[v]=1,q.push(v);
			}
			else
			{
				ans.push_back(x),del[x]=1;
				for(auto v:e[x])
				{
					del[v]=1;
					if(!vis[v]) q.push(v);
				}
			}
		}
		cout << "YES\n";
		cout << ans.size() << "\n";
		for(auto v:ans) cout << v << " ";
		cout << "\n";
	}
	return 0;
}