#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

struct UnionFind{
	int N;
	int par[100100];
	void init(int N_)
	{
		N=N_;
		for(int i=0;i<N;i++) par[i]=i;
	}
	int find(int x)
	{
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int p,int c)
	{
		p=find(p);c=find(c);
		par[c]=p;
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};

int a[100100],b[100100],lca[100100];

vector<P> query[100100];
bool used[100100];

vector<int> G[100100];

UnionFind uf;

map<P,int> ids;
vector<int> vs;

void dfs(int v,int p)
{
	vs.push_back(v);
	bool go=false;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		go=true;
		dfs(G[v][i],v);
		vs.push_back(v);
	}
	used[v]=true;
	for(int i=0;i<query[v].size();i++)
	{
		if(used[query[v][i].first]==true)
		{
			lca[query[v][i].second]=uf.find(query[v][i].first);
		}
	}
	//if(go) vs.push_back(v);
	if(p==-1) return;
	uf.unite(p,v);
	return;
}

vector<int> invs[100100];

int cnt[200200];

bool saw[100100];

int ans[100100];

int main()
{
	int N,K;
	scanf("%d",&N);
	uf.init(N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		if(a>b) swap(a,b);
		ids[P(a,b)]=i;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d%d",a+i,b+i);
		a[i]--;b[i]--;
		query[a[i]].push_back(P(b[i],i));
		query[b[i]].push_back(P(a[i],i));
	}
	memset(used,false,sizeof(used));
	dfs(0,-1);
	for(int i=0;i<vs.size();i++)
	{
		invs[vs[i]].push_back(i);
	}
	/*
	printf("vs\n");
	for(int i=0;i<vs.size();i++)
	{
		printf("%d ",vs[i]);
	}
	printf("\n");
	for(int i=0;i<K;i++)
	{
		printf("%d %d %d\n",a[i],b[i],lca[i]);
	}
	*/
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<K;i++)
	{
		int A=a[i],B=b[i],L=lca[i];
		int Aid=invs[A][0],Bid=invs[B][0],Lid=invs[L][0];
		cnt[Lid]+=2;
		cnt[Aid]--;
		cnt[Bid]--;
	}
	for(int i=1;i<=2*N-2;i++)
	{
		cnt[i]+=cnt[i-1];
	}
	memset(saw,false,sizeof(saw));
	for(int i=0;i<2*N-2;i++)
	{
		int u=vs[i],v=vs[i+1];
		if(u>v) swap(u,v);
		int eid=ids[P(u,v)];
		if(saw[eid]==false)
		{
			ans[eid]+=cnt[i];
			saw[eid]=true;
		}
		else
		{
			ans[eid]-=cnt[i];
		}
	}
	for(int i=0;i<N-1;i++)
	{
		printf("%d%c",ans[i],i==N-2?'\n':' ');
	}
	return 0;
}