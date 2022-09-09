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

int main(){
	for(int t=ri();t--;){
		int n=ri();
		auto a=rv<int>(n);
		auto b=rv<int>(n);
		vector<bool> dp(n*100+1,false);
		dp[0]=true;
		int sum=0;
		for(int i=0;i<n;i++){
			vector<bool> nxt(n*100+1,false);
			for(int j=0;j<nxt.size();j++){
				if(a[i]<=j)nxt[j]=nxt[j]|dp[j-a[i]];
				if(b[i]<=j)nxt[j]=nxt[j]|dp[j-b[i]];
			}
			dp=nxt;
			sum+=a[i]+b[i];
		}
		int best=0,mn=1e9;
		for(int i=0;i<dp.size();i++){
			if(dp[i]){
				int j=sum-i;
				if(abs(i-j)<mn){
					best=i;
					mn=abs(i-j);
				}
			}
		}
		ll ans=0;
		for(int i=0;i<n;i++){
			ans+=(ll)(n-2)*a[i]*a[i];
			ans+=(ll)(n-2)*b[i]*b[i];
		}
		ans+=(ll)best*best;
		ans+=(ll)(sum-best)*(sum-best);
		printf("%lld\n",ans);
	}
	return 0;
}