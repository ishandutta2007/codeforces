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
#define N 500005
int las[N][4],a[N],n;
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4],ct[N*4];
	void pushup(int u)
	{
		t[u]=max(t[ls],t[rs]); ct[u]=0;
		if(t[ls]==t[u]) ct[u]+=ct[ls];
		if(t[rs]==t[u]) ct[u]+=ct[rs];
	}
	void doit(int u,int v) {t[u]+=v,tag[u]+=v;}
	void pushdown(int u)
	{
		if(tag[u]) doit(ls,tag[u]),doit(rs,tag[u]),tag[u]=0;
	}
	void build(int u,int l,int r)
	{
		if(l==r)
		{
			t[u]=n,tag[u]=0,ct[u]=1;
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(R<=0) return ;
		if(L<=l&&r<=R)
		{
			doit(u,v);
			return ;
		}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		pushup(u);
	}
	int query()
	{
		if(t[1]==n) return ct[1];
		else return 0;
	}
}smt;
signed main()
{
	cin>>n; ll ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	smt.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		smt.update(1,1,n,las[a[i]][0]+1,i,-1);
		smt.update(1,1,n,las[a[i]][3]+1,las[a[i]][2],-1);
		for(int j=3;j>=1;j--) las[a[i]][j]=las[a[i]][j-1];
		las[a[i]][0]=i;
		smt.update(1,1,n,las[a[i]][3]+1,las[a[i]][2],1);
		// cout<<smt.query()<<endl;
		ans+=smt.query()-n+i;
	}
	cout<<ans<<endl;
	return 0;
}