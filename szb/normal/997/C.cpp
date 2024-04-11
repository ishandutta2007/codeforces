#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=int(x);i<int(y);++i)
#define For(i,x,y)  for(int i=int(x);i<=int(y);++i)
#define FOr(i,x,y)  for(int i=int(x);i>=int(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
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
	void writeln(ll x){write(x),puts("");}
	void Max(ll &x,ll y){x=x<y?y:x;}
	ll max(ll x,ll y){return x<y?y:x;}
}using namespace SHENZHEBEI;
const ll N=1001000,mod=998244353;
ll fac[N],inv[N],bin[N],n,ans;
ll ppow(ll x,ll k){
	ll ans=1;for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);
	return ans;
}
ll C(ll n,ll m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main(){
	n=read();	
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%mod;
	bin[0]=1;For(i,1,n)bin[i]=bin[i-1]*(-3)%mod;
	inv[n]=ppow(fac[n],mod-2);FOr(i,n,1)inv[i-1]=inv[i]*i%mod;
	For(i,1,n)Add(ans,C(n,i)*((i&1)?1:-1)*ppow(3,(n-i)*n+i));
	Add(ans,ans);
	For(i,0,n-1){
		ll tmp=-ppow(3,i);
		Add(ans,3*C(n,i)*ppow(-1,i+1)%mod*(ppow(1+tmp,n)-ppow(tmp,n)));
	}
	Add(ans,mod);	writeln(ans);
}