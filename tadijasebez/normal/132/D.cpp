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

const int N=1000050;
const int inf=1e9;
char s[N];
int dp[N][2];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	reverse(s,s+n);
	s[n]='0';
	dp[0][0]=s[0]=='1'?1:0;
	dp[0][1]=s[0]=='1'?1:inf;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i][1]=inf;
		if(s[i]=='1'){
			ckmn(dp[i][1],dp[i-1][1]);
			ckmn(dp[i][1],dp[i-1][0]+1);//-2^i
			ckmn(dp[i][0],dp[i-1][0]+1);//+2^i
		}else{
			ckmn(dp[i][1],dp[i-1][1]+1);//-2^i
			ckmn(dp[i][0],dp[i-1][1]+1);//+2^i
			ckmn(dp[i][0],dp[i-1][0]);
		}
	}
	printf("%i\n",dp[n][0]);
	int o=0;
	for(int i=n;i>=1;i--){
		if(s[i]=='1'){
			if(o==1){
				if(dp[i-1][1]>dp[i-1][0]+1){
					printf("-2^%i\n",i);
					o=0;
				}
			}else{
				printf("+2^%i\n",i);
			}
		}else{
			if(o==1){
				printf("-2^%i\n",i);
			}else{
				if(dp[i-1][0]>dp[i-1][1]+1){
					printf("+2^%i\n",i);
					o=1;
				}
			}
		}
	}
	if(s[0]=='1'){
		if(o==0)printf("+2^0\n");
		else printf("-2^0\n");
	}
	return 0;
}