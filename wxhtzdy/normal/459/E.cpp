#include <bits/stdc++.h>
using namespace std;
const int N=300050;
const int M=100050;
vector<pair<int,int>> E[M];
int dp[N][2];
int main(){
	int n,m;scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%i%i%i",&u,&v,&w);
        E[w].push_back({u,v});
    }
    for(int i=1;i<M;i++){
		for(auto e:E[i])dp[e.second][1]=0;
        for(auto e:E[i])dp[e.second][1]=max(dp[e.second][1],dp[e.first][0]+1);
        for(auto e:E[i])dp[e.second][0]=max(dp[e.second][0],dp[e.second][1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dp[i][0]);
    printf("%i",ans);
    return 0;
}