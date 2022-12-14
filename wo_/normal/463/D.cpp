#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int p[5][1010];

vector<int> G[1010];
int dp[1010];
int ord[1010][1010];

int dfs(int v){
	if(dp[v]!=-1) return dp[v];
	int res=0;
	for(int i=0;i<G[v].size();i++){
		res=max(res,dfs(G[v][i]));
	}
	dp[v]=res+1;
	return dp[v];
}

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++) for(int j=0;j<N;j++) scanf("%d",&p[i][j]);
	for(int i=0;i<K;i++){
		for(int j=0;j<N;j++) for(int k=j+1;k<N;k++){
			ord[p[i][j]][p[i][k]]++;
		}
	}
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
		if(ord[i][j]==K) G[i].push_back(j);
	}
	for(int i=1;i<=N;i++) dp[i]=-1;
	int ans=-1;
	for(int i=1;i<=N;i++) ans=max(ans,dfs(i));
	printf("%d\n",ans);
	return 0;
}