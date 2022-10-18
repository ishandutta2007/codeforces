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
#define mod 1000000007
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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 100005
struct Edge
{
	int v,w,c;
	Edge(int a=0,int b=0,int d=0) {v=a,w=b,c=d;}
};
vector<Edge> G[N];
int n,ans=1;
int vis[N],siz[N],mn,rt,tot;
void getrt(int u,int f)
{
	siz[u]=1; int mx=0;
	for(auto [v,_,__]:G[u])
	{
		if(v==f||vis[v]) continue;
		getrt(v,u),siz[u]+=siz[v];
		mx=max(mx,siz[v]);
	}
	mx=max(mx,tot-siz[u]);
	if(mx<mn) mn=mx,rt=u;
}
struct Node
{
	int c0,c1,w,id;
};
Node a[N],b[N]; int m;
int cnt[N];
void dfs1(int u,int f,int c0,int c1,int w)
{
	a[++m]=(Node){c0,c1,w,u};
	for(auto [v,tw,c]:G[u])
	{
		if(v==f||vis[v]) continue;
		if(c==0) dfs1(v,u,c0+1,c1,mul(w,tw));
		else dfs1(v,u,c0,c1+1,mul(w,tw));
	}
}
struct BIT
{
	int len,t[N*6];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){for(int i=u;i<=len;i+=lowbit(i)) t[i]+=v;}
	int query(int u)
	{
		// if(u==0) cout<<"bad\n",exit(0);
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
	int qry(int l,int r) {return query(r)-query(l-1);}
}bit;
int getv1(Node x) {return 2*x.c0-x.c1;}
int getv2(Node x) {return 2*x.c1-x.c0;}
bool cmp1(Node x,Node y) {return getv1(x)<getv1(y);}
bool cmp2(Node x,Node y) {return getv1(x)>getv1(y);}
void work(int op)
{
	for(int i=1;i<=m;i++) b[i]=a[i];
	// for(int i=1;i<=m;i++) printf("%d %d %d\n",a[i].c0,a[i].c1,a[i].id);
	sort(a+1,a+m+1,cmp1),sort(b+1,b+m+1,cmp2);
//	for(int i=1;i<=m;i++) printf("%d %d\n",getv1(a[i]),getv2(a[i]));
//	cout<<"\n";
//	for(int i=1;i<=m;i++) printf("%d %d\n",-getv1(b[i]),-getv2(b[i]));
//	cout<<"\n";
	int cur=1;
	for(int i=1;i<=m;i++)
	{
		while(cur<=m&&getv1(a[i])>=-getv1(b[cur]))
		{
			bit.update(-getv2(b[cur])+300001,1);
			cur++;
		}
		int res=bit.qry(1,getv2(a[i])+300001);
		// printf("^ %d %d\n",i,res);
		cnt[a[i].id]+=op*res;
	}
	for(int i=1;i<cur;i++) bit.update(-getv2(b[i])+300001,-1);
}
void getvs(int u,int f,int w)
{
	ans=mul(ans,qpow(w,cnt[u]));
	cnt[u]=0,siz[u]=1;
	for(auto [v,tw,c]:G[u])
	{
		if(v==f||vis[v]) continue;
		getvs(v,u,mul(w,tw));
		siz[u]+=siz[v];
	}
}
void solve(int u)
{
	// printf("^ %d\n",u);
	m=0;
	dfs1(u,0,0,0,1);
	work(1);
	// for(int i=1;i<=n;i++) printf("%d%c",cnt[i]," \n"[i==n]);
	for(auto [v,w,c]:G[u])
	{
		if(vis[v]) continue;
		m=0;
		if(c==0) dfs1(v,u,1,0,w);
		else dfs1(v,u,0,1,w);
		work(-1);
		// for(int i=1;i<=n;i++) printf("%d%c",cnt[i]," \n"[i==n]);
	}
	// for(int i=1;i<=n;i++) printf("%d%c",cnt[i]," \n"[i==n]);
	getvs(u,0,1);
	vis[u]=1;
	for(auto [v,w,c]:G[u])
	{
		if(vis[v]) continue;
		tot=siz[v],mn=inf,getrt(v,0);
		solve(rt);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read(),c=read();
		G[u].eb(v,w,c),G[v].eb(u,w,c);
	}
	bit.init(600005);
	tot=n,mn=inf,getrt(1,0);
	solve(rt);
	cout<<ans<<endl;
	return 0;
}