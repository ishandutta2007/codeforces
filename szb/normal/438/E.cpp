#include<bits/stdc++.h>
using namespace std; 
#define ll long long
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
#define sqr(x)		((x)*(x))
#define abs(x)		((x)>0?(x):-(x))
#define Mul(x,y)    (x=x*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define Max(x,y)	(x=(x<(y)?(y):x))
#define Min(x,y)	(x=(x>(y)?(y):x))
#define E(x) 		return writeln(x),0
#define p(x)		printf("~%d~\n",x)
#define pp(x,y)		printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)	printf("~~~%d %d %d~~~\n",x,y,z)
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
#define NEG 1
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
const ll N=(1<<19)|111,mod=998244353,G=3,Inv_2=mod/2+1;
ll n,m,rev[N];
llu a[N],b[N],c[N],d[N],Inv_b[N],cogito[N],LBC[N],WN[N],wn[N];
struct NTT{
	ll n,L;
	ll ppow(ll x,ll k){ll ans=1;for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);return ans;}
	void init(ll len){
		n=1;L=0;while(n<len)n<<=1,L++;
		ll w=ppow(G,(mod-1)/n);
		rep(i,0,n)wn[i]=i?wn[i-1]*w%mod:1,rev[i]=rev[i>>1]>>1|((i&1)<<L-1);
	}
	void dft(llu *a,ll frog=0){
		rep(i,0,n)if (i<rev[i])swap(a[i],a[rev[i]]);
		for(ll d=1,Len=L-1;d<n;d<<=1,--Len){
			rep(i,0,d)WN[i]=wn[i<<Len];
			llu x,y,t;
			for(ll i=0;i<n;i+=d<<1)
			for(ll k=0,x=i;k<d;++k,++x)
				t=a[x+d]*WN[k]%mod,a[x+d]=a[x]-t+mod,a[x]+=t;
		}rep(i,0,n)a[i]=a[i]%mod;
		if (frog){
			ll inv=ppow(n,mod-2);
			rep(i,0,n)Mul(a[i],inv);
			reverse(a+1,a+n);
		}
	}
}ntt;
void Print(llu *a,ll n){rep(i,0,n)printf("%lld ",(ll)a[i]);puts("");}
	ll ppow(ll x,ll k){ll ans=1;for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);return ans;}
void Get_Inv(llu *a,llu *b,llu n){
	b[0]=ppow(a[0],mod-2);b[1]=0;
	for(ll m=2;m<=n;m<<=1){
		rep(i,0,m)c[i]=a[i];
		rep(i,m,m*2)c[i]=b[i]=0;
		ntt.init(m*2);
		ntt.dft(b),ntt.dft(c);
		rep(i,0,m*2)b[i]=b[i]*(2-1LL*b[i]*c[i]%mod+mod)%mod;
		ntt.dft(b,1);
		rep(i,m,m*2)b[i]=0;
	}
//	Print(a,n);
//	Print(b,n);
//	puts("--------------------------------");
}
void Get_Root(llu *a,llu *b,ll n){
	b[0]=1;	b[1]=0;
	for(m=2;m<=n;m<<=1){
		rep(i,0,m)d[i]=a[i];
		rep(i,m,m*2)d[i]=b[i]=0;
		Get_Inv(b,Inv_b,m);ntt.init(m*2);
		ntt.dft(d);ntt.dft(Inv_b);ntt.dft(b);
		rep(i,0,m*2)b[i]=Inv_2*(b[i]+Inv_b[i]*d[i]%mod)%mod;
		ntt.dft(b,1);rep(i,m,m*2)b[i]=0;
	}
}
int main(){
	n=read();ll lzh=m=read();
	For(i,1,n)(a[read()]+=mod-4)%=mod;
	for(ll m=1;m<=lzh;m<<=1);m<<=1;
	a[0]=1;
	Get_Root(a,cogito,m);
	++cogito[0];
	Get_Inv(cogito,LBC,m);
	For(i,1,lzh)printf("%d\n",(int)LBC[i]*2%mod);
}
/*
b=2g-ag^2
b=a/2g+g/2
2/(1+sqrt(1-4c))
*/