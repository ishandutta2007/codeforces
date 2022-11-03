#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(int i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(int i=(ll)(x);i>=(ll)(y);--i)
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
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*SS=SZB,*TT=SZB;
    inline char gc(){   if (SS==TT){  TT=(SS=SZB)+fread(SZB,1,GYN,stdin); if (SS==TT) return '\n';  }   return *SS++;    }
#if NEG
    inline ll read(){    ll x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(long long x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
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
	void Min(ll &x,ll y){x=x<y?x:y;}
	void Max(ll &x,ll y){x=x>y?x:y;}
}using namespace SHENZHEBEI;
const ll N=400010;
vector<ll>g[N];
vector<ll>lzh;
ll dep[N],a[N],b[N],fa[N],vis[N],cqz,n,zyy,sum,best,Best,Rt,id1,id2,ans;
void dfs(ll x){	rep(i,0,g[x].size()){	ll to=g[x][i];	if (to==fa[x])continue;	fa[to]=x;	dep[to]=dep[x]+1;	dfs(to);	}	}
ll lca(ll x,ll y){for(;x!=y;x=fa[x])if (dep[x]<dep[y])swap(x,y);return x;}
bool fafa(){
	best=0,Best=0;
	For(i,1,n)if (a[i]!=b[i])best=dep[best]<dep[i]?i:best;
	if (!best)return 1;
	for(ll i=best;vis[i]=1,lzh.push_back(i),a[fa[i]]!=b[fa[i]];i=fa[i]);

	For(i,1,n)if (a[i]!=b[i]&&!vis[i])Best=dep[Best]<dep[i]?i:Best;
	if (Best){
		reverse(lzh.begin(),lzh.end());
		for(ll i=Best;vis[i]=1,lzh.push_back(i),a[fa[i]]!=b[fa[i]];i=fa[i]);
	}
	else	Best=fa[lzh.back()];
	For(i,1,n)if (a[i]!=b[i]&&!vis[i])return 0;
	Rt=lca(best,Best);
	if (lzh.size()!=dep[best]+dep[Best]-2*dep[Rt])return 0;
	return 1;
}
int main(){
	n=read();
	For(i,1,n)a[i]=read(),id1=a[i]?id1:i;
	For(i,1,n)b[i]=read(),id2=b[i]?id2:i;
	rep(i,1,n){
		ll a=read(),b=read();
		g[a].push_back(b);
		g[b].push_back(a);
	}dep[0]=-1;dfs(id2);
	for(ll i=id1;i!=id2;i=fa[i])swap(a[i],a[fa[i]]);
	ans=dep[id1];
	if (!fafa())return puts("-1"),0;
	if (!lzh.size())return printf("0 %lld\n",ans),0;
	zyy=0,sum=lzh.size();
	rep(i,0,sum)if (b[lzh[i]]==a[lzh[0]])zyy=i;
	rep(i,1,sum)if (b[lzh[(i+zyy)%sum]]!=a[lzh[i]])return puts("-1"),0;
	memset(vis,0,sizeof vis);
	for(ll i=id1;i;i=fa[i])vis[i]=1;
	if (vis[lzh[0]]||vis[lzh.back()]){
		rep(i,0,sum)if (!vis[lzh[i]]){cqz=i;break;}
		ans+=-cqz+min(cqz+zyy*(sum+1),abs((sum-zyy)*(sum+1)-cqz));
	}else	ans+=min(zyy,sum-zyy)*(sum+1);
	for(;!vis[Rt];Rt=fa[Rt])ans+=2;
	if (best>Best)swap(best,Best);
	printf("%lld %lld %lld\n",best,Best,ans);
}