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
#define mul(x,y)	x=x*(y)%mod
#define Add(x,y)	x=(x+(y))%mod
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
const ll N=110,mod=1e9+7;
ll inv[N],g[N][N],f[N][N],F[N][N],n,m;
int main(){
	n=read();	m=read();
	inv[0]=inv[1]=1;
	For(i,2,n)	inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	f[0][1]=1;
	For(i,1,n)	For(j,1,i+1){
		For(p,0,i-1)For(q,j,p+1)	Add(g[i][j],f[p][q]*f[i-1-p][j]);//mincost=j
		For(p,0,i-1)For(q,j+1,i-p)	Add(g[i][j],f[p][j]*f[i-1-p][q]);//g->1 
		memset(F,0,sizeof F);
		For(k,0,n)For(p,1,k+1){
			ll cost=1;
			for(ll q=1;k+q*i<=n;++q)	cost=cost*(g[i][j]+q-1)%mod*inv[q]%mod,
										Add(F[k+q*i][p+q*j],f[k][p]*cost);
		}
		For(p,0,n)For(q,1,p+1)	Add(f[p][q],F[p][q]);
	}
	writeln((f[n][m]+mod)%mod);
}