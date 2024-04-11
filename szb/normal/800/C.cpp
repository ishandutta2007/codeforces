#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ld long double
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
const ll N=200010;
ll n,f[N],g[N],q[N],cur[N],sum[N],lbc,MOD,ttt,top,bel[N],vis[N],pos[N];
vector<ll>h[N];
void exgcd(ll a,ll b,ll &x,ll &y){
	if (!b){	x=1;	y=0;	return;	}
	exgcd(b,a%b,y,x);	y-=a/b*x;
}
ll GET_inv(ll x,ll mod){
	ll X,Y;
	exgcd(x,mod,X,Y);
	return (X+mod)%mod;
}
ll MK(ll a,ll b){//a->b 
	//pp(a,b);
	ll cur_a=a,cur_b=b;
	ll A=__gcd(a,MOD),B=__gcd(b,MOD),mod=MOD;
	a/=A;b/=B;mod/=B;
	ll ans=B/A*b%MOD*GET_inv(a,mod)%MOD;
//	if (cur_a*ans%MOD!=cur_b)while(1)pp(cur_a,cur_b);
	return ans;
}
void Write(ll x){
	if (x||!vis[x])write(x),putchar(' ');
}
int main(){
	lbc=read();	MOD=n=read();
	For(i,1,n)if (!(n%i))q[++top]=i;
	sort(q+1,q+top+1);
	For(i,1,top)pos[q[i]]=i;
//	For(i,1,ttt)p(g[i]);
	rep(i,1,n)bel[i]=__gcd(i,n),++sum[pos[bel[i]]];
	while(lbc--){
		ll x=read();
		vis[x]=1;
		--sum[pos[bel[x]]];
	}
//	writeln(bel[12]);
//	writeln(bel[700]);
	For(i,1,top)f[i]=sum[i];ll tt=top;
//	rep(i,1,top)writeln(sum[i]);
	For(i,1,top)	For(j,i+1,top)if (!(q[j]%q[i]))
	if (f[i]+sum[j]>f[j])	f[j]=f[i]+sum[j],cur[j]=i;
	writeln(f[top]+!vis[0]);top=0;memset(q,0,sizeof q);
	rep(i,1,n)if (!vis[i])h[pos[bel[i]]].push_back(i);
	for(ll i=tt;i;i=cur[i]){
		rep(j,0,h[i].size())	q[++top]=h[i][j];
	}Write(q[top]);
	while(top--)Write(MK(q[top+1],q[top]));
}
/*
n=p1^a1*p2^a2*p3^a3*p4^a4..
a1,a2,a3,a4,a5..
 
a->b
a*x%mod=b
A=gcd(a,mod)
B=gcd(b,mod)
a*x%mod=b
x%mod=b*a-1
4 3 2 1 0
*/