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
#define N 200005
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4];
	void upd(int u,int v) {t[u]+=v,tag[u]+=v;}
	void pushdown(int u)
	{
		upd(ls,tag[u]),upd(rs,tag[u]);
		tag[u]=0;
	}
	void build(int u,int l,int r)
	{
		t[u]=inf,tag[u]=0;
		if(l==r) return ;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void fix(int u,int l,int r,int pos,int v)
	{
		if(l==r) {t[u]=v; return ;}
		pushdown(u);
		if(pos<=mid) fix(ls,l,mid,pos,v);
		else fix(rs,mid+1,r,pos,v);
		t[u]=min(t[ls],t[rs]);
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L>R) return ;
		if(L<=l&&r<=R) return upd(u,v);
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		t[u]=min(t[ls],t[rs]);
	}
	int query() {return t[1];}
}smt;
int a[N],rev[N],vis[N],n;
void work()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read(),rev[a[i]]=i;
	for(int i=1;i<=n;i++) vis[i]=0;
	int ans=0,cur=n;
	smt.build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		// smt.fix(1,1,n,rev[i],rev[i]+1-(rev[i]&1));
		smt.update(1,1,n,rev[i],rev[i],rev[i]-(1-(rev[i]&1))-inf);
		smt.update(1,1,n,rev[i]+1,n,-2);
		vis[rev[i]]=1;
		while(vis[cur]) smt.fix(1,1,n,cur,inf),cur--;
		// printf("%d %d\n",i,i-smt.query());
		ans=max(ans,i-smt.query());
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}