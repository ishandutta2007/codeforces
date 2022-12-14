#include<cstdio>
#include<vector>

using namespace std;

struct UnionFind{
	int par[550];
	void init(int N)
	{
		for(int i=0;i<N;i++) par[i]=i;
	}
	int find(int v)
	{
		if(v==par[v]) return v;
		return par[v]=find(par[v]);
	}
	void unite(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v) return;
		par[u]=v;
	}
	bool same(int u,int v)
	{
		return find(u)==find(v);
	}
};

UnionFind uf;

int u[10010],v[10010];

vector<int> le,ri;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",u+i,v+i);
		u[i]--;v[i]--;
	}
	uf.init(N);
	for(int i=0;i<M;i++)
	{
		if(!uf.same(u[i],v[i]))
		{
			le.push_back(i);
			uf.unite(u[i],v[i]);
		}
	}
	uf.init(N);
	for(int i=M-1;i>=0;i--)
	{
		if(!uf.same(u[i],v[i]))
		{
			ri.push_back(i);
			uf.unite(u[i],v[i]);
		}
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		uf.init(N);
		int l,r;
		scanf("%d%d",&l,&r);
		l--;r--;
		int cnt=0;
		for(int j=0;j<le.size();j++)
		{
			if(le[j]>=l) break;
			if(!uf.same(u[le[j]],v[le[j]]))
			{
				uf.unite(u[le[j]],v[le[j]]);
				cnt++;
			}
		}
		for(int j=0;j<ri.size();j++)
		{
			if(ri[j]<=r) break;
			if(!uf.same(u[ri[j]],v[ri[j]]))
			{
				uf.unite(u[ri[j]],v[ri[j]]);
				cnt++;
			}
		}
		printf("%d\n",N-cnt);
	}
	return 0;
}