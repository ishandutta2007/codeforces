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
#define mul(x,y)	x=x*(y)%mod
#define Add(x,y)	x=(x+(y))%mod
#define EXIT(x)	return writeln(x),0;
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 0
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
const ll N=50010,inf=200;
ll mn[N],mx[N],from[N],q[N],head[N],nxt[N],vet[N],val[N],cost[N],vis[N],dis[N],n,Q,tot=1,SS,TT;
void insert(ll x,ll y,ll w,ll c){	nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;val[tot]=w;cost[tot]=c;	}
void addedge(ll x,ll y,ll w,ll c){	/*printf("%lld %lld %lld %lld\n",x,y,w,c);*/insert(x,y,w,c);insert(y,x,0,-c);	}
bool spfa(){
	ll he=0,ta=1;	q[1]=SS;
	For(i,SS,TT)	dis[i]=inf,vis[i]=0;	dis[SS]=0;	vis[SS]=1;
	while(he^ta){
		ll x=q[++he];vis[x]=0;
		for(ll i=head[x];i;i=nxt[i])
		if ((val[i]&&dis[vet[i]]>dis[x]+cost[i])){
			dis[vet[i]]=dis[x]+cost[i];
			from[vet[i]]=i;
			if (!vis[vet[i]])	q[++ta]=vet[i],vis[vet[i]]=1;
		}
	}return dis[TT]!=inf;
}
ll mincost(){
	ll ccc=0;
	while(spfa()){
		for(ll i=TT;i^SS;i=vet[from[i]^1]){
			ccc+=cost[from[i]],val[from[i]]--,val[from[i]^1]++;
//			For(j,1,1000000000);
		}
	}
	return ccc;
}
int main(){
	n=read();Q=read();
	For(i,1,n)	mn[i]=1,mx[i]=n;
	For(i,1,Q){
		ll tp=read(),l=read(),r=read(),w=read();
		For(i,l,r)	if (tp==1)	mn[i]=max(mn[i],w);
		else	mx[i]=min(mx[i],w);
	}SS=0;TT=2*n+1;
	For(i,1,n)if (mn[i]>mx[i])	return puts("-1"),0;
	For(i,1,n)For(j,1,n)addedge(i,TT,1,2*j-1);
	For(i,1,n)addedge(SS,i+n,1,0);
	For(i,1,n)For(j,mn[i],mx[i])addedge(i+n,j,1,0);
	writeln(mincost());
}
/*
k!/(n^k)*||(a[i]-b[i])/b[i]!
f[x]->x^j*(a[i]-j)/j!
*/