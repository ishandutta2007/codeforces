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
#define int long long
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
#define N 200005
vector<int> G[N];
int dis[N],tin[N],tout[N],cnt;
int n,m,W,u[N],v[N],w[N],id[N],dep[N];
void dfs(int u,int fa)
{
	tin[u]=++cnt; id[cnt]=u;
	dep[u]=dep[fa]+1;
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		id[++cnt]=u;
	}
	tout[u]=cnt;
}
struct Node
{
	int w,m,lm,mr,lmr,tag;
};
Node t[N*4];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)/2)
void pushup(int u)
{
	t[u].w=max(t[ls].w,t[rs].w);
	t[u].m=min(t[ls].m,t[rs].m);
	t[u].lm=max(t[ls].lm,t[rs].lm,t[ls].w-2*t[rs].m);
	t[u].mr=max(t[ls].mr,t[rs].mr,t[rs].w-2*t[ls].m);
	t[u].lmr=max(t[ls].lmr,t[rs].lmr,t[ls].lm+t[rs].w,t[ls].w+t[rs].mr);
}
void Add(int u,int w)
{
	t[u].w+=w,t[u].m+=w,t[u].lm-=w,t[u].mr-=w;
	t[u].tag+=w;
}
void pushdown(int u)
{
	Add(ls,t[u].tag),Add(rs,t[u].tag);
	t[u].tag=0;
}
void update(int u,int l,int r,int L,int R,int d)
{
	if(L<=l&&r<=R)
	{
		Add(u,d);
		return ;
	}
	pushdown(u);
	if(mid>=L) update(ls,l,mid,L,R,d);
	if(mid<R) update(rs,mid+1,r,L,R,d);
	pushup(u);
}
int query(){return t[1].lmr;}
signed main()
{
	cin>>n>>m>>W;
	for(int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		G[u[i]].pb(v[i]),G[v[i]].pb(u[i]);
	}
	dfs(1,0);
	for(int i=1;i<n;i++)
	{
		if(dep[u[i]]<dep[v[i]]) swap(u[i],v[i]);
		update(1,1,cnt,tin[u[i]],tout[u[i]],w[i]);
	}
	int las=0;
	for(int i=1;i<=m;i++)
	{
		int d=(read()+las)%(n-1)+1,_w=(read()+las)%W;
		// printf("%d %d\n",d,_w);
		update(1,1,cnt,tin[u[d]],tout[u[d]],_w-w[d]);
		w[d]=_w;
		las=query();
		printf("%lld\n",las);
	}
	return 0;
}