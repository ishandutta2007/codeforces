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
char s[2][N];
int dp[N][2][2];
const int inf=1e9+7;
int main(){
	int n=ri();
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			dp[0][i][j]=-inf;
		}
	}
	if(s[1][1]=='1'){
		dp[1][0][0]=0;
		dp[1][0][1]=-inf;
		dp[1][1][1]=1;
		dp[1][1][0]=-inf;
	}else{
		dp[1][0][0]=0;
		dp[1][0][1]=-inf;
		dp[1][1][1]=-inf;
		dp[1][1][0]=-inf;
	}
	for(int i=2;i<=n;i++){
		for(int last=0;last<2;last++){
			for(int swch=0;swch<2;swch++){
				dp[i][last][swch]=dp[i-1][last][swch];
				if(s[last][i]=='1'){
					if(swch){
						ckmx(dp[i][last][swch],dp[i-1][last^1][0]+1);
						ckmx(dp[i][last][swch],dp[i-2][last^1][1]+1);
					}else{
						ckmx(dp[i][last][swch],dp[i-1][last][0]+1);
						ckmx(dp[i][last][swch],dp[i-1][last][1]+1);
					}
					if(s[last^1][i]=='1'){
						if(swch){
							ckmx(dp[i][last][swch],dp[i-1][last^1][0]+2);
							ckmx(dp[i][last][swch],dp[i-2][last^1][1]+2);
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ckmx(ans,dp[n][i][j]);
		}
	}
	printf("%i\n",ans);
	return 0;
}