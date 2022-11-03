#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    (x=1LL*(x)*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    inline char gc(){   return getchar();   }
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace SHENZHEBEI;
const ll N=20010,mod=1e9+7;
ll MUL[N],now[N],ans[N],suc[N],fac[N],Inv[N],a[N],b[N],n;
ll ppow(ll x,ll k){ll ans=1;for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);return ans;}
ll ff(ll x,ll y){return fac[y]*Inv[x]%mod;}
int main(){
	n=read()-1;For(i,1,n)a[i]=read(); 
	fac[0]=1;	For(i,1,n)fac[i]=fac[i-1]*a[i]%mod;
	suc[n+1]=1;	FOr(i,n,1)suc[i]=suc[i+1]*a[i]%mod;memcpy(b,a,sizeof a);
	Inv[0]=1;For(i,1,n)Inv[i]=Inv[i-1]*ppow(a[i],mod-2)%mod;b[0]=1;
	FOr(lca,n,0){
		ll qwq=(fac[lca]*(b[lca+1]*(b[lca+1]-1)/2%mod)%mod);
		memset(now,0,sizeof now);
		FOr(i,n*2,0)Add(now[i],MUL[i-2]*b[lca+2]%mod*b[lca+2]%mod);
		For(i,lca+1,n)Add(now[i-lca+1],ff(lca+1,i));
		For(i,lca+2,n)Add(now[i-lca+1],ff(lca+1,i));
		memcpy(MUL,now,sizeof now);
		For(i,2,n*2)ans[i]=(ans[i]+MUL[i]*qwq)%mod;
	}
	For(i,0,n)For(j,i,n)Add(ans[j-i],fac[j]);
	For(i,1,n*2)printf("%I64d ",(ans[i]+mod)%mod);
}
/*
0	1	a[i+2]	a[i+3]
0	1	a[i+2]	a[i+3]
*/