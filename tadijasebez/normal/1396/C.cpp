#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
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
const int N=1000050;
const ll inf=7e18;
int a[N];
ll dp[N],ans,need[N];
int main(){
	int n,r1,r2,r3,d;
	rd(n,r1,r2,r3,d);
	for(int i=1;i<=n;i++)rd(a[i]);
	for(int i=1;i<=n;i++)need[i]=min((ll)r1*(a[i]+1),(ll)r2)+r1+(ll)3*d,need[i]+=need[i-1];
	dp[0]=0;
	ll best=inf;
	for(int i=1;i<=n;i++){
		ll dest=min((ll)r1*a[i]+r3,min((ll)r1*(a[i]+1),(ll)r2)+(ll)2*d+r1);
		dp[i]=dp[i-1]+(i==1?0:d)+dest;
		dp[i]=min(dp[i],best+need[i]-(ll)3*d);
		dp[i]=min(dp[i],best+need[i-1]+dest);
		best=min(best,dp[i-1]-need[i-1]+(i==1?0:d));
		//printf("%lld ",dp[i]);
	}
	//printf("\n");
	ans=dp[n];
	for(int i=1;i<=n;i++)need[i]=min((ll)r1*(a[i]+1),(ll)r2)+r1+(ll)2*d,need[i]+=need[i-1];
	ll dest=min((ll)r1*a[n]+r3,min((ll)r1*(a[n]+1),(ll)r2)+(ll)2*d+r1);
	for(int i=0;i<n-1;i++){
		ans=min(ans,need[n-1]-need[i]+dp[i]+(i==0?0:d)+dest);
	}
	printf("%lld\n",ans);
	return 0;
}