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

const int N=105;
const int M=N*N;
const int inf=1e9+7;
int dp[N][M*2],b[N],a[N];
int main(){
	int n=ri();
	ra(a,b,n);
	for(int i=0;i<=n;i++)for(int bal=0;bal<M*2;bal++)dp[i][bal]=-inf;
	int C=0;
	for(int i=1;i<=n;i++)C+=b[i];
	dp[0][M]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			for(int bal=0;bal<M*2;++bal)if(dp[j][bal]!=-inf){
				//if(bal-a[i]+b[i]>=0&&bal-a[i]+b[i]<2*M&&dp[j-1][bal-a[i]+b[i]]!=-inf)
				//	ckmx(dp[j][bal],dp[j-1][bal-a[i]+b[i]]+a[i]);
				ckmx(dp[j+1][bal+a[i]-b[i]],dp[j][bal]+a[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int bal=0;bal<2*M;bal++)if(dp[i][bal]!=-inf){
			int A=2*dp[i][bal];
			int B=dp[i][bal]-(bal-M)+C;
			ckmx(ans,min(A,B));
			//printf("%i: %i %i\n",bal-M,A,B);
		}
		printf("%.2f ",(ldb)ans/2);
	}
	return 0;
}