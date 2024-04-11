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
priority_queue<pa>q;
const ll N=600020;vector<ll>g[N];
ll rt,sz[N],head[N],nxt[N],vet[N],fa[N/2][23],val[N],n,m,tot,dep[N],dis[N],ans;
bool vis[N];
void insert(ll x,ll y,ll w){	nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;val[tot]=w;}
ll lca(ll x,ll y){
	if (dep[x]>dep[y])swap(x,y);
	ll t=dep[y]-dep[x];
	FOr(i,20,0)if (t>>i&1)	y=fa[y][i];
	FOr(i,20,0)if (fa[x][i]^fa[y][i])x=fa[x][i],y=fa[y][i];
	return x^y?fa[x][0]:x;
}
void insert(ll x,ll pre){
	dep[x]=dep[pre]+1;	fa[x][0]=pre;
	For(i,1,20)fa[x][i]=fa[fa[x][i-1]][i-1];
	g[pre].push_back(x);
}
void dijstra(ll x){
	ll he=0,ta=1;	q.push(mk(0,x));
	memset(dis,60,sizeof dis);	dis[x]=0;
	while(!q.empty()){
		ll x=q.top().second;q.pop();
		if (vis[x])continue;
		vis[x]=1;
		ll pra=0;
		for(ll i=head[x];i;i=nxt[i])
		if (dis[vet[i]]==dis[x]-val[i])	pra=pra?lca(pra,vet[i]):vet[i];
		insert(x,pra);
		for(ll i=head[x];i;i=nxt[i])
		if (dis[vet[i]]>dis[x]+val[i]){
			dis[vet[i]]=dis[x]+val[i];
			q.push(mk(-dis[vet[i]],vet[i]));
		}
	}
}
void dfs(ll x){	sz[x]=1;	rep(i,0,g[x].size())dfs(g[x][i]),sz[x]+=sz[g[x][i]];	}
int main(){
	n=read(),m=read();rt=read();
	For(i,1,m){
		ll x=read(),y=read(),w=read();
		insert(x,y,w),insert(y,x,w);
	}dijstra(rt);
	dfs(rt);For(i,1,n)if (i^rt)ans=max(ans,sz[i]);
	writeln(ans);
}