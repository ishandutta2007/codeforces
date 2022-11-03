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
#define mk make_pair<ld,ld>
#define pa pair<ld,ld>
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
#define p(x)        prllf("~%d~\n",x)
#define pp(x,y)     prllf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  prllf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(a,b,c,d)	prllf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 1
    const ll L=2333333;
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
    inline ll readstr(char *s){ char ch=gc();   ll cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
ll n,d,b,a[1000010],dd,x1,x2,ddd,f1[1000010],f2[1000010],l,r;
int main(){
	n=read();d=read();b=read();dd=n/2*b;
	For(i,1,n)a[i]=read();
	For(i,1,n)f1[i]=min(a[i],dd)+f1[i-1],dd-=min(a[i],dd);
	dd=n/2*b;
	FOr(i,n,1)f2[i]=min(a[i],dd)+f2[i+1],dd-=min(a[i],dd);
	dd=n/2;ddd=0;
	For(i,1,dd){
		r+=d+1;r=min(r,n);
		if (ddd+b<=f1[r])ddd+=b;else x1++; 
	}dd=(n+1)/2+1;ddd=0;l=n+1;
	FOr(i,n,dd){
		l-=d+1;l=max(1ll,l);
		if (ddd+b<=f2[l])ddd+=b;else x2++; 
	}writeln(max(x1,x2));
}