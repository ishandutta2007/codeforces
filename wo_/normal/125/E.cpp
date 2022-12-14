#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

struct edge{
	int cost;
	int u,v;
	double cost2;
	int id;
	edge(){}
	edge(int a,int b,double c,int d):u(a),v(b),cost(c),id(d){}
};

bool cmp(const edge &e1,const edge &e2)
{
	return e1.cost2<e2.cost2;
}

struct UnionFind{
	int par[5500];
	int rank[5500];
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

edge es[100100],tmp[100100];
edge ans[5500];

UnionFind uf;

int N,M,K;

P check(double w)
{
	for(int i=0;i<M;i++)
	{
		tmp[i]=es[i];
		if(es[i].u==0)
		{
			tmp[i].cost2=tmp[i].cost+w;
		}
		else
		{
			tmp[i].cost2=tmp[i].cost;
		}
	}
	sort(tmp,tmp+M,cmp);
	uf.init(N);
	int weight=0,cnt=0;
	int c=0;
	for(int i=0;i<M;i++)
	{
		int u=tmp[i].u,v=tmp[i].v;
		if(uf.same(u,v)) continue;
		uf.unite(u,v);
		if(u==0)
		{
			cnt++;
		}
		weight+=tmp[i].cost;
		ans[c]=tmp[i];
		c++;
	}
	return P(weight,cnt);
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		if(a>b) swap(a,b);
		es[i]=edge(a,b,c,i);
	}
	double lb=-100000,ub=100000;
	bool ok=false;
	for(int stage=0;stage<100;stage++)
	{
		double mid=(ub+lb)/2;
		P p=check(mid);
		if(p.second>K) lb=mid;
		else if(p.second==K)
		{
			lb=mid;
			ok=true;
			break;
		}
		else ub=mid;
	}
	P p=check(lb);
	if(!ok) printf("-1\n");
	else
	{
		printf("%d\n",N-1);
		for(int i=0;i<N-1;i++)
		{
			printf("%d%c",ans[i].id+1,i==N-2?'\n':' ');
		}
	}
	return 0;
}