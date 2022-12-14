#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

struct UnionFind
{
	int par[1001000],rank[1001000];
	void init(int N)
	{
		for(int i=0;i<N;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};

UnionFind uf;

vector<int> G[1001000];
int cnt[1001000]={};

int odd[1001000];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	uf.init(N);
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		uf.unite(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
		cnt[u]++;cnt[v]++;
	}
	memset(odd,-1,sizeof(odd));
	for(int i=0;i<N;i++)
	{
		if(cnt[i]==0) continue;
		int p=uf.find(i);
		if(odd[p]==-1) odd[p]=0;
		if(cnt[i]%2==1) odd[p]++;
	}
	if(odd[uf.find(0)]==-1) odd[uf.find(0)]=0;
	int ans=0;
	int com=0;
	int id;
	for(int i=0;i<N;i++)
	{
		if(odd[i]==-1) continue;
		com++;
		id=i;
	}
	if(com==1)
	{
		ans=odd[id]/2;
	}
	else
	{
		ans=com;
		for(int i=0;i<N;i++)
		{
			if(odd[i]==-1) continue;
			ans+=(max(odd[i]-2,0)/2);
		}
	}
	printf("%d\n",ans);
	return 0;
}