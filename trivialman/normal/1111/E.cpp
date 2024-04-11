#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
const int P = 1e9+7;
const int N = 1e5+5;

int n,q,x,y,k,m,r,T=0;
int dp[305];
vector<int> g[N], oc[N]; 
array<int, 2> a[N];

void dfs(int x,int fa){
	oc[x].PB(++T);
	for(auto u:g[x])if(u!=fa){
		dfs(u,x);
		oc[x].PB(++T);
	}
}

int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		g[x].PB(y), g[y].PB(x);
	}
	dfs(1,0);
	oc[1].pop_back(), --T;
	rep(i,1,n)
		for(int j=0;oc[i][j]<=T;++j)
			oc[i].PB(oc[i][j]+T);
	while(q--){
		scanf("%d%d%d",&k,&m,&r);
		int rt0 = oc[r][0];
		rep(i,1,k){
			scanf("%d",&x);
			a[i] = {*lower_bound(oc[x].begin(), oc[x].end(), rt0), *--upper_bound(oc[x].begin(), oc[x].end(), rt0+T)};
		}
		sort(a+1,a+k+1);
		priority_queue<int, vector<int>, greater<int>> heap;
		memset(dp,0,sizeof dp);
		dp[0] = 1;
		int ans = 0;
		rep(i,1,k){
			while(!heap.empty() && heap.top()<a[i][0]) heap.pop();
			int sz = heap.size();
			rrep(j,min(m,i),1)
				dp[j] = (1ll * dp[j] * max(j-sz, 0) + dp[j-1]) % P;
			dp[0] = 0;
			heap.push(a[i][1]);
		}
		rep(i,1,m) ans = (ans + dp[i]) % P;
		printf("%d\n", ans);
	}
	return 0;
}