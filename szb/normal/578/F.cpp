#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)		(x)*(x)
#define abs(x)		(x)>0?(x):-(x)
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
#define E(x) 		return writeln(x),0
#define p(x)		printf("~%d~\n",x)
#define pp(x,y)		printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)	printf("~~~%d %d %d~~~\n",x,y,z)
#define f_in(x)		freopen(x".in","r",stdin)
#define f_out(x) 	freopen(x".out","w",stdout)
#define open(x)		f_in(x),f_out(x)
#define fi first
#define se second
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
const ll N=21000;
char s[410][410];
ll a[410][410],n,m,mod,ans,fa[N],ID[N];
void lnk(ll x,ll y){
Add(a[x][y],mod-1),Add(a[y][x],mod-1);
Add(a[x][x],1),Add(a[y][y],1);
}
ll id(ll x,ll y){	return (x)*(m+1)+(y);	}
#define X find(id(i,j+(i+j+tp)%2))
#define Y find(id(i+1,j+1-(i+j+tp)%2))
ll inv(ll x){ll ans=1,k=mod-2;for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);return ans;}
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll gauss(ll n){
	ll ans=1;
	rep(i,0,n)rep(j,0,n)Add(a[i][j],mod);
//	writeln(n);
	rep(i,0,n){
		ll j=i;while(j<n&&!a[j][i])++j;
		if (j==n)return 0;
		if (i^j){rep(k,0,n)swap(a[i][k],a[j][k]);Mul(ans,-1);Add(ans,mod);}
		For(j,i+1,n){
			ll t=(-a[j][i]*inv(a[i][i])%mod+mod)%mod;
			rep(k,i,n)Add(a[j][k],t*a[i][k]);
		}Mul(ans,a[i][i]);
	}return ans;
}
int main(){
	n=read();m=read();mod=read();
	rep(i,0,n)readstr(s[i]);
	rep(tp,0,2){
		ll ecnt=0,vcnt=0;
		For(i,0,n)For(j,0,m)fa[id(i,j)]=id(i,j);
		rep(i,0,n)rep(j,0,m)if (s[i][j]=='*')++ecnt;lf (s[i][j]=='/'^((i+j)%2==tp))if((X)==(Y))vcnt=-1e9;else fa[X]=Y;
		if (vcnt<0)continue;
		For(i,0,n)For(j,0,m)if (((i+j)%2==tp)&&find(id(i,j))==id(i,j))	ID[id(i,j)]=vcnt++;
		rep(i,0,vcnt)rep(j,0,vcnt)a[i][j]=0;
		rep(i,0,n)rep(j,0,m)if (s[i][j]=='*')	lnk(ID[X],ID[Y]);
		Add(ans,gauss(vcnt-1));
		rep(i,0,vcnt)ID[i]=0;
	}
	writeln((ans+mod)%mod);
}