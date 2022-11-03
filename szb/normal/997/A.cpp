#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=int(x);i<int(y);++i)
#define For(i,x,y)  for(int i=int(x);i<=int(y);++i)
#define FOr(i,x,y)  for(int i=int(x);i>=int(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define E(x)        return writeln(x),0
#define LL          (long long)
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)   printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue       puts("\nGuYueNa________________________________________________________________________________")
#define y1          fafa____
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*SS=SZB,*TT=SZB;
    inline char gc(){   if (SS==TT){  TT=(SS=SZB)+fread(SZB,1,GYN,stdin); if (SS==TT) return '\n';  }   return *SS++;    }
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
    void writeln(ll x){write(x),puts("");}
    void Max(ll &x,ll y){x=x<y?y:x;}
    void Min(ll &x,ll y){x=x>y?y:x;}
    ll min(ll x,ll y){return x<y?x:y;}
}using namespace SHENZHEBEI;
const ll N=600010;
ll n,a,b,cnt,ans;
char s[N];
int main(){
	n=read();a=read(),b=read();
	readstr(s+1);s[n+1]='1';
	for(int i=1;i<=n;++i)if (s[i]=='0'){
		ll j=i;
		for(;s[j+1]=='0';++j);
		i=j;
		++cnt;
	}
	for(;cnt>1;--cnt,ans+=min(a,b));
	writeln(ans+b*cnt);
}
/*
01010101
1010100
*/