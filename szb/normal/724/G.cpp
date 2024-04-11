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
const ll N=800010,mod=1e9+7;
ll head[N],nxt[N],vet[N],val[N],n,m,tot=1,rev[N],ans,bin[N],vis[N],sz,lbc[100];
struct dt{
	ll c[N],node;
	dt(){	node=0;	}
	void clear(){
		node=0;
		For(i,0,60)c[i]=lbc[i]=0;
	}
	void insert(ll x){
		FOr(i,60,0)if (x>>i&1){
			if (!c[i])	return c[i]=x,++node,void(0);
			else	x^=c[i];
		}
	}
	ll count(ll w){
		bool fl=0;
		For(i,0,60)	fl|=c[i]>>w&1;
		return fl;
	}
}xxj;
void insert(ll x,ll y,ll w){	nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;val[tot]=w;	}
void dfs(ll x,ll pre){
	vis[x]=1;++sz;
	For(i,0,60)lbc[i]+=rev[x]>>i&1;
	for(ll i=head[x];i;i=nxt[i])
	if (i^pre)	if (!vis[vet[i]])rev[vet[i]]=rev[x]^val[i],dfs(vet[i],i^1);
	else	xxj.insert(rev[vet[i]]^rev[x]^val[i]);
}
int main(){
	n=read();m=read();
	For(i,1,m){
		ll x=read(),y=read(),w=read();
		insert(x,y,w);	insert(y,x,w);
	}
	bin[0]=1;	For(i,1,n)	bin[i]=bin[i-1]*2%mod;
	For(rt,1,n)if (!vis[rt]){
		xxj.clear();
		sz=0;	dfs(rt,0);
		For(i,0,60){
			if (xxj.count(i))	ans+=sz*(sz-1)/2%mod*bin[xxj.node-1+i]%mod;
			else	ans+=lbc[i]*(sz-lbc[i])%mod*bin[xxj.node+i]%mod;
		}
	}writeln(ans%mod);
}