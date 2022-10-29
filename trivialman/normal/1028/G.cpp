#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL N = 1e4;
LL n,x,now,query[N+5],dp[N+5][7];

LL dfs(LL x, int d){
	if(!d) return 0;
	if(x>N) return dfs(N,d);
	if(dp[x][d]) return dp[x][d];
	LL res = x;
	rep(j,0,x) res += dfs(res,d-1) + 1;
	return dp[x][d] = res-x-1;
};

int main() {
	for(int i=5;i;--i){
		n = min(now+1, N);
		rep(j,0,n){
			query[j] = now++;
			now += dfs(now, i-1);
		}
		printf("%d",n);
		rep(j,1,n) printf(" %lld",query[j]);
		cout<<endl<<flush;
		cin>>x;
		if(x<0) return 0;
		now = query[x];
	}
}