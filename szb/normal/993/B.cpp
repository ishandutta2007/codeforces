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
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    (x=(x)*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define E(x)        return writeln(x),0
#define p(x)        printf("~%d~\n",x)
#define pp(x,y)     printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(x,y,z,a)  printf("~~~%d %d %d %d~~~\n",x,y,z,a)
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
const ll N=200010;
pa a[N],b[N];
ll dfn[N],n,m,dfn1[N],dfn2[N],sum1,sum2,sum3,sum4,sum,answ;
ll jiao(pa a,pa b){
	return (a.fi==b.fi)+(a.fi==b.se)+(a.se==b.fi)+(a.se==b.se);
}
ll Jiao(pa a,pa b){
	return (a.fi==b.fi?a.fi:0)+(a.fi==b.se?a.fi:0)+(a.se==b.fi?a.se:0)+(a.se==b.se?a.se:0);
}
int main(){
	n=read(),m=read();
	For(i,1,n){
		a[i].fi=read();
		a[i].se=read();
		if (a[i].fi>a[i].se)swap(a[i].fi,a[i].se);
	}
	For(i,1,m){
		b[i].fi=read();
		b[i].se=read();
		if (b[i].fi>b[i].se)swap(b[i].fi,b[i].se);
	}
	For(i,1,n)For(j,1,m)if (jiao(a[i],b[j])==1){
		++dfn[Jiao(a[i],b[j])];
	}
	For(i,1,9)if (dfn[i])++sum,answ=i;
	if(sum==1)writeln(answ);
	else{
		bool frog=1;
		For(i,1,n){
			ll sum=0,cur=0;
			For(j,1,m)if (jiao(a[i],b[j])==1){
				if (!cur)cur=Jiao(a[i],b[j]);
				else	frog&=cur==Jiao(a[i],b[j]);
			}
		}
		For(i,1,m){
			ll sum=0,cur=0;
			For(j,1,n)if (jiao(a[j],b[i])==1){
				if (!cur)cur=Jiao(a[j],b[i]);
				else	frog&=cur==Jiao(a[j],b[i]);
			}
		}
		writeln(frog?0:-1);
	}
}