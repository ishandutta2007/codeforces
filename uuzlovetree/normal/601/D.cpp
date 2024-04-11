#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n;
int c[maxn];
char s[maxn];
vector<int> g[maxn];
int ch[maxn][26],cnt,sumv[maxn];
int Ans[maxn];
int merge(int &x,int y)
{
	if(!x||!y)
	{
		x=x+y;
		return sumv[x];
	}
	sumv[x]=1;
	for(int i=0;i<26;++i)sumv[x]+=merge(ch[x][i],ch[y][i]);
	return sumv[x];
}
int dfs(int u,int fa)
{
	int x=++cnt;
	sumv[x]=1;
	for(int v:g[u])if(v!=fa)
	{
		int t=dfs(v,u);
		sumv[x]-=sumv[ch[x][s[v]-'a']];
		sumv[x]+=merge(ch[x][s[v]-'a'],t);
	}
	Ans[u]=sumv[x];
	return x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	scanf("%s",s+1);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int maxv=0,maxt=0;
	for(int u=1;u<=n;++u)
	{
		if(maxv<Ans[u]+c[u])
		{
			maxv=Ans[u]+c[u];
			maxt=1;
		}
		else if(maxv==Ans[u]+c[u])maxt++;
	}
	printf("%d\n%d\n",maxv,maxt);
}