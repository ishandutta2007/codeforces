#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)		(x)*(x)
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
#define E(x) 		return writeln(x),0
#define p(x)		printf("%d\n",x)
#define pp(x,y)		printf("%d %d\n",x,y)
#define ppp(x,y,z)	printf("%d %d %d\n",x,y,z)
#define f_in(x)		freopen(x".in","r",stdin)
#define f_out(x) 	freopen(x".out","w",stdout)
#define open(x)		f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 0
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
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
}using namespace SHENZHEBEI;
const ll N=2010,mod=998244353;
ll n,a,b,f[N],h[N],g[N][N],inv_p[N],fac_p[N],p;
ll ppow(ll x,ll k){ll ans=1;for(;k;k>>=1,x=x*x%mod)if (k&1)ans=ans*x%mod;return ans;}
int main(){
	n=read();a=read();b=read();p=a*ppow(b,mod-2)%mod;
	g[0][0]=1;
	inv_p[0]=1;For(i,1,n)inv_p[i]=inv_p[i-1]*p%mod;
	fac_p[0]=1;For(i,1,n)fac_p[i]=fac_p[i-1]*(1-p)%mod;
	For(i,1,n){g[i][0]=1;	For(j,1,i)	g[i][j]=(g[i-1][j]*fac_p[j]+g[i-1][j-1]*inv_p[i-j])%mod;	}
	h[1]=1;	For(i,2,n){	h[i]=1;	For(j,1,i-1)h[i]=(h[i]-h[j]*g[i][j])%mod;	}
	f[1]=0;
	For(i,2,n){
 		For(j,1,i-1)
		f[i]=f[i]+((f[i-j]+f[j]+j*(j-1)/2+(i-j)*j)%mod*g[i][j]%mod*h[j])%mod;
		f[i]=(f[i]+i*(i-1)/2*h[i]%mod*g[i][i])%mod;
		f[i]=f[i]*ppow((1-g[i][i]*h[i])%mod,mod-2)%mod;
	}
	writeln((f[n]+mod)%mod);
}
/*
f[i]i,A1,, 
f[n]=(f[n-i]+f[i]+i*(i-1)/2+(n-i)*i)*g[n][i]*h[i] 
g[n][i]nni,h[i]i
h,h[i]=1-g[n][i]*h[i](i=1..n-1)
g[n][m]=g[n-1][m]*(1-p)^m+g[n-1][m-1]*p^(n-m)
*/