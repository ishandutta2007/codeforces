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
const ll N=200010,mod=1e9+7;
struct dt{ll m[4][4];}tmp,st,zy;
ll q[N],l[N],r[N],a[N],f[N],n,m,tot;
dt cheng(dt a,dt b){
	memset(tmp.m,0,sizeof tmp.m);
	For(i,1,3)For(j,1,3)For(k,1,3)
		Add(tmp.m[i][k],a.m[i][j]*b.m[j][k]);
	return tmp;
}
void Print(dt a){
	For(i,1,3){
		For(j,1,3)printf("%lld ",a.m[i][j]);
		puts("");
	}puts("GYN________________________________________________");
}
int main(){
	n=read(),m=read();
	For(i,1,n)	a[i]=read(),l[i]=read(),r[i]=read(),q[++tot]=l[i],q[++tot]=r[i]+1;
	q[++tot]=1;q[++tot]=2;q[++tot]=m;q[++tot]=m+1;
	sort(q+1,q+tot+1);tot=unique(q+1,q+tot+1)-q-1;
	For(i,1,n){
		ll LS=lower_bound(q+1,q+tot+1,l[i])-q,RS=lower_bound(q+1,q+tot+1,r[i]+1)-q-1,zt=1<<a[i]-1;
		For(j,LS,RS)f[j]|=zt;
	}
	rep(i,1,tot)if (f[i]==7)return puts("0"),0;
	st.m[1][2]=1;
	rep(i,2,tot){
		ll len=q[i+1]-q[i],now=f[i];
		memset(zy.m,0,sizeof zy.m);
		For(i,1,3)For(j,i-1,i+1)if ((j>0)&&(j<4)&&!(now>>(j-1)&1))
			zy.m[i][j]=1;
		for(;len;len>>=1,zy=cheng(zy,zy))if (len&1)st=cheng(st,zy);
	}writeln(st.m[1][2]);
}