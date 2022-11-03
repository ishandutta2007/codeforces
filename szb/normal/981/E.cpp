

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(ll i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(ll i=(ll)(x);i>=(ll)(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
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
#define y1			fafa____
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,GYN,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);puts("");}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);puts("");}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);puts("");}
	void writeln(ll x){write(x);putchar('\n');}
}using namespace SHENZHEBEI;
const ll N=10010;
ll n,Q;
struct dt{ll l,r,x;}ask[N],tmp[N];
bitset<N>f[100],ans;
vector<ll>g;
void fenzhi(ll l,ll r,ll L,ll R,ll dep){
	if (l==r||(L>R)){
		For(i,L,R)f[dep]|=f[dep]<<ask[i].x;
		ans|=f[dep];
		return;
	}ll mid=(l+r)>>1,ls=L,rs=R;
	f[dep+1]=f[dep];
	For(i,L,R)	if (ask[i].l<=l&&mid<=ask[i].r){
		f[dep+1]|=f[dep+1]<<ask[i].x;
		tmp[rs--]=ask[i];
	}			lf (ask[i].l<=mid)	tmp[ls++]=ask[i];
							else	tmp[rs--]=ask[i];
	For(i,L,R)ask[i]=tmp[i];
	fenzhi(l,mid,L,ls-1,dep+1);
	
	f[dep+1]=f[dep];ls=L,rs=R;
	For(i,L,R)	if (ask[i].l<=mid+1&&r<=ask[i].r){
		f[dep+1]|=f[dep+1]<<ask[i].x;
		tmp[rs--]=ask[i];
	}			lf	(ask[i].r>mid)	tmp[ls++]=ask[i];
							else	tmp[rs--]=ask[i];
	For(i,L,R)ask[i]=tmp[i];
	fenzhi(mid+1,r,L,ls-1,dep+1);
}
int main(){
	n=read(),Q=read();
	For(i,1,Q)ask[i].l=read(),ask[i].r=read(),ask[i].x=read();
	f[0][0]=1;
	fenzhi(1,n,1,Q,0);
	For(i,1,n)if (ans[i])g.push_back(i);
	writeln(g.size());
	rep(i,0,g.size())write(g[i]),putchar(' ');puts("");
}