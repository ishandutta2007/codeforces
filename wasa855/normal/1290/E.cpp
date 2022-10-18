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
#define N 150005
int a[N],rev[N],n;
struct SMT1
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int a[N*4],tag[N*4],b[N*4],ans[N*4]; // a chuxiancishu ,b quanzhi ,ans=a*b
	inline void doit(int u,int v)
	{
		a[u]+=v,tag[u]+=v,ans[u]+=v*b[u];
	}
	inline void pushdown(int u)
	{
		doit(ls,tag[u]),doit(rs,tag[u]);
		tag[u]=0;
	}
	void upd1(int u,int l,int r,int pl,int v)
	{
		if(pl<1||pl>n) return ;
		// if(l==1&&r==n) printf("%d %d\n",pl,v);
		if(l==r)
		{
			b[u]+=v,ans[u]=a[u]*b[u];
			return ;
		}
		pushdown(u);
		if(pl<=mid) upd1(ls,l,mid,pl,v);
		else upd1(rs,mid+1,r,pl,v);
		ans[u]=ans[ls]+ans[rs],b[u]=b[ls]+b[rs],a[u]=a[ls]+a[rs];
	}
	void upd2(int u,int l,int r,int L,int R,int v)
	{
		// if(l==1&&r==n) printf("%d %d %d\n",L,R,v);
		if(L<=l&&r<=R)
		{
			a[u]+=v,tag[u]+=v; ans[u]+=v*b[u];
			return ;
		}
		pushdown(u);
		if(mid>=L) upd2(ls,l,mid,L,R,v);
		if(mid<R) upd2(rs,mid+1,r,L,R,v);
		ans[u]=ans[ls]+ans[rs],b[u]=b[ls]+b[rs],a[u]=a[ls]+a[rs];
	}
	int query(){return ans[1];}
	// int query(int u,int l,int r,int L,int R)
	// {
		// if(L<=l&&r<=R) return ans[u];
		// pushdown(u);
		// int ans=0;
		// if(mid>=L) ans+=query(ls,l,mid,L,R);
		// if(mid<R) ans+=query(rs,mid+1,r,L,R);
		// return ans;
	// }
}smt1;
struct SMT2 // hou zhui
{
	struct Node
	{
		int mx1,mx2,ct,tag;
	};
	Node t[N*4];
	inline Node merge(Node u,Node v)
	{
		Node ans;
		if(u.mx1==v.mx1)
		{
			ans.mx1=u.mx1,ans.mx2=max(u.mx2,v.mx2);
			ans.ct=u.ct+v.ct;
		}
		else if(u.mx1>v.mx1)
		{
			ans.mx1=u.mx1,ans.mx2=max(u.mx2,v.mx1);
			ans.ct=u.ct;
		}
		else
		{
			ans.mx1=v.mx1,ans.mx2=max(u.mx1,v.mx2);
			ans.ct=v.ct;
		}
		return ans;
	}
	void update(int u,int l,int r,int L,int R,int v,int qaq);
	void build(int u,int l,int r)
	{
		if(l==r)
		{
			t[u].mx1=0;
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		t[u]=merge(t[ls],t[rs]);
	}
	void pushdown(int u,int l,int r)
	{
		if(t[u].tag)
		{
			doit(ls,l,mid,l,mid,t[u].tag,0);
			doit(rs,mid+1,r,mid+1,r,t[u].tag,0);
			t[u].tag=0;
		}
	}
	void doit(int u,int l,int r,int L,int R,int v,int qaq)
	{
		if(t[u].mx1<=v) return ;
		if(l==r)
		{
			if(qaq) if(t[u].mx1!=N&&t[u].mx1!=1) smt1.upd1(1,1,n,t[u].mx1-1,-t[u].ct);
			// printf("%d %d - %d ++ %d - ",l,r,qaq,t[u].mx1);
			t[u].mx1=v;
			if(qaq) if(t[u].mx1!=N&&t[u].mx1!=1) smt1.upd1(1,1,n,t[u].mx1-1,t[u].ct);
			// printf("%d\n",t[u].mx1);
			return ;
		}
		if(t[u].mx2<v)
		{
			if(qaq) if(t[u].mx1!=N&&t[u].mx1!=1) smt1.upd1(1,1,n,t[u].mx1-1,-t[u].ct);
			// printf("%d %d - %d ++ %d - ",l,r,qaq,t[u].mx1);
			t[u].mx1=v,t[u].tag=v;
			if(qaq) if(t[u].mx1!=N&&t[u].mx1!=1) smt1.upd1(1,1,n,t[u].mx1-1,t[u].ct);
			// printf("%d\n",t[u].mx1);
			return ;
		}
		pushdown(u,l,r);
		update(ls,l,mid,L,R,v,qaq),update(rs,mid+1,r,L,R,v,qaq);
		t[u]=merge(t[ls],t[rs]);
	}
	void update(int u,int l,int r,int pl)
	{
		if(l==r)
		{
			t[u].mx1=n+1,t[u].ct=1;
			smt1.upd1(1,1,n,n,t[u].ct);
			return ;
		}
		pushdown(u,l,r);
		if(pl<=mid) update(ls,l,mid,pl);
		else update(rs,mid+1,r,pl);
		t[u]=merge(t[ls],t[rs]);
	}
}smt2;
void SMT2::update(int u,int l,int r,int L,int R,int v,int qaq)
{
	// printf("-+ %d %d %d %d %d %d\n",u,l,r,L,R,v);
	if(L<=l&&r<=R)
	{
		SMT2::doit(u,l,r,L,R,v,qaq);
		return ;
	}
	SMT2::pushdown(u,l,r);
	if(mid>=L) SMT2::update(ls,l,mid,L,R,v,qaq);
	if(mid<R) SMT2::update(rs,mid+1,r,L,R,v,qaq);
	SMT2::t[u]=merge(SMT2::t[ls],SMT2::t[rs]);
}
struct SMT3 // qian zhui
{
	struct Node
	{
		int mn1,mn2,ct,tag;
	};
	Node t[N*4];
	inline Node merge(Node u,Node v)
	{
		Node ans;
		if(u.mn1==v.mn1)
		{
			ans.mn1=u.mn1,ans.mn2=min(u.mn2,v.mn2);
			ans.ct=u.ct+v.ct;
		}
		else if(u.mn1<v.mn1)
		{
			ans.mn1=u.mn1,ans.mn2=min(u.mn2,v.mn1);
			ans.ct=u.ct;
		}
		else
		{
			ans.mn1=v.mn1,ans.mn2=min(u.mn1,v.mn2);
			ans.ct=v.ct;
		}
		return ans;
	}
	void build(int u,int l,int r)
	{
		if(l==r)
		{
			t[u].mn1=N;
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		t[u]=merge(t[ls],t[rs]);
	}
	void update(int u,int l,int r,int L,int R,int v,int qaq);
	void pushdown(int u,int l,int r)
	{
		if(t[u].tag)
		{
			doit(ls,l,mid,l,mid,t[u].tag,0);
			doit(rs,mid+1,r,mid+1,r,t[u].tag,0);
			t[u].tag=0;
		}
	}
	void doit(int u,int l,int r,int L,int R,int v,int qaq)
	{
		// printf("** %d %d %d %d %d\n",u,l,r,L,R);
		if(t[u].mn1>=v) return ;
		if(l==r)
		{
			if(qaq) if(t[u].mn1!=0&&t[u].mn1!=N) smt1.upd1(1,1,n,t[u].mn1,t[u].ct);
			// if(qaq) if(t[u].mn1==0) smt1.upd1(1,1,n,n,t[u].ct);
			// printf("%d %d - %d ** %d - ",l,r,qaq,t[u].mn1);
			t[u].mn1=v;
			if(qaq) if(t[u].mn1!=0&&t[u].mn1!=N) smt1.upd1(1,1,n,t[u].mn1,-t[u].ct);
			// if(qaq) if(t[u].mn1==0) smt1.upd1(1,1,n,n,-t[u].ct);
			// printf("%d\n",t[u].mn1);
			return ;
		}
		if(t[u].mn2>v)
		{
			if(qaq) if(t[u].mn1!=0&&t[u].mn1!=N) smt1.upd1(1,1,n,t[u].mn1,t[u].ct);
			// if(qaq) if(t[u].mn1==0) smt1.upd1(1,1,n,n,t[u].ct);
			// printf("%d %d - %d ** %d - ",l,r,qaq,t[u].mn1);
			t[u].mn1=v,t[u].tag=v;
			if(qaq) if(t[u].mn1!=0&&t[u].mn1!=N) smt1.upd1(1,1,n,t[u].mn1,-t[u].ct);
			// if(qaq) if(t[u].mn1==0) smt1.upd1(1,1,n,n,-t[u].ct);
			// printf("%d\n",t[u].mn1);
			return ;
		}
		pushdown(u,l,r);
		update(ls,l,mid,L,R,v,qaq),update(rs,mid+1,r,L,R,v,qaq);
		t[u]=merge(t[ls],t[rs]);
	}
	void update(int u,int l,int r,int pl)
	{
		if(l==r)
		{
			t[u].mn1=0,t[u].ct=1;
			return ;
		}
		pushdown(u,l,r);
		if(pl<=mid) update(ls,l,mid,pl);
		else update(rs,mid+1,r,pl);
		t[u]=merge(t[ls],t[rs]);
	}
}smt3;
void SMT3::update(int u,int l,int r,int L,int R,int v,int qaq)
{
	// printf("-- %d %d %d %d %d\n",u,l,r,L,R);
	if(L<=l&&r<=R)
	{
		SMT3::doit(u,l,r,L,R,v,qaq);
		return ;
	}
	SMT3::pushdown(u,l,r);
	if(mid>=L) SMT3::update(ls,l,mid,L,R,v,qaq);
	if(mid<R) SMT3::update(rs,mid+1,r,L,R,v,qaq);
	SMT3::t[u]=merge(SMT3::t[ls],SMT3::t[rs]);
}
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read(),rev[a[i]]=i;
	smt2.build(1,1,n),smt3.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int pos=rev[i];
		smt2.update(1,1,n,1,pos,pos,1);
		smt3.update(1,1,n,pos,n,pos,1);
		smt3.update(1,1,n,pos);
		smt2.update(1,1,n,pos);
		smt1.upd2(1,1,n,pos,n,1);
		printf("%lld\n",smt1.query());
	}
	return 0;
}