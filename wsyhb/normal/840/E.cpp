#include<bits/stdc++.h>
using namespace std;
const int max_n=5e4+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],E;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E;
	End[++E]=x,Next[E]=Last[y],Last[y]=E;
}
namespace Trie
{
	const int max_tot=4097+5;
	int son[max_tot][2],tot=1;
	inline void clear()
	{
		for(int i=1;i<=tot;++i)
			son[i][0]=son[i][1]=0;
		tot=1;
	}
	inline void insert(int v)
	{
		int now=1;
		for(int i=15;i>=0;--i)
		{
			int to=v>>i&1;
			if(!son[now][to])
				son[now][to]=++tot;
			now=son[now][to];
		}
	}
	inline int query(int v)
	{
		int now=1,ans=0;
		for(int i=15;i>=0;--i)
		{
			int to=v>>i&1;
			if(son[now][to^1])
			{
				now=son[now][to^1];
				ans|=1<<i;
			}
			else
				now=son[now][to];
		}
		return ans;
	}
}
int a[max_n],dep[max_n],fath[max_n],anc[max_n],ans[max_n][200];
typedef pair<int,int> P; 
vector<P> deal[max_n];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	fath[x]=fa;
	if(dep[x]>=256)
	{
		deal[x].push_back(P(x,0));
		int now=x;
		for(int t=1;t<=256;++t)
			now=fath[now];
		anc[x]=now;
		for(int t=1;dep[now]>=256;++t)
		{
			deal[now].push_back(P(x,t));
			now=anc[now];
		}
	}
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs(y,x);
	}
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs(1,0);
	for(int x=1;x<=n;++x)
	{
		if(dep[x]<256)
			continue;
		Trie::clear();
		for(int i=0,now=x;i<256;++i,now=fath[now])
			Trie::insert(i^a[now]);
		for(vector<P>::iterator it=deal[x].begin();it!=deal[x].end();++it)
			ans[it->first][it->second]=Trie::query(it->second*256);
	}
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int Ans=0,now=v;
		for(int i=0;dep[now]-dep[u]+1>=256;++i)
		{
			Ans=max(Ans,ans[v][i]);
			now=anc[now];
		}
		while(dep[now]>=dep[u])
		{
			Ans=max(Ans,a[now]^(dep[v]-dep[now]));
			now=fath[now];
		}
		printf("%d\n",Ans); 
	}
	return 0;
}