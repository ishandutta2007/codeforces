#include <iostream>
using namespace std;
struct edge
{
	int v,n;
}e[5005];
int head[1005],cnt,vis[1005],dis[1005],dep[1005],fa[1005];
inline void add(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
inline void DFS(int u,int f)
{
	fa[u]=f;
	for(int i=head[u];i;i=e[i].n)
	{
		if(e[i].v==f) continue;
		dep[e[i].v]=dep[u]+1;
		DFS(e[i].v,u);
	}
}
inline void dfs(int u,int f)
{
	for(int i=head[u];i;i=e[i].n)
	{
		if(e[i].v==f) continue;
		if(!vis[e[i].v]) dis[e[i].v]=dis[u]+1;
		else dis[e[i].v]=dis[u];
		dfs(e[i].v,u);
	}
}
inline void change(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	vis[x]=vis[y]=1;
	while(dep[x]!=dep[y])
	{
		vis[x]=1;
		x=fa[x];
		vis[x]=1;
	}
	while(x!=y)
	{
		vis[x]=vis[y]=1;
		x=fa[x],y=fa[y];
		vis[x]=vis[y]=1;
	}
	vis[x]=vis[y]=1;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		add(u,v),add(v,u);
	}
	DFS(1,0);
	while(1)
	{
		int w=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]) w=i;
		if(!w) while(1);
		dis[w]=1;
		dfs(w,0);
		int mx=-1,qwq=0;
		for(int i=1;i<=n;i++)
			if(dis[i]>mx&&!vis[i]) mx=dis[i],qwq=i;
		mx=-1;
		dis[qwq]=1;
		dfs(qwq,0);
		for(int i=1;i<=n;i++)
			if(dis[i]>mx&&!vis[i]) mx=dis[i],w=i;
		//cout << mx << endl;
		if(mx==1)
		{
			cout << "! "<< w << endl;
			return 0;
		}
		if(mx==2)
		{
			/*for(int i=1;i<=n;i++)
			{
				dfs(i,0);
				for(int j=1;j<=n;j++)
				{
					if(dis[j]>mx)
					{
						mx=dis[j],w=i,qwq=j;
					}
				}
			}*/
			if(mx<=2)
			{
				if(w==qwq)
				{
					cout << "! " << w << endl;
					return 0;
				}
				cout << "? "<< w << " " << qwq << endl;
				int x;
				cin >> x;
				if(x!=w&&x!=qwq)
				{
					vis[w]=vis[qwq]=1;
					continue;
				}
				else
				{
					cout << "! " << x << endl;
					return 0;
				}
			}
		}
		if(mx<=0) return 1;
				if(w==qwq)
				{
					cout << "! " << w << endl;
					return 0;
				}
		cout << "? "<< w << " " << qwq << endl;
		int x;
		cin >> x;
		if(x!=w&&x!=qwq)
		{
			vis[w]=vis[qwq]=1;
			continue;
		}
		change(w,qwq);
		if(x==w) vis[w]=0;
		if(x==qwq) vis[qwq]=0;
	}
	return 0;
}