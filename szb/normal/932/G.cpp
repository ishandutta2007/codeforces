#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(int i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(int i=(ll)(x);i>=(ll)(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
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
    inline void write(long long x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);}
    void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
    void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
    void writeln(ll x){write(x);puts("");}
    void Min(ll &x,ll y){x=x<y?x:y;}
    void Max(ll &x,ll y){x=x>y?x:y;}
}using namespace SHENZHEBEI;
const ll N=1000010,mod=1e9+7;
char s[N],t[N];
int c[N][30];
ll f[N],g[N],len[N],pre[N],diff[N],gg[N],n;
struct Pam{
	ll now,cnt,p,np,q,nq,ch;
	Pam(){
		pre[0]=1;pre[1]=0;
		len[0]=0;len[1]=-1;
		now=0;cnt=1;
	}
	void extend(ll x){
		p=now,ch=s[x]-'a';
		for(;s[x-len[p]-1]!=s[x];p=pre[p]);
		if (!c[p][ch]){
			len[np=++cnt]=len[p]+2;
			q=pre[p];
			for(;s[x]!=s[x-len[q]-1];q=pre[q]);
			pre[np]=c[q][ch];
			c[p][ch]=np;
			diff[np]=len[np]-len[pre[np]];
			if (diff[np]==diff[pre[np]])
				gg[np]=gg[pre[np]];
			else	gg[np]=pre[np];
		}now=c[p][ch];
	}
}Pam;
int main(){
	n=readstr(t+1);
	For(i,1,n/2)	s[i*2-1]=t[i],s[i*2]=t[n+1-i];
	f[0]=1;
	For(i,1,n){
		Pam.extend(i);
//		writeln(i);
		for(ll p=Pam.now;p>1;p=gg[p]){
			g[p]=f[i-len[gg[p]]-diff[p]];//
			if (diff[p]==diff[pre[p]])	Add(g[p],g[pre[p]]);
			if (!(i&1))Add(f[i],g[p]);
		}
	}writeln(f[n]);
}