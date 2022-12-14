#include<cstdio>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> PP;

struct UnionFind{
	int par[100100];
	int rank[100100];
	void init(int N)
	{
		for(int i=0;i<N;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int v)
	{
		if(par[v]==v) return v;
		return par[v]=find(par[v]);
	}
	void unite(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v) return;
		if(rank[u]<rank[v]) par[u]=v;
		else par[v]=u;
		if(rank[u]==rank[v]) rank[u]++;
	}
	bool same(int u,int v)
	{
		return find(u)==find(v);
	}
};

UnionFind uf;

int N,M;

int ans[100100];

vector<PP> edges[1100100];

vector<int> useVs;
vector<P> G[100100];
int par[100100],pre[100100],low[100100];
bool visited[100100];

bool used[100100];

int c=0;
void dfs(int v,int p)
{
	visited[v]=true;
//	printf("dfs %d %d\n",v,c);
	par[v]=p;
	pre[v]=c;
	c++;
	low[v]=pre[v];
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i].first;
		if(visited[u]==false)
		{
			used[G[v][i].second]=true;
			dfs(u,v);
			low[v]=min(low[v],low[u]);
		}
		else if(used[G[v][i].second]==false)
		{
			low[v]=min(low[v],pre[u]);
		}
	}
}

bool good[100100];

void solve(int w)
{
	useVs.clear();
	for(int i=0;i<edges[w].size();i++)
	{
		int u=edges[w][i].first.first;
		int v=edges[w][i].first.second;
//		printf("%d %d-%d ",w,u,v);
		used[edges[w][i].second]=false;
		u=uf.find(u),v=uf.find(v);
//		printf("%d-%d\n",u,v);
		if(u==v)
		{
			good[i]=false;
			ans[edges[w][i].second]=2;
		}
		else
		{
			useVs.push_back(u);
			useVs.push_back(v);
			good[i]=true;
		}
	}
	sort(useVs.begin(),useVs.end());
	useVs.erase(unique(useVs.begin(),useVs.end()),useVs.end());
//	if(useVs.size()!=0) printf("solve %d\n",w);
//	printf("using\n");
	for(int i=0;i<useVs.size();i++)
	{
		int v=useVs[i];
		par[v]=-1;pre[v]=-1;low[v]=-1;visited[v]=false;
		G[v].clear();
//		printf("%d ",useVs[i]);
	}
//	printf("\n");
	for(int i=0;i<edges[w].size();i++)
	{
		if(good[i]==false) continue;
		int u=edges[w][i].first.first,v=edges[w][i].first.second;
		u=uf.find(u);
		v=uf.find(v);
//		printf("con %d-%d\n",u,v);
		G[v].push_back(P(u,edges[w][i].second));
		G[u].push_back(P(v,edges[w][i].second));
	}
	for(int i=0;i<useVs.size();i++)
	{
		int v=useVs[i];
//		printf("%d-",v);
//		for(int j=0;j<G[v].size();j++)
//		{
//			printf("a%d ",G[v][j].first);
//		}
//		printf("\n");
	}
	c=0;
	for(int i=0;i<useVs.size();i++)
	{
		if(par[useVs[i]]==-1)
		{
			dfs(useVs[i],-1);
		}
	}
//	if(w==1)
//	{
//		for(int i=0;i<useVs.size();i++)
//		{
//			int v=useVs[i];
//			printf("%d %d %d\n",v,pre[v],low[v]);
//		}
//	}
	for(int i=0;i<edges[w].size();i++)
	{
		if(good[i]==false) continue;
		int u=edges[w][i].first.first,v=edges[w][i].first.second;
		u=uf.find(u),v=uf.find(v);
		if(par[u]!=v&&par[v]!=u)
		{
			ans[edges[w][i].second]=1;
		}
		else
		{
			if(par[v]==u) swap(u,v);
			if(pre[v]>=low[u]){
				ans[edges[w][i].second]=1;
//				printf("k\n");
			}
			else ans[edges[w][i].second]=0;
//			printf("id=%d %d-%d\n",edges[w][i].second,u,v);
		}
	}
	for(int i=0;i<edges[w].size();i++)
	{
		if(good[i]==false) continue;
		int u=edges[w][i].first.first,v=edges[w][i].first.second;
		u=uf.find(u),v=uf.find(v);
		uf.unite(u,v);
//		printf("unite %d %d\n",u,v);
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	uf.init(N);
	for(int i=0;i<M;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u--;v--;
		edges[w].push_back(PP(P(u,v),i));
	}
	for(int i=1;i<=1000000;i++)
	{
		if(edges[i].size()>=1) solve(i);
	}
	for(int i=0;i<M;i++)
	{
		if(ans[i]==0) printf("any\n");
		else if(ans[i]==1) printf("at least one\n");
		else printf("none\n");
	}
	return 0;
}