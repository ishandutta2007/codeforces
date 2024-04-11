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
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
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
typedef complex<double> E;
namespace cqz{
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
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
	void writeln(ll x){write(x);puts("");}
}using namespace cqz;
const ll N=1000010,mod=1e9+7;
ll Q,ind,n,fa[200010][22],L[N],R[N],c[N],pri[N],dep[N],W[N],ans[N],x[N],y[N],w[N];
ll mark[10000010];
vector<ll>g[N];
vector<pa>has[N];
void Init(){
	ll n=10000000;
	For(i,2,n)if (!mark[i]){
		pri[++pri[0]]=i;
		for(ll j=i;j<=n;j+=i)mark[j]=mark[j]?mark[j]:pri[0];
	}
}
void add(ll x,ll v){for(;x<=n;x+=x&-x)c[x]+=v;}
ll ask(ll x){ll ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
void dfs(ll x){
	L[x]=++ind;
	For(i,1,20)fa[x][i]=fa[fa[x][i-1]][i-1];
	rep(i,0,g[x].size())if (g[x][i]!=fa[x][0]){
		ll to=g[x][i];
		dep[to]=dep[x]+1;
		fa[to][0]=x;
		dfs(to);
	}
	R[x]=ind;
}
ll lca(ll a,ll b){
	if (dep[a]<dep[b])swap(a,b);
	FOr(i,20,0)if (dep[a]-(1<<i)>=dep[b])a=fa[a][i];
	FOr(i,20,0)if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return a==b?a:fa[a][0];
}
void work(ll x,ll w){
	for(;w>1;){
		ll cnt=0,cur=mark[w];
		for(;!(w%pri[cur]);w/=pri[cur],++cnt)
		if (x>=0)has[cur].push_back(mk(cnt+1,x));
		if (x<0)has[cur].push_back(mk(cnt,x));
	}
}
ll ppow(ll x,ll k){ll ans=1;for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);return ans;}
bool cmp(pa a,pa b){return a.fi==b.fi?(a.se>b.se):(a.fi<b.fi);}
int main(){
	n=read();Init();
	rep(i,1,n){
		ll x=read(),y=read();
		g[x].push_back(y);g[y].push_back(x);
	}
	For(i,1,n)W[i]=read();
	dfs(1);
	Q=read();
	For(i,1,n)work(i,W[i]);
	For(i,1,Q){x[i]=read(),y[i]=read(),w[i]=read(),ans[i]=1;work(-i,w[i]);}
	For(i,1,pri[0])if (has[i].size()){
		sort(has[i].begin(),has[i].end(),cmp);
		rep(j,0,has[i].size()){
			if (has[i][j].se>=0){
				add(L[has[i][j].se],1);
				add(R[has[i][j].se]+1,-1);
			}else{
				ll a=x[-has[i][j].se],b=y[-has[i][j].se],Lca=lca(a,b),
					Value=ask(L[a])+ask(L[b])-ask(L[Lca])-ask(L[fa[Lca][0]]);
				Mul(ans[-has[i][j].se],ppow(pri[i],Value));
			}
		}
		rep(j,0,has[i].size())if(has[i][j].se>=0){
			add(L[has[i][j].se],-1);
			add(R[has[i][j].se]+1,1);
		}
	}
	For(i,1,Q)writeln(ans[i]);
}