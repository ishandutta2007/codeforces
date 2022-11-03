
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
const ll N=1000010,mod=1e9+7;
ll mark[N],pri[N],phi[N],sum[N],ans1[N],ans2[N],ans3[N],n,m;
void Init(){
	phi[1]=1;
	For(i,2,n){
		if (!mark[i])pri[++pri[0]]=i,phi[i]=i-1;
		for(ll j=1;j<=pri[0]&&i*pri[j]<=n;++j){
			mark[i*pri[j]]=1;
			if (!(i%pri[j])){phi[i*pri[j]]=phi[i]*pri[j];break;}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	For(Gcd,1,n)for(ll i=Gcd;i<=n;i+=Gcd)Add(sum[i],Gcd*phi[i/Gcd]);
}
int main(){
	n=1e6;

	Init();
	For(i,1,n){
		ll val=(i*(i+1)*(2*i+1)/3%mod-3*i*i+2*sum[i])%mod;
		ans1[i]=(ans1[i-1]+val)%mod;
		ans2[i]=(ans2[i-1]+val*(i-1))%mod;
		ans3[i]=(ans3[i-1]+val*(i-1)%mod*(i-1))%mod;
	}
	for(ll T=read();T--;){
		n=read(),m=read();
		if (n>m)swap(n,m);
		ll ans=(n*m%mod*ans1[n]-(n+m)*ans2[n]+ans3[n])%mod;
		Add(ans,mod);
		writeln(ans);
	}
}
/*
L*(L+1)*(2L+1)/3-3L^2+2sigma gcd(i,L)

*/