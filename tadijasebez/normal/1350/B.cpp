#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
int main(){
	for(int t=ri();t--;){
		int n=ri();
		vector<int> s(n+1),dp(n+1,1);
		for(int i=1;i<=n;i++)rd(s[i]);
		int ans=1;
		for(int i=1;i<=n;ckmx(ans,dp[i]),i++)for(int j=i*2;j<=n;j+=i)if(s[i]<s[j])ckmx(dp[j],dp[i]+1);
		printf("%i\n",ans);
	}
	return 0;
}