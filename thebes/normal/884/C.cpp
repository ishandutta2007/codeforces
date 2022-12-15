#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
vector<int> vec, adj[MN];
int N, i, x, vis[MN]; long long ans;
bool cmp(int i,int j){return(i>j);}

int dfs(int n){
	vis[n] = 1; int ret=1;
	for(auto v : adj[n]){
		if(!vis[v]) ret += dfs(v);
	}
	return ret;
}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&x);
		adj[i].push_back(x);
	}
	for(i=1;i<=N;i++){
		if(!vis[i]) vec.push_back(dfs(i));
	}
	sort(vec.begin(), vec.end(), cmp);
	if(vec.size() >= 2){vec[0]+=vec[1]; vec[1]=0;}
	for(auto v : vec){
		ans += (1LL * v * v);
	}
	printf("%I64d\n",ans);
	return 0;
}