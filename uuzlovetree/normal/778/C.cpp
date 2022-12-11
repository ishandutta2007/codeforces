#include<bits/stdc++.h>
#define maxn 600005
using namespace std;
int n;
vector< pair<int,int> > g[maxn];
int ch[maxn][26];
int d[maxn],Ans[maxn];
void build(int u)
{
	for(auto p:g[u])
	{
		int v=p.first,c=p.second;
		ch[u][c]=v;
		d[v]=d[u]+1;
		build(v);
	}
}
int cnt;
int merge(int x,int y)
{
	if((!x)&&(!y))return 0;
	if(!x||!y)return x+y;
	int u=++cnt;
	for(int i=0;i<26;++i)
	{
		ch[u][i]=merge(ch[x][i],ch[y][i]);
	}
	return u;
}
void dfs(int u)
{
	for(auto p:g[u])
	{
		int v=p.first,c=p.second;
		dfs(v);
	}
	int rt=n+1;
	cnt=n+1;
	for(auto p:g[u])
	{
		int v=p.first,c=p.second;
		rt=merge(rt,v);
	}
	Ans[d[u]]-=cnt-n-1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		char opt[3];
		scanf("%d%d",&u,&v);
		scanf("%s",opt);
		int c=opt[0]-'a';
		g[u].push_back(make_pair(v,c));
	}
	d[1]=1;
	build(1);
	for(int i=1;i<=n;++i)Ans[i]=n;
	dfs(1);
	int p=1;
	//for(int i=1;i<=n;++i)cerr<<Ans[i]<<endl;
	for(int i=2;i<=n;++i)if(Ans[i]&&Ans[i]<Ans[p])p=i;
	printf("%d\n%d\n",Ans[p],p);
}