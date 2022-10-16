#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef double db;

int N;
vector<pii> e[maxn*9+5];
ll dis[maxn*9+5];
bool mark[maxn*9+5];

struct segt
{
	#define ls i*2
	#define rs i*2+1
	int id[maxn*4+5],dir;
	void build(int i,int l,int r)
	{
		if(l==r) id[i]=l;
		else
		{
			id[i]=++N;
			int mid=(l+r)>>1;
			build(ls,l,mid);
			build(rs,mid+1,r);
			if(dir==0) e[id[i]].pb(mp(id[ls],0)),e[id[i]].pb(mp(id[rs],0));
			else e[id[ls]].pb(mp(id[i],0)),e[id[rs]].pb(mp(id[i],0));
		}
	}
	void add(int i,int l,int r,int ql,int qr,int x,int w)
	{
		if(ql<=l && r<=qr)
		{
			if(dir==0) e[x].pb(mp(id[i],w));
			else e[id[i]].pb(mp(x,w));
			return;
		}
		if(r<ql || qr<l) return;
		int mid=(l+r)>>1;
		add(ls,l,mid,ql,qr,x,w);
		add(rs,mid+1,r,ql,qr,x,w);
	}
}t[2];

int main()
{
	int n,Q,s; scanf("%d%d%d",&n,&Q,&s);
	N=n;
	t[0].dir=0; t[1].dir=1;
	t[0].build(1,1,n);
	t[1].build(1,1,n);
	rep(i,1,Q)
	{
		int op; scanf("%d",&op);
		if(op==1) 
		{
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			e[u].pb(mp(v,w));
		}
		else
		{
			int u,l,r,w; scanf("%d%d%d%d",&u,&l,&r,&w);
			op-=2;
			t[op].add(1,1,n,l,r,u,w);
		}
	}
	rep(i,1,N) dis[i]=1ll<<60;
	priority_queue<pli,vector<pli>,greater<pli> > q;
	dis[s]=0;
	q.push(mp(0,s));
	while(q.size())
	{
		int now=q.top().SE; q.pop();
		if(mark[now]) continue;
		mark[now]=1;
		for(auto it: e[now])
		{
			int v=it.FI,w=it.SE;
			if(dis[v]>dis[now]+w) dis[v]=dis[now]+w,q.push(mp(dis[v],v));
		}
	}
	rep(i,1,n) if(dis[i]==1ll<<60) dis[i]=-1;
	rep(i,1,n) printf("%lld%c",dis[i]," \n"[i==n]);
	return 0;
}