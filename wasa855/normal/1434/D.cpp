#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int max(int x,int y,int z){return max(max(x,y),z);}
int min(int x,int y,int z){return min(min(x,y),z);}
int max(int a,int b,int c,int d){return max(a,b,max(c,d));}
#define N 1000005
vector<pii> G[N];
int dis[N],tin[N],tout[N],cnt,sum[N];
int n,m,W,u[N],v[N],w[N],id[N],dep[N];
void dfs(int u,int fa)
{
	tin[u]=++cnt; id[cnt]=u;
	dep[u]=dep[fa]+1;
	for(auto [v,w]:G[u])
	{
		if(v==fa) continue;
		sum[v]=sum[u]^w;
		dfs(v,u);
		id[++cnt]=u;
	}
	tout[u]=cnt;
}
struct Node
{
	int lm[2],mr[2],lmr[2],minn,maxn[2],tag;
};
Node t[N*4];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)/2)
void pushup(int u)
{
	t[u].minn=min(t[ls].minn,t[rs].minn);
	for(int i=0;i<2;i++)
	{
		t[u].maxn[i]=max(t[ls].maxn[i],t[rs].maxn[i]);
		t[u].lm[i]=max(t[ls].lm[i],t[rs].lm[i],t[ls].maxn[i]-2*t[rs].minn);
		t[u].mr[i]=max(t[ls].mr[i],t[rs].mr[i],t[rs].maxn[i]-2*t[ls].minn);
		t[u].lmr[i]=max(t[ls].lmr[i],t[rs].lmr[i],t[ls].lm[i]+t[rs].maxn[i],t[ls].maxn[i]+t[rs].mr[i]);
	}
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<2;++i) t[u].maxn[i]=t[u].lm[i]=t[u].mr[i]=t[u].lmr[i]=-inf;
		t[u].maxn[sum[id[l]]]=t[u].minn=dep[id[l]];
		t[u].lm[sum[id[l]]]=t[u].mr[sum[id[l]]]=-dep[id[l]];
		t[u].lmr[sum[id[l]]]=0;
		return ;
	}
	build(ls,l,mid),build(rs,mid+1,r);
	pushup(u);
}
void doit(int u)
{
	t[u].tag^=1;
	swap(t[u].maxn[0],t[u].maxn[1]);
	swap(t[u].lm[0],t[u].lm[1]);
	swap(t[u].mr[0],t[u].mr[1]);
	swap(t[u].lmr[0],t[u].lmr[1]);
}
void pushdown(int u)
{
	if(t[u].tag)
	{
		doit(ls),doit(rs);
		t[u].tag=0;
	}
}
void update(int u,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		doit(u);
		return ;
	}
	pushdown(u);
	if(mid>=L) update(ls,l,mid,L,R);
	if(mid<R) update(rs,mid+1,r,L,R);
	pushup(u);
}
int query(){return max(t[1].lmr[0],t[1].lmr[1]);}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		G[u[i]].eb(v[i],w[i]),G[v[i]].eb(u[i],w[i]);
	}
	dfs(1,0);
	build(1,1,cnt);
	for(int i=1;i<n;i++) if(dep[u[i]]<dep[v[i]]) swap(u[i],v[i]);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int d=read();
		update(1,1,cnt,tin[u[d]],tout[u[d]]);
		printf("%d\n",query());
	}
	return 0;
}