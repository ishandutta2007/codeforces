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
const ll N=60;
bool cmp(pa a,pa b){return a.fi==b.fi?(a.se<b.se):(a.fi<b.fi);}
void Min(ll &x,ll y){x=x<y?x:y;}
ll f[60][60][6010],n;
pa a[N];
double answ;
int main(){
	n=read();
	For(i,1,n)a[i].fi=read();
	For(i,1,n)a[i].se=read();
	sort(a+1,a+n+1,cmp);
	memset(f,60,sizeof f);
	f[0][0][0]=0;
	For(i,1,n){
		ll pos=i;
		for(;a[pos+1].fi==a[pos].fi;++pos);
		For(j,i+1,pos)a[j].se+=a[j-1].se,a[j].fi+=a[j-1].fi;
		a[i-1].se=a[i-1].fi=0;
		For(j,0,min(n/2+2,i-1))
		For(k,0,100*(i-1)){
			For(p,i-1,pos){
				ll left=p-i+1,rigt=pos-p;
				Min(f[pos][max(0ll,j-left)+rigt][k+a[p].se],f[i-1][j][k]+a[p].fi);
				Min(f[pos][max(0ll,j-rigt)+left][k+a[pos].se-a[p].se],f[i-1][j][k]+a[pos].fi-a[p].fi);
			}
		}
		i=pos;
	}answ=1e18;
	For(i,1,6000)answ=min(answ,1000.0*f[n][0][i]/i);
	if (abs(answ-(ll)answ)<1e-9)writeln(answ);
	else						writeln(answ+1);
}
/*
 
f[i][j][k]
ij, 
*/