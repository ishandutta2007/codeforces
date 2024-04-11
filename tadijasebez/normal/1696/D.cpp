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


const int N=300050;
const int inf=1e9;
int a[N],dp[N];

/*struct BIT{
	vector<int> sum;
	int n;
	BIT(){}
	void init(int _n){
		n=_n;
		sum.clear();
		sum.assign(n+1,inf);
	}
	int Get(int i){
		int ans=inf;
		for(i++;i<=n;i+=i&-i)
			ans=min(ans,sum[i]);
		return ans;
	}
	void Set(int i,int x){
		for(i++;i>0;i-=i&-i)
			sum[i]=min(sum[i],x);
	}
}LB,HB;*/

void Run(){
	int n=ri();
	ra(a,n);
	vector<int> lo,hi;
	//LB.init(n);
	//HB.init(n);
	dp[1]=0;
	for(int i=1;i<=n;i++){
		if(i!=1)dp[i]=inf;

		while(lo.size()&&a[lo.back()]>a[i]){
			lo.pop_back();
		}
		while(hi.size()&&a[hi.back()]<a[i]){
			hi.pop_back();
		}

		int pm=0;
		if(lo.size())
			pm=lo.back();
		if(pm!=i-1){
			//printf("pm %i ",pm);
			int j=lower_bound(hi.begin(),hi.end(),pm)-hi.begin();
			//printf("hi: %i %i ",j,hi.size());
			ckmn(dp[i],dp[hi[j]]+1);
		}

		pm=0;
		if(hi.size())
			pm=hi.back();
		if(pm!=i-1){
			//printf("pm2 %i ",pm);
			int j=lower_bound(lo.begin(),lo.end(),pm)-lo.begin();
			//printf("lo: %i\n",lo[j]);
			ckmn(dp[i],dp[lo[j]]+1);
		}

		lo.push_back(i);
		hi.push_back(i);
	}
	printf("%i\n",dp[n]);
}

int main(){
	int t=ri();
	while(t--)Run();
	return 0;
}