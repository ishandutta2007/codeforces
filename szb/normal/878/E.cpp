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
const ll N=1000010,mod=1e9+7;
vector<pa>g[N];
ll fa[N],pre[N],sum[N],bin[N],a[N],n,Q,answ[N],SUM[N],zyy[N];
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);	}
void merge(ll x,ll y){	fa[x]=y;	pre[y]=pre[x];	SUM[y]=min((min(mod,SUM[y])<<min(31LL,(x-pre[x])))+SUM[x],mod);	}
ll Query(ll l,ll r){	return (sum[l]-sum[r+1]*bin[r-l+1])%mod;	}
int main(){
	n=read();	Q=read();
	bin[0]=1;
	For(i,1,n)	bin[i]=bin[i-1]*2%mod,a[i]=read();
	For(i,1,Q){
		ll l=read(),r=read();
		g[r].push_back(mk(l,i));
	}
	For(i,1,n)	fa[i]=i,pre[i]=i-1,SUM[i]=a[i];
	FOr(i,n,1)	sum[i]=(sum[i+1]*2+a[i])%mod;
	For(i,1,n){
		while(pre[i]&&SUM[i]>=0)	merge(pre[i],i);
		zyy[i]=(zyy[pre[i]]+Query(pre[i]+1,i)*2)%mod;
		for(ll j=0;j<g[i].size();++j){
			ll to=find(g[i][j].fi);
			answ[g[i][j].se]=(zyy[i]-zyy[to]+Query(g[i][j].fi,to))%mod;
		}
	}For(i,1,Q)	writeln((answ[i]+mod)%mod);
}