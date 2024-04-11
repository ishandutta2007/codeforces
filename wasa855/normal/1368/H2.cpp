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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
template <typename _Tp,typename... Args>_Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>_Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
#define N 100005
struct Mat
{
	int a[2][2];
	Mat(){memset(a,0,sizeof(a));}
	Mat operator * (const Mat &x) const
	{
		Mat ans; memset(ans.a,0x3f,sizeof(ans.a));
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) ans.a[i][j]=min(ans.a[i][j],a[i][k]+x.a[k][j]);
		return ans;
	}
};
int l[N],r[N],u[N],d[N];
int l1,r1,u1,d1;
int n,m,Q;
Mat getMat(int t)
{
	Mat ans;
	ans.a[0][0]=t,ans.a[0][1]=n+2-t;
	ans.a[1][0]=n+t,ans.a[1][1]=2-t;
	return ans;
}
struct SMT2
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int *a;
	int t[N*4],tag[N*4];
	void build(int u,int l,int r)
	{
		tag[u]=0;
		if(l==r)
		{
			t[u]=a[l];
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		t[u]=t[ls]+t[rs];
	}
	void flip(int u,int l,int r)
	{
		tag[u]^=1;
		t[u]=r-l+1-t[u];
	}
	void pushdown(int u,int l,int r)
	{
		if(tag[u]) flip(ls,l,mid),flip(rs,mid+1,r),tag[u]=0;
	}
	void update(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			flip(u,l,r);
			return ;
		}
		pushdown(u,l,r);
		if(mid>=L) update(ls,l,mid,L,R);
		if(mid<R) update(rs,mid+1,r,L,R);
		t[u]=t[ls]+t[rs];
	}
	pii query(){return mp(t[1],n-t[1]);}
}L,R;
struct SMT1
{
	Mat t[N*4][4];
	int tag1[N*4],tag2[N*4];
	void pushup(int u)
	{
		for(int i=0;i<4;i++) t[u][i]=t[ls][i]*t[rs][i];
	}
	void flip1(int u)
	{
		tag1[u]^=1;
		swap(t[u][0],t[u][1]),swap(t[u][2],t[u][3]);
	}
	void flip2(int u)
	{
		tag2[u]^=1;
		swap(t[u][0],t[u][2]),swap(t[u][1],t[u][3]);
	}
	void pushdown(int u)
	{
		if(tag1[u]) flip1(ls),flip1(rs),tag1[u]=0;
		if(tag2[u]) flip2(ls),flip2(rs),tag2[u]=0;
	}
	void build(int u,int l,int r)
	{
		tag1[u]=tag2[u]=0;
		if(l==r)
		{
			t[u][0]=getMat(::u[l]+d[l]);
			t[u][1]=getMat(::u[l]+!d[l]);
			t[u][2]=getMat(!::u[l]+d[l]);
			t[u][3]=getMat(!::u[l]+!d[l]);
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void update1(int u,int l,int r,int L,int R) // D
	{
		if(L<=l&&r<=R) {flip1(u); return ;}
		pushdown(u);
		if(mid>=L) update1(ls,l,mid,L,R);
		if(mid<R) update1(rs,mid+1,r,L,R);
		pushup(u);
	}
	void update2(int u,int l,int r,int L,int R) // U
	{
		if(L<=l&&r<=R) {flip2(u); return ;}
		pushdown(u);
		if(mid>=L) update2(ls,l,mid,L,R);
		if(mid<R) update2(rs,mid+1,r,L,R);
		pushup(u);
	}
	int query()
	{
		Mat f; pii x=L.query();
		f.a[0][0]=x.fir,f.a[0][1]=x.sec;
		f=f*t[1][0];
		int g[]={f.a[0][0],f.a[0][1]};
		x=R.query();
		return min(g[0]+x.fir,g[1]+x.sec);
	}
	#undef ls
	#undef rs
	#undef mid
}smt;
struct Query
{
	char opt;
	int l,r;
}q[N];
int ans[N];
signed main()
{
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++) l[i]=rdchar()=='B';
	for(int i=1;i<=n;i++) r[i]=rdchar()=='B';
	for(int i=1;i<=m;i++) u[i]=rdchar()=='B';
	for(int i=1;i<=m;i++) d[i]=rdchar()=='B';
	for(int i=1;i<=Q;i++) q[i].opt=rdchar(),q[i].l=read(),q[i].r=read(),ans[i]=inf;
	L.a=l,R.a=r;
	L.build(1,1,n),R.build(1,1,n);
	smt.build(1,1,m);
	ans[0]=smt.query();
	for(int i=1;i<=Q;i++)
	{
		if(q[i].opt=='L') L.update(1,1,n,q[i].l,q[i].r);
		if(q[i].opt=='R') R.update(1,1,n,q[i].l,q[i].r);
		if(q[i].opt=='D') smt.update1(1,1,m,q[i].l,q[i].r);
		if(q[i].opt=='U') smt.update2(1,1,m,q[i].l,q[i].r);
		ans[i]=min(ans[i],smt.query());
	}
	
	swap(n,m),swap(l,u),swap(r,d);
	L.a=l,R.a=r;
	L.build(1,1,n),R.build(1,1,n);
	smt.build(1,1,m);
	ans[0]=min(ans[0],smt.query());
	for(int i=1;i<=Q;i++)
	{
		if(q[i].opt=='L') q[i].opt='U';
		else if(q[i].opt=='R') q[i].opt='D';
		else if(q[i].opt=='U') q[i].opt='L';
		else if(q[i].opt=='D') q[i].opt='R';
	}
	L.a=l,R.a=r;
	L.build(1,1,n),R.build(1,1,n);
	smt.build(1,1,m);
	ans[0]=min(ans[0],smt.query());
	for(int i=1;i<=Q;i++)
	{
		if(q[i].opt=='L') L.update(1,1,n,q[i].l,q[i].r);
		if(q[i].opt=='R') R.update(1,1,n,q[i].l,q[i].r);
		if(q[i].opt=='D') smt.update1(1,1,m,q[i].l,q[i].r);
		if(q[i].opt=='U') smt.update2(1,1,m,q[i].l,q[i].r);
		ans[i]=min(ans[i],smt.query());
	}
	for(int i=0;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}