#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = (l);x<=(u);x++)
#define RREP(x,l,u) for(ll x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 300010;
const int mod = 1e9+7;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m,s;

int tp[maxn],U[maxn],V[maxn];

vector<PII> G[maxn];

int vi[maxn],Ans[maxn],ans;

void dfs1(int u){
	if(vi[u])return;
	vi[u]=1;ans++;
	for(auto v:G[u]){
		if(tp[v.se]==1)dfs1(v.fi);
		else if(!Ans[v.se]){
			Ans[v.se]=V[v.se]==v.fi?1:2;
			dfs1(v.fi);
		}
	}
}

void dfs2(int u){
	if(vi[u])return;
	vi[u]=1;ans++;
	for(auto v:G[u]){
		if(tp[v.se]==1)dfs2(v.fi);
		else if(!Ans[v.se]){
			Ans[v.se]=V[v.se]==v.fi?2:1;
		}
	}
}

void Work(){
	REP(i,1,n)vi[i]=0;
	REP(i,1,m)Ans[i]=0;
	dfs1(s);
	printf("%d\n",ans);
	REP(i,1,m)if(tp[i]==2)if(Ans[i]==1)printf("+");else printf("-");
	puts("");
	ans=0;
	REP(i,1,n)vi[i]=0;
	REP(i,1,m)Ans[i]=0;
	dfs2(s);
	printf("%d\n",ans);
	REP(i,1,m)if(tp[i]==2)if(Ans[i]==1)printf("+");else printf("-");
}

void Init(){
	read(n,m,s);
	REP(i,1,m){
		int t,u,v;
		read(t,u,v);
		tp[i]=t;U[i]=u;V[i]=v;
		G[u].PB(MP(v,i));
		if(t==2)G[v].PB(MP(u,i));
	}
}

int main(){
	Init();
	Work();
	return 0;
}