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
#define GuYueNa		puts("GYN_________________________________________")
typedef complex<double> E;
namespace _GuYueNa{
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
}using namespace _GuYueNa;
const ll N=10010;
bitset<N>ok,g[N];
ll f[N],Pre[N];
ll a[N],b[N],c[N],l,r,n,m,sum,ans,lzh;
int main(){
	n=read(),l=read(),r=read(); 
	For(i,1,n)a[i]=read(),lzh+=a[i];Min(r,lzh);
	ok[0]=1;
	For(i,1,n){
		b[i]=read();
		if (b[i])c[++m]=a[i];
		else ok|=ok<<a[i],sum+=a[i];
	}sort(c+1,c+m+1);
	g[m+1]=g[m+2]=ok;
	FOr(i,m,1)g[i]=g[i+1]|(g[i+1]<<c[i]);
	memset(f,-60,sizeof f);f[0]=sum=0;
	if (m)For(i,l,r)if (g[m+1][i])ans=1;
	For(i,1,m){
		FOr(j,sum,0)Max(f[j+c[i]],f[j]+1);
		sum+=c[i];ll up=min(r-l,sum);
		ll frog=0,pos=l-sum;
		For(j,l-sum,r-sum)if (j>=0)frog+=g[i+2][j];
		For(j,0,up){
			if (frog)Max(ans,f[j]+(i!=m));
			if (pos>=0)frog-=g[i+2][pos];pos++;
		}
	}writeln(ans);
}