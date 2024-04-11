#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct BIT{
	vector<int> dat;
	void init(int N_)
	{
		dat=vector<int>(N_+1);
	}
	void add(int i,int x)
	{
		while(i<dat.size())
		{
			dat[i]+=x;
			i+=(i&(-i));
		}
	}
	int sum(int i)
	{
		int res=0;
		while(i>0)
		{
			res+=dat[i];
			i-=(i&(-i));
		}
		return res;
	}
};


vector<int> G[100100];
int root=0;

BIT bit[100100];
int vid[100100];//[vid]=bit_id

int dep[100100],top_par[100100];

int c=0;
void dfs(int v,int p,int t,int d)
{
	top_par[v]=t;
	dep[v]=d;
	bool flg=false;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v,t,d+1);
		flg=true;
	}
	if(flg==false)
	{
		bit[c].init(d);
		vid[t]=c;
		c++;
	}
}

int es[100100][2];
int color[100100];

int solve(int u,int v)
{
	if(u==v) return 0;
	if(v==root) swap(u,v);
	if(u==root)
	{
		int tv=top_par[v];
		int id=vid[tv];
		int d=dep[v];
		if(bit[id].sum(d)==0) return d;
		else return -1;
	}
	if(top_par[u]==top_par[v])
	{
		int i=top_par[v];
		int id=vid[i];
		int d1=dep[u],d2=dep[v];
		if(bit[id].sum(d1)==bit[id].sum(d2)) return max(d2-d1,d1-d2);
		else return -1;
	}
	int ud=solve(root,u);
	int vd=solve(root,v);
	if(ud==-1||vd==-1) return -1;
	return ud+vd;
}

void update(int id,int which)//1:white,-1:black
{
	int u=es[id][0],v=es[id][1];
	if(v==root) swap(u,v);
	int i=top_par[v];
	int ii=vid[i];
	int d=max(dep[v],dep[u]);
	bit[ii].add(d,which);
	if(which==1) color[id]=1;
	else color[id]=0;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
		es[i][0]=u,es[i][1]=v;
	}
	for(int i=0;i<N;i++) if(G[i].size()>2) root=i;
	for(int i=0;i<G[root].size();i++)
	{
		dfs(G[root][i],root,G[root][i],1);
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int id;
			scanf("%d",&id);
			id--;
			if(color[id]==1) update(id,-1);
		}
		else if(type==2)
		{
			int id;
			scanf("%d",&id);
			id--;
			if(color[id]==0) update(id,1);
		}
		else
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			printf("%d\n",solve(u,v));
		}
	}
	return 0;
}