#pragma GCC optimize("Ofast")
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
//void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 400005
vector<int> G[N];
int n,dep[N],siz[N],son[N],top[N],fa[N],dfn[N],rev[N],dfscnt;
void addedge(int u,int v) {G[u].pb(v),G[v].pb(u);}
void dfs1(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs1(v,u),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp,dfn[u]=++dfscnt,rev[dfscnt]=u;
	if(!son[u]) return ;
	dfs2(son[u],tp);
	for(int v:G[u]) if(v!=fa[u]&&v!=son[u]) dfs2(v,v);
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
		else v=fa[top[v]];
	}
	return dep[u]>dep[v]?v:u;
}
int dis(int u,int v) {return dep[u]+dep[v]-dep[lca(u,v)]*2;}
int jump(int u,int d)
{
//	printf("$ %d %d - ** %d ",u,d);
	while(dep[u]-dep[top[u]]+1<=d) d-=dep[u]-dep[top[u]]+1,u=fa[top[u]];
//	printf("- %d %d\n",u,rev[dfn[u]-d]);
	return rev[dfn[u]-d];
}
int go(int u,int v,int d)
{
	int l=lca(u,v),ans;
	if(dep[u]-dep[l]>=d) ans=jump(u,d);
	else ans=jump(v,dep[u]+dep[v]-dep[l]*2-d);
//	printf("%d %d %d - %d\n",u,v,d,ans);
	return ans;
}
namespace DFS
{
	int dep[N],fa[N][20],dist[N][20],val[N],g[N],siz[N],vis[N],totsiz,minval,minn;
	int curdep=0;
	void getrt(int u,int f)
	{
		int maxn=0; siz[u]=1;
		for(int v:G[u])
		{
			if(vis[v]||v==f) continue;
			getrt(v,u),siz[u]+=siz[v];
			maxn=max(maxn,siz[v]);
		}
		maxn=max(maxn,totsiz-siz[u]);
		if(maxn<minval) minval=maxn,minn=u;
	}
	void getsiz(int u,int f)
	{
		siz[u]=1;
		for(int v:G[u])
		{
			if(vis[v]||v==f) continue;
			getsiz(v,u),siz[u]+=siz[v];
		}
	}
	void build(int u)
	{
		curdep++;
//		printf("%d %d\n",u,curdep);
		getsiz(u,0),vis[u]=1;
		for(int v:G[u])
		{
			if(vis[v]) continue;
			totsiz=siz[v],minval=inf;
			getrt(v,u);
			fa[minn][1]=u,build(minn);
		}
		curdep--;
	}
	void init()
	{
		totsiz=n,minval=inf; getrt(1,0);
		build(minn);
		for(int i=2;i<=19;i++) for(int j=1;j<=n*2;j++) fa[j][i]=fa[fa[j][i-1]][1];
		for(int i=1;i<=n*2;i++) fa[i][0]=i;
		for(int i=1;i<=n*2;i++) for(int j=1;j<=19;j++)
		{
			if(fa[i][j]) dist[i][j]=dis(i,fa[i][j]);
			else break;
		}
//		for(int i=1;i<=n*2-1;i++) for(int j=0;j<=3;j++) printf("%d%c",fa[i][j]," \n"[j==3]);
//		for(int i=1;i<=n*2-1;i++) for(int j=0;j<=3;j++) printf("%d%c",dist[i][j]," \n"[j==3]);
		memset(siz,0,sizeof(siz));
	}
	void clear()
	{
		memset(siz,0,sizeof(siz));
		memset(val,0,sizeof(val));
		memset(g,0,sizeof(g));
	}
	void update(int u,int v)
	{
//		printf("%d %d\n",u,v);
		int las=0;
		for(int i=0;i<=19;i++)
		{
			if(fa[u][i])
			{
				int nd=fa[u][i];
				siz[nd]+=v,val[nd]+=dist[u][i]*v;
				if(las) g[las]+=dist[u][i]*v;
				las=nd;
			}
			else break;
		}
	}
	int query(int u)
	{
		int ans=0,las=0;
		for(int i=0;i<=19;i++)
		{
			if(fa[u][i])
			{
				int nd=fa[u][i];
				int r=dist[u][i]*(siz[nd]-siz[las])+val[nd]-g[las];
				ans+=r; las=nd;
			}
			else break;
		}
		return ans;
	}
};
using DFS::update;
using DFS::query;
struct Cir
{
	int v,r;
	Cir(int x=0,int y=0) {v=x,r=y;}
};
pair<Cir,int> merge(Cir x,Cir y)
{
	int d=dis(x.v,y.v);
	if(d+y.r<=x.r) return {x,1};
	if(d+x.r<=y.r) return {y,3};
	int rt=go(x.v,y.v,(y.r+d-x.r)/2);
	return {Cir(rt,(y.r+d+x.r)/2),2};
}
int ans=0;
Cir a[N]; int presum[N];
int L[N],R[N];
void solve(int l,int r)
{
	if(l==r) return ;
	int mid=(l+r)/2;
	a[mid]=Cir(mid,0),a[mid+1]=Cir(mid+1,0);
	for(int i=mid-1;i>=l;i--) a[i]=merge(a[i+1],Cir(i,0)).fir;
	for(int i=mid+2;i<=r;i++) a[i]=merge(a[i-1],Cir(i,0)).fir;
	presum[mid]=0; for(int i=mid+1;i<=r;i++) presum[i]=presum[i-1]+a[i].r;
	int cur=mid;
	for(int i=mid;i>=l;i--)
	{
		while(cur+1<=r&&merge(a[i],a[cur+1]).sec==1) cur++;
		L[i]=cur+1;
	}
	cur=mid+1;
	for(int i=mid;i>=l;i--)
	{
		while(cur<=r&&merge(a[i],a[cur]).sec<=2) cur++;
		R[i]=cur-1;
	}
	int curl=mid+1,curr=mid;
	for(int i=mid;i>=l;i--)
	{
		while(curr<R[i]) curr++,update(a[curr].v,1);
		while(curl<L[i]) update(a[curl].v,-1),curl++;
		ans+=a[i].r*(L[i]-mid-1)*2;
		ans+=a[i].r*(R[i]-L[i]+1)+query(a[i].v)+presum[R[i]]-presum[L[i]-1];
		ans+=(presum[r]-presum[R[i]])*2;
	}
	for(int i=curl;i<=curr;i++) update(a[i].v,-1);
	solve(l,mid),solve(mid+1,r);
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		addedge(u,n+i),addedge(v,n+i);
//		printf("%d %d\n%d %d\n",u,n+i,v,n+i);
	}
	dfs1(1,0),dfs2(1,1);
	DFS::init();
	solve(1,n);
	ans/=2;
	cout<<ans<<endl;
	return 0;
}