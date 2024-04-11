#include<bits/stdc++.h>
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))    
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
const ll N=500010;
ll sz[N],fa[N],X[N],Y[N],q[N],n,m,top,w[N],Q,wa[N];
vector<pa>ask[N];
ll find(ll x){	while(x^fa[x])	x=fa[x];	return x;	}
void merge(ll x,ll y){	if (sz[x]>sz[y])	swap(x,y);	fa[x]=y,sz[y]+=sz[x],q[++top]=x;}
void Clear(){	while(top)	sz[fa[q[top]]]-=sz[q[top]],fa[q[top]]=q[top--];	}
int main(){
	n=read();	m=read();
	For(i,1,n)	fa[i]=i,sz[i]=1;
	For(i,1,m)	X[i]=read(),Y[i]=read(),w[i]=read(),ask[w[i]].push_back(mk(0,i));
	Q=read();	For(i,1,Q){	ll k=read(),QWQ;	while(k--)	QWQ=read(),ask[w[QWQ]].push_back(mk(i,QWQ));	}
	rep(i,1,N){
		sort(ask[i].begin(),ask[i].end());	bool WA=0;
		for(ll j=0;j<ask[i].size();j++)	if (ask[i][j].fi){
			ll to=ask[i][j].se,x=find(X[to]),y=find(Y[to]);
			if (x==y) WA=1;	else	merge(x,y);
			if ((j+1==ask[i].size())||(ask[i][j].fi^ask[i][j+1].fi))	Clear(),wa[ask[i][j].fi]|=WA,WA=0;
		}
		for(ll j=0;j<ask[i].size();j++)	if (!ask[i][j].fi){
			ll to=ask[i][j].se,x=find(X[to]),y=find(Y[to]);
			if (x^y)	merge(x,y);
		}top=0;
	}For(i,1,Q)	puts(!wa[i]?"YES":"NO");
}