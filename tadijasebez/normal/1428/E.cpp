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

const int N=100050;
//const ll inf=2e18;
//map<int,map<int,ll>> dp[N];
ll calc(int x,int y){
	ll now=x/y,ost=x%y;
	return now*now*(y-ost)+(now+1)*(now+1)*ost;
}
/*ll DP(int i,int k,int las){
	if(i==0)return k==0?0:inf;
	if((ll)i*las<k||k<i)return inf;
	if(dp[i].count(k)&&dp[i][k].count(las))return dp[i][k][las];
	dp[i][k][las]=inf;
	for(int j=1;j<=min(k,las);j++){
		ckmn(dp[i][k][las],DP(i-1,k-j,j)+calc(a[i],j));
	}
	return dp[i][k][las];
}
mt19937 rng(time(0));*/
int sz[N],a[N];
ll ans;
int main(){
	int n,k;
	rd(n,k);
	ra(a,n);
	priority_queue<pair<ll,int>> pq;
	for(int i=1;i<=n;i++){
		sz[i]=1;
		if(a[i]>sz[i])pq.push({calc(a[i],sz[i])-calc(a[i],sz[i]+1),i});
		//pq.push({a[i],i}),sz[i]=1;
	}
	for(int j=n+1;j<=k;j++){
		int i=pq.top().second;
		pq.pop();
		sz[i]++;
		if(a[i]>sz[i])pq.push({calc(a[i],sz[i])-calc(a[i],sz[i]+1),i});
	}
	for(int i=1;i<=n;i++){
		ans+=calc(a[i],sz[i]);
	}
	printf("%lld\n",ans);
	/*k=100000;
	n=60000;
	for(int i=1;i<=n;i++)a[i]=rng()%1000000+1;
	sort(a+1,a+1+n);
	printf("%i\n",DP(n,k,k));*/
	return 0;
}