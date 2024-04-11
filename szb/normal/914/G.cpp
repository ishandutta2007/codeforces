
 #include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ld long double
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
#define abs(x)		(x)>0?(x):-(x)
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
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
const ll N=2100000,mod=1e9+7,mo=1e9+7,inv=mod/2+1;
ll f[N],n,fib[N],a[N],b[N],c[N],type,ans;
void fwt(ll *a){
	for (ll d=1;d<n;d<<=1)
		for (ll m=d<<1,i=0;i<n;i+=m)
			for (ll j=0;j<d;j++){
				ll x=a[i+j],y=a[i+j+d];
				if (type==1) a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;//xor
				if (type==0) a[i+j]=(x+y)%mod;//and
			}
}
void UFWT(ll *a){
	for (ll d=1;d<n;d<<=1)
		for (ll m=d<<1,i=0;i<n;i+=m)
			for (ll j=0;j<d;j++){
				ll x=a[i+j],y=a[i+j+d];
				if (type==1) a[i+j]=1ll*(x+y)*inv%mo,a[i+j+d]=(1ll*(x-y)*inv%mo+mo)%mo;//xor
				if (type==0) a[i+j]=(x+mo-y)%mo;//and
			}
}
int main(){
	n=read();
	For(i,1,n)f[read()]++;
	memcpy(a,f,sizeof f);
	memcpy(b,f,sizeof f);
	memcpy(c,f,sizeof f);
	memset(f,0,sizeof f);
	n=(1<<17)-1;
	fib[1]=1;
	For(i,2,n)fib[i]=(fib[i-2]+fib[i-1])%mod;
	For(i,0,n){
		ll j=i;
		while(1){
			f[i]+=a[j]*a[i^j];
			if (j==0)break;
			j=(j-1)&i;
		}f[i]%=mod;
	}
	type=1;
	fwt(b);
	For(i,0,n)	Mul(b[i],b[i]);
	UFWT(b);
	For(i,0,n)	f[i]=fib[i]*f[i]%mod;
	For(i,0,n)	b[i]=fib[i]*b[i]%mod;
	For(i,0,n)	a[i]=fib[i]*a[i]%mod;
	type=0;
	fwt(f);	fwt(a);	fwt(b);
	For(i,0,n)Mul(f[i],a[i]),Mul(f[i],b[i]);
	UFWT(f);
	for(ll i=1;i<n;i<<=1)	Add(ans,f[i]);
	writeln(ans);
}
/* 
,
f[j]&=a[i]==b[i+j]
f[ch]
g[ch]
*/