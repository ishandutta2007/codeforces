#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    (x=1LL*(x)*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYueNa		puts("GYN_________________________________________")
typedef complex<double> E;
namespace _GuYueNa{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    inline char gc(){   return getchar();   }	
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc()aaaaaaaaaaaaa)  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace _GuYueNa;
const ll N=200010;
ll from[N][2],dfn[N],low[N],q[N],vis[N],n,m,S,ind,top;
vector<ll>g[N],h[N];
bool dfs(ll x,ll sum){
	rep(i,0,g[x].size())if (!from[g[x][i]][sum^1]){
		from[g[x][i]][sum^1]=x;
		dfs(g[x][i],sum^1);
	}
}
void dfs(ll x){
	dfn[x]=low[x]=++ind;q[++top]=x;vis[x]=1;
	rep(i,0,h[x].size()){
		ll to=h[x][i];
		if (!vis[to])dfs(to),Min(low[x],low[to]);
		else	Min(low[x],dfn[to]);
	}
	if (low[x]==dfn[x]){
		ll sz=0;
		for(;q[top+1]!=x;--top,++sz)vis[q[top]]=0;
		if (sz>1){
			puts("Draw");
			exit(0);
		}
	}
}
int main(){
	n=read(),m=read();
	For(i,1,n)for(ll sz=read();sz--;){ll to=read();g[to].push_back(i),h[i].push_back(to),++dfn[i];}
	For(i,1,n)if (!dfn[i])from[i][1]=i,dfs(i,1);
	S=read();
	if (from[S][0]){
		puts("Win"); ll frog;
		for(S,frog=0;dfn[S];S=from[S][frog],frog^=1)write(S),putchar(' ');write(S);
	}else{
		memset(dfn,0,sizeof dfn);
		dfs(S);puts("Lose");
	}
}