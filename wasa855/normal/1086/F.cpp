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
inline int sim(int x) {return (x%mod+mod)%mod;}
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
const int i2=Inv(2),i6=Inv(6);
#define N 105
int x[N],y[N],r[N*N],n,m,t;
int p[N],s;
struct Node{int p,l,r,v;};
bool cmp(Node x,Node y) {return x.p<y.p;}
Node b[N]; int q;
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int t[N*8],val[N*8];
	void build(int u,int l,int r)
	{
		t[u]=val[u]=0;
		if(l==r) return ;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void pushup(int u,int l,int r)
	{
		if(t[u]) val[u]=p[r+1]-p[l];
		else val[u]=val[ls]+val[rs];
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			t[u]+=v,pushup(u,l,r);
			// printf("^^ %d %d %d - %d\n",u,l,r,val[u]);
			return ;
		}
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		pushup(u,l,r);
		// printf("^^ %d %d %d - %d\n",u,l,r,val[u]);
	}
	int query() {return val[1];}
}smt;
int getpos(int a)
{
	if(a==0) return n;
	s=q=0;
	for(int i=1;i<=n;i++) p[++s]=y[i]-a,p[++s]=y[i]+a+1;
	sort(p+1,p+s+1); s=unique(p+1,p+s+1)-p-1;
	// for(int i=1;i<=s;i++) printf("%d%c",p[i]," \n"[i==s]);
	for(int i=1;i<=n;i++)
	{
		int l=lower_bound(p+1,p+s+1,y[i]-a)-p,r=lower_bound(p+1,p+s+1,y[i]+a+1)-p-1;
		// printf("%d %d - %d\n",l,r,s);
		b[++q]=(Node){x[i]-a,l,r,1},b[++q]=(Node){x[i]+a+1,l,r,-1};
	}
	smt.build(1,1,s);
	sort(b+1,b+q+1,cmp);
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		smt.update(1,1,s,b[i].l,b[i].r,b[i].v);
		// int pi=i;
		while(i!=q&&b[i].p==b[i+1].p) i++,smt.update(1,1,s,b[i].l,b[i].r,b[i].v);
		// printf("^ %d - %d %d\n",b[i].p,smt.query(),b[i+1].p-b[i].p);
		ans=add(ans,mul(smt.query(),b[i+1].p-b[i].p));
	}
	return ans;
}
vector<int> polymul(vector<int> a,int B) // (x+B)
{
	vector<int> ans=a;
	for(int i=0;i<(int)a.size();i++) ans[i]=mul(ans[i],B);
	ans.pb(0);
	for(int i=0;i<(int)a.size();i++) ans[i+1]=add(ans[i+1],a[i]);
	return ans;
}
vector<int> interpolation(vector<int> x,vector<int> y)
{
	// cout<<"************\n";
	// print(x),print(y);
	int n=x.size();
	vector<int> ans(n);
	for(int i=0;i<n;i++)
	{
		vector<int> p={1}; int q=y[i];
		for(int j=0;j<n;j++) if(i!=j)
		{
			p=polymul(p,mod-x[j]);
			q=mul(q,Inv(sim(x[i]-x[j])));
		}
		for(int j=0;j<(int)p.size();j++) p[j]=mul(p[j],q);
		// print(p);
		for(int j=0;j<(int)p.size();j++) ans[j]=add(ans[j],p[j]);
	}
	return ans;
}
int rgsum1(int l,int r) {return mul(r-l+1,l+r,i2);}
int preqwq(int x) {return mul(mul(x,x+1,2*x+1),i6);}
int rgsum2(int l,int r) {return sub(preqwq(r),preqwq(l-1));}
int getsum(int l,int r)
{
	// printf("^ %d %d\n",l,r);
	if(l==r) return getpos(l);
	if(l+1==r) return add(getpos(l),getpos(r));
	int A=getpos(l),B=getpos(l+1),C=getpos(l+2);
	vector<int> coef=interpolation({l,l+1,l+2},{A,B,C});
	// printf("%d %d %d\n",A,B,C);
	// print(coef);
	int x=mul(coef[0],r-l+1),y=mul(coef[1],rgsum1(l,r)),z=mul(coef[2],rgsum2(l,r));
	// printf("^** %d %d\n",add(x,y,z),add(A,B,C));
	return add(x,y,z);
}
signed main()
{
	cin>>n>>t; for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	r[0]=-1,r[++m]=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		int q=(max(abs(x[i]-x[j]),abs(y[i]-y[j]))-1)/2;
		if(q<t) r[++m]=q;
		// if(q+1<t) r[++m]=q+1;
	}
	r[++m]=t;
	sort(r+1,r+m+1); m=unique(r+1,r+m+1)-r-1;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int qwq=getsum(r[i-1]+1,r[i]);
		ans=add(ans,qwq);
		// printf("%d %d - %d\n",r[i-1]+1,r[i],qwq);
	}
	// ans=0;
	// for(int i=0;i<=t;i++) ans=add(ans,getpos(i));
	// for(int i=0;i<=t;i++) printf("%d%c",getpos(i)," \n"[i==t]);
	// cout<<getpos(t)<<endl;
	int res=mul(t+1,getpos(t));
	// cout<<ans<<endl;
	cout<<sub(res,ans)<<endl;
	return 0;
}