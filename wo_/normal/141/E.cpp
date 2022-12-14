#include<cstdio>
#include<vector>

using namespace std;

struct edge{
	int u,v;
	bool which;//true:S,false:M
	int id;
	edge(){}
	edge(int a,int b,bool c,int d):u(a),v(b),which(c),id(d){}
};

struct UnionFind{
	int par[1010];
	int rank[1010];
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

UnionFind uf,allS;
vector<edge> ss,ms;

vector<edge> ans;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	if(N%2==0)
	{
		printf("-1\n");
		return 0;
	}
	uf.init(N),allS.init(N);
	for(int i=0;i<M;i++)
	{
		int u,v;
		char ch[2];
		scanf("%d%d%s",&u,&v,ch);
		u--;v--;
		if(u==v) continue;
		if(ch[0]=='S')
		{
			ss.push_back(edge(u,v,true,i+1));
		}
		else ms.push_back(edge(u,v,false,i+1));
	}
	int m=(N-1)/2;
	if(ms.size()<m||ss.size()<m)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<ss.size();i++)
	{
		allS.unite(ss[i].u,ss[i].v);
	}
	for(int i=0;i<ms.size();i++)
	{
		if(!allS.same(ms[i].u,ms[i].v))
		{
			allS.unite(ms[i].u,ms[i].v);
			uf.unite(ms[i].u,ms[i].v);
			ans.push_back(ms[i]);
		}
	}
	for(int i=0;i<ms.size();i++)
	{
		if(!uf.same(ms[i].u,ms[i].v))
		{
			uf.unite(ms[i].u,ms[i].v);
			ans.push_back(ms[i]);
		}
		if(ans.size()==m) break;
	}
	if(ans.size()!=m)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<ss.size();i++)
	{
		if(!uf.same(ss[i].u,ss[i].v))
		{
			uf.unite(ss[i].u,ss[i].v);
			ans.push_back(ss[i]);
		}
	}
	if(ans.size()!=N-1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d%c",ans[i].id,i==(int)ans.size()-1?'\n':' ');
	}
	return 0;
}