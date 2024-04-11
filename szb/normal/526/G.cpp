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
	void writeln(ll x){write(x),puts("");}
}using namespace SHENZHEBEI;
const ll N=500100;
ll A,B;
vector<ll>g[N],w[N];
ll Dist[N],n,Q,Ans;
ll *q[N];
bool cmp(ll *a,ll *b){return *a>*b;}
struct dt{
	ll vv[N],dis[N],Max_d[N],vis[N],sumans[N],d[N],ans[N],fafa[N],Rt,yezi;
	int val[N][20],fa[N][20];
	void Dfs(ll x){
		Max_d[x]=Dist[x];
		rep(i,0,g[x].size())if (g[x][i]!=fa[x][0]){
			if (fa[g[x][i]][0]==x)continue;
			fafa[g[x][i]]=w[x][i];
			fa[g[x][i]][0]=x;
			Dfs(g[x][i]);
			Max_d[x]=max(Max_d[x],Max_d[g[x][i]]);
		}
	}
	void Build(ll x){
		Dfs(Rt=x);
		memcpy(d,Dist,sizeof Dist);
		For(i,1,n)if (g[i].size()==1&&i!=Rt)q[++yezi]=Dist+i;
		sort(q+1,q+yezi+1,cmp);
		For(i,1,yezi){
			ll x=q[i]-Dist,y=x;
			for(;!vis[x];x=fa[x][0])
				vis[x]=1,dis[y]+=fafa[x];
			q[i]=dis+y;
		}
		sort(q+1,q+yezi+1,cmp);
		For(i,1,yezi){
			sumans[i]=sumans[i-1]+(vv[i]=*q[i]);
			ll x=q[i]-dis,y=x;
			for(;vis[x]!=2;x=fa[x][0])
				vis[x]=2,val[x][0]=i;
		}
		For(i,1,18)For(x,1,n)
			fa[x][i]=fa[fa[x][i-1]][i-1],
			val[x][i]=min(val[fa[x][i-1]][i-1],val[x][i-1]);
	}
	ll Query(ll x,ll y){
		y=y*2-1;
		if (y>=yezi)return sumans[yezi];
		ll ans=sumans[y];
		if (val[x][0]>y){
			ll tmp=x;
			FOr(i,18,0)if (val[tmp][i]>y)tmp=fa[tmp][i];
			ans+=Max_d[x]-d[tmp];
			ans-=min(vv[y],Max_d[tmp]-d[tmp]);
		}
		return ans;
	}
}As,Bs;
void dfs(ll x,ll fa,ll dist){
	Dist[x]=dist;
	rep(i,0,g[x].size())if(g[x][i]!=fa)
		dfs(g[x][i],x,dist+w[x][i]);
}
int main(){
	n=read(),Q=read();
	rep(i,1,n){
		ll x=read(),y=read(),W=read();
		g[x].push_back(y);	g[y].push_back(x);
		w[x].push_back(W);	w[y].push_back(W);
	}dfs(1,0,0);
	A=max_element(Dist+1,Dist+n+1)-Dist;
	dfs(A,0,0);
	As.Build(A);
	B=max_element(Dist+1,Dist+n+1)-Dist;
	dfs(B,0,0);
	Bs.Build(B);
//	writeln(As.Query(4,1));
//	writeln(Bs.Query(4,1));return 0;
	for(;Q--;){
		ll	x=(read()+Ans+n-1)%n+1,y=(read()+Ans+n-1)%n+1;
		writeln(Ans=max(As.Query(x,y),Bs.Query(x,y)));
	}
}