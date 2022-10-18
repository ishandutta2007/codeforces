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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 800005
struct Node
{
	int x,y;
	Node(int a=0,int b=0) {x=a,y=b;}
	bool operator < (const Node &o) const {return x<o.x||(x==o.x&&y<o.y);}
};
bool operator == (Node x,Node y) {return x.x==y.x&&x.y==y.y;}
bool operator != (Node x,Node y) {return x.x!=y.x||x.y!=y.y;}
Node jump(Node _,int p)
{
	int x=_.x,y=_.y;
	for(int i=0;i<=30&&p;i++)
	{
		if(x>>i&1)
		{
			if(p>(1<<i)) p-=(1<<i),x^=(1<<i);
			else x-=p,p=0;
		}
		if(y>>i&1)
		{
			if(p>(1<<i)) p-=(1<<i),y^=(1<<i);
			else y-=p,p=0;
		}
	}
	return Node(x,y);
}
Node lca(Node _1,Node _2)
{
	int x1=_1.x,y1=_1.y,x2=_2.x,y2=_2.y;
	int ax=0,ay=0;
	for(int i=30;i>=0;i--)
	{
		int tx1=x1>>i&1,ty1=y1>>i&1,tx2=x2>>i&1,ty2=y2>>i&1;
		int A=tx1*2+ty1,B=tx2*2+ty2;
		if(A==B) ax|=tx1<<i,ay|=ty1<<i;
		else
		{
			if(A==1) x1=0,y1=(1<<i)-1;
			else if(A==2) x1=(1<<i)-1,y1=0;
			if(B==1) x2=0,y2=(1<<i)-1;
			else if(B==2) x2=(1<<i)-1,y2=0;
		}
	}
	return Node(ax,ay);
}
Node a[N],b[N];
int n;
bool cmp(Node x,Node y)
{
	if(x==y) return 0;
	Node r=lca(x,y);
	if(r==x) return 1;
	if(r==y) return 0;
	r.x++;
	if(lca(x,r)==r) return 1;
	else return 0;
}
Node t[N];
Node st[N]; int tp;
map<Node,int> id; int idcnt;
Node rev[N];
vector<int> G[N];
int dep(Node x) {return x.x+x.y;}
void addedge(Node x,Node y)
{
	if(!id[x]) id[x]=++idcnt,rev[idcnt]=x;
	if(!id[y]) id[y]=++idcnt,rev[idcnt]=y;
	int u=id[x],v=id[y];
	// printf("%d %d\n",u,v);
	// printf("(%d,%d) (%d,%d)\n",x.x,x.y,y.x,y.y);
	G[u].pb(v),G[v].pb(u);
}
int fa[N][20],dp[N];
void dfs(int u,int f)
{
	fa[u][0]=f,dp[u]=dp[f]+1;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dp[u]<dp[v]) swap(u,v);
	int go=dp[u]-dp[v];
	for(int i=0;i<=18;i++) if(go>>i&1) u=fa[u][i];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
	{
		if(fa[u][i]&&fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
int cnt[N];
void dfs2(int u,int f)
{
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs2(v,u),cnt[u]+=cnt[v];
	}
}
map<int,int> vis;
void dfs3(int u,int f)
{
	if(cnt[u])
	{
		vis[dep(rev[u])]^=1;
		if(f) vis[dep(rev[f])]^=1;
	}
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs3(v,u);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),b[i].x=read(),b[i].y=read();
	// for(int i=1;i<=n;i++)
	// {
		// Node r=lca(a[i],b[i]);
		// printf("%d %d\n",r.x,r.y);
	// }
	int qwqcnt=0;
	for(int i=1;i<=n;i++)
	{
		t[++qwqcnt]=a[i],t[++qwqcnt]=b[i];
		Node r=lca(a[i],b[i]);
		t[++qwqcnt]=r;
		if(dep(r)!=0) t[++qwqcnt]=jump(r,1);
	}
	sort(t+1,t+qwqcnt+1,cmp);
	// for(int i=1;i<=n*2;i++) printf("%d %d\n",t[i].x,t[i].y);
	st[++tp]=Node(0,0);
	id[Node(0,0)]=++idcnt;
	for(int i=1;i<=qwqcnt;i++)
	{
		if(t[i]==t[i-1]) continue;
		Node L=lca(st[tp],t[i]);
		if(L!=st[tp])
		{
			while(dep(st[tp-1])>dep(L)) addedge(st[tp],st[tp-1]),tp--;
			addedge(st[tp],L),tp--;
			if(st[tp]!=L) st[++tp]=L;
		}
		st[++tp]=t[i];
	}
	while(tp>1) addedge(st[tp],st[tp-1]),tp--;
	dfs(1,0);
	for(int i=1;i<=18;i++) for(int j=1;j<=idcnt;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=n;i++)
	{
		int u=id[a[i]],v=id[b[i]];
		int l=lca(u,v);
		cnt[u]++,cnt[v]++,cnt[l]--,cnt[fa[l][0]]--;
	}
	dfs2(1,0);
	dfs3(1,0);
	int ans=0;
	for(auto [x,y]:vis) if(y) ans++;
	cout<<ans<<endl;
	return 0;
}