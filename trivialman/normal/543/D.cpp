#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
#define ar2 array<int, 2>
typedef long long LL;
const int P = 1e9+7;
const int N = 2e5+5;
const double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> g[N];
int n, x;
LL ans[N], dp[N];

LL pw(LL x,int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P) if(n&1) res=res*x%P;
	return res;
}

void dfs(int x){
	dp[x] = 1;
	for(auto u:g[x]){
		dfs(u);
		dp[x] = dp[x] * (dp[u]+1) % P;
	}
}

void dfs2(int x, LL upnum){
	ans[x] = dp[x] * upnum % P;
	int num0 = 0;
	LL tmp = 1;
	for(auto u:g[x]) num0 += (dp[u]+1==P);
	if(num0==1){
		for(auto u:g[x]) if(dp[u]+1!=P)
			tmp = tmp * (dp[u]+1) % P;
	}
	for(auto u:g[x]){
		LL mul = dp[x] * pw(dp[u]+1, P-2) % P;
		if(num0==1 && dp[u]+1==P) mul = tmp;
		dfs2(u, (upnum * mul + 1) % P);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,2,n){
		scanf("%d",&x);
		g[x].PB(i);
	}
	dfs(1);
	dfs2(1, 1);
	rep(i,1,n) printf("%lld ",ans[i]);
	return 0;
}