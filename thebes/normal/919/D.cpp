#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
int vis[MN], dp[MN][27], N, M, i, x, y, st[MN], ans, val[MN];
vector<int> adj[MN]; char c;

bool cycle(int n){
	vis[n] = st[n] = 1;
	for(auto v : adj[n]){
		if(st[v]) return 1;
		if(!vis[v]){if(cycle(v)) return 1;}
	}
	st[n] = 0; return 0;
}

void solve(int n){
	if(!vis[n]) vis[n]=1;
	else return;
	for(auto v : adj[n]){
		solve(v);
		for(int i=0;i<26;i++)
			dp[n][i]=max(dp[n][i],dp[v][i]);
	}
	dp[n][val[n]]++;
}

int main(){
	scanf("%d%d",&N,&M);
	string s; cin >> s;
	for(i=0;i<s.size();i++) val[i+1]=s[i]-'a';
	for(i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
	}
	bool flag = 0;
	for(i=1;i<=N;i++){
		if(!vis[i]) flag=max(flag,cycle(i));
	}
	if(flag) printf("-1\n");
	else{
		memset(vis, 0, sizeof(vis));
		for(i=1;i<=N;i++){
			solve(i);
			for(int j=0;j<26;j++)
				ans=max(ans,dp[i][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}