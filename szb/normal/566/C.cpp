#include <unistd.h> 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(ll i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(ll i=(ll)(x);i>=(ll)(y);--i)
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
	void writeln(ll x){write(x);putchar('\n');}
	#define Max(x,y)	((x)=(x)<(y)?(y):(x))
}using namespace SHENZHEBEI;
const ll N=800010;
ll head[N],nxt[N],vet[N],val[N],siz[N],a[N],vis[N];
ll pos,n,Rt,mn,tot,sum,tmp=1e9;
double f1,f2,ans=1e100;
void insert(ll x,ll y,ll w){nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;val[tot]=w;}
void GetSz(ll x){
	siz[x]=1;vis[x]=1;
	for(ll i=head[x];i;i=nxt[i])if (!vis[vet[i]])
		GetSz(vet[i]),siz[x]+=siz[vet[i]];
	vis[x]=0;
}
ll GetRt(ll x){
	ll mx=sum-siz[x];vis[x]=1;
	for(ll i=head[x];i;i=nxt[i])if(!vis[vet[i]])
		GetRt(vet[i]),Max(mx,siz[vet[i]]);
	if(mx<mn)mn=mx,Rt=x;vis[x]=0;
}
ll calc(ll x,ll fa,ll dis){
	f1+=sqrt(dis)*a[x];
	f2+=sqrt(dis)*dis*a[x];
	for(ll i=head[x];i;i=nxt[i])if (vet[i]!=fa)
		calc(vet[i],x,dis+val[i]);
}
void solve(ll x){
//	writeln(x);
	GetSz(x);
	sum=siz[x];mn=1e9;
	GetRt(x);
	vis[Rt]=1;
	ll tmp=Rt;	double mx=f2=0;
	for(ll i=head[Rt];i;i=nxt[i]){
		f1=0;
		calc(vet[i],Rt,val[i]);
		if (f1>mx)mx=f1,tmp=vet[i];
	}
	if (f2<ans)ans=f2,pos=Rt;
//	sleep(1);
	if(!vis[tmp])solve(tmp);
}
int main(){
	n=read();For(i,1,n)a[i]=read();
	rep(i,1,n){ll x=read(),y=read(),w=read();insert(x,y,w);insert(y,x,w);}
	solve(1);
	printf("%lld %.10f",pos,ans);
}