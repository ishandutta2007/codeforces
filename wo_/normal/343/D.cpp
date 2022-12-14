#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[500500];

int pre[500500],pos[500500];
int par[500500];

struct segtree{
	int N;
	bool all[1048576];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<N*2;i++) all[i]=false;
	}
	void fi(int l,int r,int k,int a,int b)
	{
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r)
		{
			all[k]=true;
			return;
		}
		fi(l,r,k*2,a,(a+b)/2);
		fi(l,r,k*2+1,(a+b)/2,b);
	}
	void em(int id)
	{
		id+=N;
		int tmp=id;
		int hi=1<<25;
		tmp/=2;
		while(tmp>0)
		{
			if(all[tmp]) hi=tmp;
			tmp/=2;
		}
		if(hi==(1<<25))
		{
			all[id]=false;
			return;
		}
		all[id]=false;
		while(id/2>0)
		{
			if(hi<id) all[id^1]=true;
			all[id/2]=false;
			id/=2;
		}
	}
	bool check(int l,int r,int k,int a,int b)
	{
		if(r<=a||b<=l) return true;
		if(l<=a&&b<=r) return all[k];
		if(all[k]) return true;
		return check(l,r,k*2,a,(a+b)/2)&check(l,r,k*2+1,(a+b)/2,b);
	}
	bool check(int l,int r)
	{
		return check(l,r,1,0,N);
	}
	void fi(int v)
	{
		int l=pre[v],r=pos[v];
		bool flg=check(l,r);
		fi(l,r,1,0,N);
		if(flg==false&&v!=0) em(pre[par[v]]);
	}
};

segtree seg;

int c=0;
void dfs(int v,int p)
{
	par[v]=p;
	pre[v]=c;
	c++;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v);
	}
	pos[v]=c;
}

int main()
{
	int N;
	scanf("%d",&N);
	seg.init(N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,-1);
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int c,v;
		scanf("%d%d",&c,&v);
		v--;
		if(c==1)
		{
			seg.fi(v);
		}
		else if(c==2)
		{
			seg.em(pre[v]);
		}
		else
		{
			bool flg=seg.check(pre[v],pos[v]);
			if(flg) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}