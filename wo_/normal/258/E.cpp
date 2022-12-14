#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> G[100100];

struct segtree{
	int N,Na;
	int dat[262144];
	int minval[262144];
	int mincnt[262144];
	void init(int N_)
	{
		Na=N_;
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++)
		{
			dat[i]=0;
			minval[i]=0;
		}
		for(int i=N;i<=N*2-1;i++) mincnt[i]=1;
		for(int i=N-1;i>=1;i--) mincnt[i]=mincnt[i*2]+mincnt[i*2+1];
	}
	void setchild(int k)
	{
		if(k>=N) return;
		minval[k*2]+=dat[k];
		minval[k*2+1]+=dat[k];
		dat[k*2]+=dat[k];
		dat[k*2+1]+=dat[k];
		dat[k]=0;
	}
	void update(int l,int r,int x,int k,int a,int b)
	{
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r)
		{
			dat[k]+=x;
			minval[k]+=x;
			return;
		}
		//setchild(k);
		update(l,r,x,k*2,a,(a+b)/2);
		update(l,r,x,k*2+1,(a+b)/2,b);
		int m=min(minval[k*2],minval[k*2+1]);
		int cnt=0;
		if(minval[k*2]==m) cnt+=mincnt[k*2];
		if(minval[k*2+1]==m) cnt+=mincnt[k*2+1];
		minval[k]=m+dat[k];
		mincnt[k]=cnt;
	}
	void update(int l,int r,int x)
	{
		update(l,r,x,1,0,N);
	}
	int get()
	{
		if(minval[1]!=0) return Na-1;
		int res=N-mincnt[1];
		if(res>0) res--;
		return res;
	}
};

segtree seg;

int pre[100100],pos[100100];

int c=0;
void dfs(int v,int p)
{
	pre[v]=c;
	c++;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v);
	}
	pos[v]=c;
}

vector<int> query[100100];

int ans[100100];
int N,M;

void dfs2(int v,int p)
{
	int a=pre[v],b=pos[v];
	for(int i=0;i<query[v].size();i++)
	{
		int l=pre[query[v][i]],r=pos[query[v][i]];
		seg.update(a,b,1);
		seg.update(l,r,1);
	}
	ans[v]=seg.get();
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]!=p) dfs2(G[v][i],v);
	}
	for(int i=0;i<query[v].size();i++)
	{
		int l=pre[query[v][i]],r=pos[query[v][i]];
		seg.update(a,b,-1);
		seg.update(l,r,-1);
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	dfs(0,-1);
	seg.init(N);
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		query[u].push_back(v);
		query[v].push_back(u);
	}
	dfs2(0,-1);
	for(int i=0;i<N;i++)
	{
		printf("%d%c",ans[i],i==N-1?'\n':' ');
	}
	return 0;
}