#include<bits/stdc++.h>
using namespace std;
#define ll int
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
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",a,b,c,d)
#define f_in(x)     freopen(x,"r",stdin)
#define f_out(x)    freopen(x,"w",stdout)
#define open(x)     f_in(x".in"),f_out(x".out")
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 1
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=getchar();   for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=getchar())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=getchar();   for (;!isdigit(ch);ch=getchar());    for (;isdigit(ch);ch=getchar())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=getchar();   for(;isspace(ch);ch=getchar());  return ch;  }
    inline ll readstr(char *s){ char ch=getchar();   int cur=0;  for(;isspace(ch);ch=getchar());      for(;!isspace(ch);ch=getchar())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace SHENZHEBEI;
const ll N=200010;
ll n,A,sum,p[N];
ld ans,x[N],y[N],X[N],Y[N],z[N];
bool cmp(ll a,ll b){return z[a]<z[b];}
int main(){
//	freopen("distance.in","r",stdin);
//	freopen("distance.out","w",stdout);
	srand(time(0));
	n=read(),A=read();ans=2*A;
	For(i,1,n)y[i]=read(),x[i]=read(),sum+=y[i]==0,z[i]=abs(sqrt(sqr(x[i])+sqr(y[i]-A))-sqrt(sqr(x[i])+sqr(y[i]+A)));
	if (sum>=2)return puts("0"),0;
	For(i,1,n)p[i]=i;sort(p+1,p+n+1,cmp);
	For(i,1,n)X[i]=x[p[i]],Y[i]=y[p[i]];
	For(i,1,n)x[i]=X[i],y[i]=Y[i];
	For(i,1,min(6000,n)){
		For(j,i+1,min(n/i*200,n)){
			if (y[i]==y[j]){Min(ans,abs(abs(y[i]-A)-abs(y[i]+A)));continue;}
			if (x[i]==x[j])continue;
			ld k=(y[i]-y[j])/(x[i]-x[j]),b=y[i]-x[i]*k;
			if (b>=A||b<=-A)continue;
			ld k1=-1/k,b1=A,jiao_x=(b-b1)/(k1-k),jiao_y=b+k*jiao_x;
			ld XinShe_x=2*jiao_x,XinShe_y=2*jiao_y-A;
			Min(ans,sqrt(sqr(XinShe_x)+sqr(-A-XinShe_y)));
		}
		if (clock()>CLOCKS_PER_SEC*0.9)break;
	}printf("%lf",ans);
}
/*
(0,lbc)
lbc>=a||lbc<=-a
ans=a;
|len2-len1|

s[i],s[i]+t[i]
s[i]+t[i]
+ 

nsqrt(n)
*/