

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
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define E(x)        return writeln(x),0
#define LL			(long long)
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
#define y1			fafa____
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,GYN,stdin); if (S==T) return '\n';  }   return *S++;    }
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
	ll max(ll x,ll y){return x<y?y:x;}
}using namespace SHENZHEBEI;
const ll N=4010,M=80,mod=998244353;
ll c[M][M],k,ans;
struct lzh{
#define more(i,x,y)	for(ll i=x;i<=y;i+=2)
	vector<ll>I[N];
	ll f[N][M],g[N][M],h[N][M],sum[N][M],n;
	void dfs(ll x,ll fa){
		rep(i,0,I[x].size()){
			ll to=I[x][i];
			if (to==fa)continue;
			dfs(to,x);
			more(i,0,k)Add(sum[x][i],f[to][i]);
		}f[x][0]=1;
		more(i,2,k)more(j,0,i-2)
			Add(f[x][i],sum[x][j]*f[x][i-j-2]);
//		Print(f[x],0,k);
	}
	void Dfs(ll x,ll fa){
		more(i,0,k)Add(sum[x][i],g[x][i]);
		h[x][0]=1;
		more(i,2,k)more(j,0,i-2)Add(h[x][i],sum[x][j]*h[x][i-j-2]);
		rep(i,0,I[x].size()){
			ll to=I[x][i];
			if (to==fa)continue;
			more(i,0,k)Add(sum[x][i],-f[to][i]);
			g[to][0]=1;
			more(i,2,k)more(j,0,i-2)
				Add(g[to][i],sum[x][j]*g[to][i-j-2]);
			Dfs(to,x);
			more(i,0,k)Add(sum[x][i],f[to][i]);
		}
	}
	void work(){
		rep(i,1,n){
			ll x=read(),y=read();
			I[x].push_back(y);
			I[y].push_back(x);
		}
		dfs(1,0);
		Dfs(1,0);
//		For(i,1,n){
//			For(j,0,k)write(h[i][j]),putchar(' ');
//			puts("");
//		}
	}
}A,B;
int main(){
	A.n=read(),B.n=read();k=read();
	if (k&1)return puts("0"),0;
	A.work(),B.work();
	For(i,0,75)For(j,0,i)c[i][j]=j?(c[i-1][j-1]+c[i-1][j])%mod:1ll;
	For(l,0,k){
		ll ans1=0,ans2=0;
		For(i,1,A.n)Add(ans1,A.h[i][l]);
		For(i,1,B.n)Add(ans2,B.h[i][k-l]);
		Add(ans,ans1*ans2%mod*c[k][l]);
	}
	Add(ans,mod);
	writeln(ans);
}