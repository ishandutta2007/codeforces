#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, M, vis[MN], sz, i, cnt[MN], dp[MN], a[MN];
vector<int> adj[MN];
bitset<MN> ok;

void dfs(int n){
	vis[n] = 1; sz++;
	for(auto v : adj[n])
		if(!vis[v]) dfs(v);
}

bool check(int n){
	while(n){
		if(n%10!=4&&n%10!=7) return 0;
		n /= 10;
	}
	return 1;
}

void upd(int v, int e){
	for(int i=N;i>=v;i--)
		dp[i]=min(dp[i],dp[i-v]+e);
}

int main(){
	for(scanf("%d%d",&N,&M);i<M;i++){
		int x, y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=N;i++) dp[i]=1<<30;
	for(i=1;i<=N;i++){
		if(check(i)) ok[i]=1;
		if(vis[i]) continue;
		sz=0; dfs(i); cnt[sz]++;
	}
	for(i=1;i<=N;i++){
		if(!cnt[i]) continue;
		for(int sz=1;sz<=cnt[i];sz*=2)
			upd(sz*i,sz), cnt[i]-=sz;
		upd(cnt[i]*i,cnt[i]);
	}
	int ans = 1<<30;
	for(i=1;i<=N;i++){
		if(ok[i]) ans=min(ans,dp[i]); 
	}
	printf("%d\n",(ans==1<<30)?-1:ans-1);
	return 0;
}