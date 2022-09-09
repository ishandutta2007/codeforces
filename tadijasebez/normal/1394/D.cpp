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
const int N=200050;
vector<int> E[N];
int h[N],t[N];
ll dp[N][2];
void DFS(int u,int p){
	int in=0,out=0;
	vector<ll> tmp;
	ll ans=0;
	for(int v:E[u])if(v!=p){
		DFS(v,u);
		if(h[u]>h[v])out++,ans+=dp[v][0];
		else if(h[u]<h[v])in++,ans+=dp[v][1];
		else ans+=dp[v][0],out++,tmp.pb(dp[v][1]-dp[v][0]);
	}
	if(p){
		if(h[p]>h[u])in++;
		if(h[p]<h[u])out++;
	}
	sort(tmp.begin(),tmp.end());
	if(p&&h[u]==h[p])in++;
	dp[u][0]=ans+(ll)max(in,out)*t[u];
	ll sum=0;
	for(int i=0;i<tmp.size();i++){
		sum+=tmp[i];
		dp[u][0]=min(dp[u][0],ans+sum+(ll)max(in+i+1,out-i-1)*t[u]);
	}
	if(p&&h[u]==h[p])in--;
	if(p&&h[u]==h[p])out++;
	dp[u][1]=ans+(ll)max(in,out)*t[u];
	sum=0;
	for(int i=0;i<tmp.size();i++){
		sum+=tmp[i];
		dp[u][1]=min(dp[u][1],ans+sum+(ll)max(in+i+1,out-i-1)*t[u]);
	}
	if(p&&h[u]==h[p])out--;
}
int main(){
	int n=ri();
	for(int i=1;i<=n;i++)rd(t[i]);
	for(int i=1;i<=n;i++)rd(h[i]);
	for(int i=1,u,v;i<n;i++)rd(u,v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	printf("%lld\n",dp[1][0]);
	return 0;
}