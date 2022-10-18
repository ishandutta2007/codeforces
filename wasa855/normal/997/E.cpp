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
#define N 120005
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int minn[N*8],cnt[N*8],tag[N*8],add[N*8];
	ll ans[N*8];
	void build(int u,int l,int r)
	{
		if(l==r) {minn[u]=1,cnt[u]=1; return ;}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void pushup(int u)
	{
		minn[u]=min(minn[ls],minn[rs]),cnt[u]=0;
		if(minn[u]==minn[ls]) cnt[u]+=cnt[ls];
		if(minn[u]==minn[rs]) cnt[u]+=cnt[rs];
	}
	void pdv(int u)
	{
		if(tag[u])
		{
			tag[ls]+=tag[u],minn[ls]+=tag[u];
			tag[rs]+=tag[u],minn[rs]+=tag[u];
			tag[u]=0;
		}
	}
	void Add(int u,int v,int val)
	{
		if(minn[u]==val) ans[u]+=cnt[u]*v,add[u]+=v;
	}
	void pushdown(int u)
	{
		pdv(u);
		if(add[u])
		{
			Add(ls,add[u],minn[u]),Add(rs,add[u],minn[u]);
			add[u]=0;
		}
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			tag[u]+=v,minn[u]+=v;
			return ;
		}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		pushup(u);
	}
	void Query() {Add(1,1,0);}
	ll query(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return ans[u];
		pushdown(u);
		ll ans=0;
		if(mid>=L) ans+=query(ls,l,mid,L,R);
		if(mid<R) ans+=query(rs,mid+1,r,L,R);
		return ans;
	}
}smt;
int n,Q,a[N];
ll ans[N];
vector<pii> q[N];
int st1[N],st2[N],tp1,tp2;
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read();
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		int l=read(),r=read(); q[r].eb(l,i);
	}
	smt.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		smt.update(1,1,n,1,i,-1);
		while(tp1&&a[i]>a[st1[tp1]])
		{
			int u=st1[tp1--];
			// printf("-- %d %d %d\n",st1[tp1]+1,u,a[i]-a[u]);
			smt.update(1,1,n,st1[tp1]+1,u,a[i]-a[u]);
		}
		while(tp2&&a[i]<a[st2[tp2]])
		{
			int u=st2[tp2--];
			// printf("-- %d %d %d\n",st2[tp2]+1,u,a[u]-a[i]);
			smt.update(1,1,n,st2[tp2]+1,u,a[u]-a[i]);
		}
		// printf("-- %d %d\n",i,smt.minn[1]);
		st1[++tp1]=i,st2[++tp2]=i;
		smt.Query();
		for(auto [l,id]:q[i]) ans[id]=smt.query(1,1,n,l,i);
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",ans[i]);
	return 0;
}