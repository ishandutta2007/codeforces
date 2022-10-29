#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[55][55],ans[55][55],now[55][55],deg[55],p[55],t[55][55],vis[55],pre[55],n;
inline void dfs(int u)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&!a[u][i]&&t[u][i])
		{
			vis[i]=1,pre[i]=u;
			dfs(i);
		}
	}
}
inline void work()
{
	for(int i=1;i<=n;i++)
	{
		if(deg[i]>1)
		{
			for(int j=1;j<=n;j++)
				vis[j]=pre[i]=0;
			vis[i]=1;
			dfs(i);
			int mn=1e9,w=0;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]&&deg[j]<mn)
					mn=deg[j],w=j;
			}
			if(deg[w]<deg[i])
			{
				int now=w,p=pre[w];
				while(p)
				{
					swap(t[now][p],t[p][now]);
					now=p;
					p=pre[now];
				}
				deg[i]-=2,deg[w]+=2;
			}
		}
	}
}
int main(int argc, char** argv) {
	int m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		a[u][v]=1;
		t[u][v]=1;
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	int st=clock(),ANS=0;
	while(clock()-st<CLOCKS_PER_SEC*0.87)
	{
		random_shuffle(p+1,p+n+1);
		for(int i=1;i<=n;i++) deg[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				t[i][j]=a[i][j];
				if(a[i][j])
					++deg[i],--deg[j];
			}
		}
		int now=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(t[p[i]][p[j]]+t[p[j]][p[i]])
					continue;
				if(deg[p[i]]<deg[p[j]]||deg[p[i]]==deg[p[j]]&&rand()&1)
				{
					t[p[i]][p[j]]=1;
					++deg[p[i]],--deg[p[j]];
				}
				else
				{
					t[p[j]][p[i]]=1;
					++deg[p[j]],--deg[p[i]];
				}
			}
		}/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(t[i][j]&&((n-1-deg[i])*(n-1+deg[i])+(n-1-deg[j])*(n-1+deg[j])<(n+1-deg[i])*(n-3+deg[i])+(n-3-deg[j])*(n+1+deg[j]))&&!(a[i][j]+a[j][i]))
					deg[i]-=2,deg[j]+=2,t[i][j]=0,t[j][i]=1;
			}
		}*/
		work();
		for(int i=1;i<=n;i++)
			now+=(n-1-deg[i])*(n-1+deg[i]);
		if(now>ANS)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ans[i][j]=t[i][j];
			ANS=now;
		}
	}
	//cout << ANS << endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout << ans[i][j]; 
		cout << endl;
	}
	return 0;
}