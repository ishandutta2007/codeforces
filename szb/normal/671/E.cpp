#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(int i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(int i=(ll)(x);i>=(ll)(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,int>
#define lf else if
#define IL inline
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define E(x)        return writeln(x),0
#define LL			(long long)
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*SS=SZB,*TT=SZB;
    inline char gc(){   if (SS==TT){  TT=(SS=SZB)+fread(SZB,1,GYN,stdin); if (SS==TT) return '\n';  }   return 

*SS++;    }
#if NEG
    inline long long read(){    long long x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') 

g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(long long x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x

%10+'0');  }
#else
    inline long long read(){    long long x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit

(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(long long x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline long long readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!

isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
	void Print(long long *a,int s,int t){For(i,s,t)printf("%long longd ",a[i]);}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
	void writeln(long long x){write(x);puts("");}
	void Min(long long &x,long long y){x=x<y?x:y;}
	void Max(long long &x,long long y){x=x>y?x:y;}
	ll min(ll x,ll y){return x<y?x:y;}
	ll max(ll x,ll y){return x<y?y:x;}
}using namespace SHENZHEBEI;
const ll N=1600010;
vector<ll>son[N];
ll h[N],a[N],b[N],c[N],tag[N],w[N],g[N],q[N],s1[N],s2[N];
ll n,m,ans,top;
void add(ll p,ll x){a[p]+=x;c[p]+=x;tag[p]+=x;}
void pushdown(ll p){if (tag[p])add(p<<1,tag[p]),add(p<<1|1,tag[p]),tag[p]=0;}
ll calc(ll l,ll r,ll p,ll x){
	if(l==r)return x-b[p];
	pushdown(p);ll mid=(l+r)>>1;
	if (x>a[p<<1])return min(x-b[p<<1],calc(mid+1,r,p<<1|1,x));
	return min(calc(l,mid,p<<1,x),c[p]);
}
#define updata(p)	a[p]=max(a[p<<1],a[p<<1|1]),c[p]=calc(mid+1,r,p<<1|1,a[p<<1])
void build(ll l,ll r,ll p){
	if(l==r)return a[p]=b[p]=s2[l],void(0);
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);build(mid+1,r,p<<1|1);
	updata(p);	b[p]=max(b[p<<1],b[p<<1|1]);
}
void add(ll l,ll r,ll p,ll s,ll t,ll x){
	if (l==s&&r==t)return add(p,x),void(0);
	ll mid=(l+r)>>1;pushdown(p);
	if (t<=mid)add(l,mid,p<<1,s,t,x);
	lf (s>mid)add(mid+1,r,p<<1|1,s,t,x);
	else	add(l,mid,p<<1,s,mid,x),add(mid+1,r,p<<1|1,mid+1,t,x);
	updata(p);
}
ll solve(ll l,ll r,ll p,ll x){
	if (l==r)return x-b[p]>m?0:l;
	pushdown(p);ll mid=(l+r)>>1;
	if (x-b[p<<1|1]<=m)return solve(mid+1,r,p<<1|1,x);
	return solve(l,mid,p<<1,x);
}
ll query(ll l,ll r,ll p,ll x){
	if (l==r)return x-b[p]>m?0:l;
	pushdown(p);ll mid=(l+r)>>1,ans=0;
	if (x>a[p<<1])	ans=solve(l,mid,p<<1,x);
	lf (c[p]>m)	return query(l,mid,p<<1,x);
	return max(ans,query(mid+1,r,p<<1|1,max(x,a[p<<1])));
}
inline void solve(int x){
	h[++*h]=x;

	if (x>1)add(1,n,1,1,x-1,-1e18);

	ll l=1,r=*h,pos=n;
	for(;l<=r;){
		ll mid=(l+r)>>1;
		if (s1[x]-s1[h[mid]]>m)pos=h[mid]-1,l=mid+1;
		else	r=mid-1;
	}
	add(1,n,1,pos,n,1e18);
	Max(ans,query(1,n,1,-1e18)-x+1);
	add(1,n,1,pos,n,-1e18);
	if (x>1)add(1,n,1,1,x-1,1e18);
	rep(i,0,son[x].size()){
		if(x>1)add(1,n,1,x-1,n,s1[son[x][i]]-s1[x]);
		solve(son[x][i]);
		if(x>1)add(1,n,1,x-1,n,s1[x]-s1[son[x][i]]);
	}
	--*h;
}
int main(){
	n=read(),m=read();
	rep(i,1,n)w[i]=read();
	For(i,1,n)g[i]=read();
	rep(i,1,n)s1[i+1]=s1[i]+g[i]-w[i],s2[i+1]=s2[i]+g[i+1]-w[i];
	build(1,n,1);
	For(i,1,n){
		for(;top&&s1[i]<s1[q[top]];)son[i].push_back(q[top--]);
		q[++top]=i;
	}
	For(i,1,top)solve(q[i]);
	writeln(ans);
}
/*
a[p]max
b[p]max
c[p]
*/