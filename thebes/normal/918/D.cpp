#include <bits/stdc++.h>
using namespace std;

const int MN = 101;
int dp[MN][MN][30], n, m, i, j, x, y, w;
vector<tuple<int,int>> adj[MN];

bool cmp(int p1, int p2, int last){
	if(dp[p1][p2][last]!=-1) return dp[p1][p2][last];
	bool flag = false;
	for(auto v : adj[p1]){
		if(get<1>(v)<last) continue;
		flag=max(flag,!cmp(p2,get<0>(v),get<1>(v)));
	}
	dp[p1][p2][last]=flag;
	return flag;
}

int main(){
	memset(dp, -1, sizeof(dp));
	for(scanf("%d%d",&n,&m);i<m;i++){
		scanf("%d%d",&x,&y); getchar();
		w = getchar()-'a';
		adj[x].push_back({y,w});
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			bool flag = false;
			for(auto v : adj[i])
				flag=max(flag,!cmp(j,get<0>(v),get<1>(v)));
			printf("%c",(flag)?'A':'B');
		}
		printf("\n");
	}
	return 0;
}