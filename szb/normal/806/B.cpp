#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))    
#define EXIT(x)	return writeln(x),0;
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
const ll N=510;
ll inf[]={0,500,1000,1500,2000,2500,3000};
ll zhuang_tai[N],MK[N][N],answ=1e18,a[N][N],n,win[N];
bool work(ll x){
	ll fir=0,sed=0;
	For(i,1,5){
		ll WIN=win[i],sum=n+x,now;
		if (a[2][i]!=-1&&a[1][i]>a[2][i])	WIN+=x;
		double t=1.0*WIN/sum;
		if (t>1.0/2)	now=500;
		lf (t>1.0/4)	now=1000;
		lf (t>1.0/8)	now=1500;
		lf (t>1.0/16)	now=2000;
		lf (t>1.0/32)	now=2500;
		else	now=3000;
		fir+=(~a[1][i])?(now/500*(500-a[1][i]*2)):0;
		sed+=(~a[2][i])?(now/500*(500-a[2][i]*2)):0;
	}
	return fir>sed;
}
int main(){
	n=read();
	For(i,1,n)	For(j,1,5){
		a[i][j]=read();
		if (~a[i][j])	win[j]++;
	}
	For(i,0,10000)	if (work(i))	return writeln(i),0;
	puts("-1");
}
/*
ac/(ac+wa)>1/4
ac>(ac+wa)/4
ac/2>wa/2
ac>wa
*/