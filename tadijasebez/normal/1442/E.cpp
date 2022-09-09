#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=200050;
vector<int> E[N];
int col[N],dp[N][2],diam;
void DFS(int u,int p){
	int best[2]={0,0};
	if(col[u]==1)best[0]=1;
	if(col[u]==2)best[1]=1;
	for(int v:E[u])if(v!=p){
		DFS(v,u);
		ckmx(diam,best[0]+dp[v][0]-1);
		ckmx(diam,best[1]+dp[v][1]-1);
		ckmx(diam,best[0]+dp[v][1]);
		ckmx(diam,best[1]+dp[v][0]);
		if(col[u]==0){
			ckmx(best[0],dp[v][0]),ckmx(best[1],dp[v][1]);
		}else if(col[u]==1){
			ckmx(best[0],max(dp[v][1]+1,dp[v][0]));
		}else if(col[u]==2){
			ckmx(best[1],max(dp[v][0]+1,dp[v][1]));
		}
	}
	ckmx(diam,max(best[0],best[1]));
	dp[u][0]=best[0];
	dp[u][1]=best[1];
}
int main(){
	for(int t=ri();t--;){
		int n=ri();
		ra(col,n);
		for(int i=1;i<=n;i++)E[i].clear();
		re(E,n-1);
		diam=0;
		DFS(1,0);
		int ans=diam/2+1;
		printf("%i\n",ans);
	}
	return 0;
}