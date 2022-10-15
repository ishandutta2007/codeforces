#include<bits/stdc++.h>
using namespace std;

const int maxn=107;
int n,m;
int u[maxn],w[maxn];
struct edge{
	int a,b;
	friend bool operator< (edge u,edge v){
		return u.a+u.b>v.a+v.b;
	}
}edge[maxn];

int solve_up(){
	int cnt=0;
	bool vis[maxn];
	memset(vis,0,sizeof(vis));
	while (1){
		int j=-1;
		for (int i=1;i<=n;++i){
			if (!vis[i]&&w[i]>=0&&(j==-1||u[i]<u[j])){
				j=i;
			}
		}
		if (j==-1||m<u[j]) return cnt;
		vis[j]=1;
		m+=w[j]; 
		cnt++;
	}
}

int solve_down(){
	int cnt=0;
	for (int i=1;i<=n;++i){
		if (w[i]<0){
			edge[++cnt].a=u[i];
			edge[cnt].b=w[i];
		}
	}
	sort(edge+1,edge+cnt+1);
	int dp[maxn][maxn];
	dp[0][0]=m;
	for (int i=1;i<=cnt;++i){
		dp[0][i]=-1;
	}
	for (int i=1;i<=cnt;++i){
		dp[i][0]=m;
		for (int j=1;j<=cnt;++j){
			if (dp[i-1][j-1]>=edge[i].a){
				dp[i][j]=max(dp[i-1][j-1]+edge[i].b,dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	for (int j=cnt;j>0;--j){
		if (dp[cnt][j]>=0) return j;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>u[i]>>w[i];
	}
	cout<<solve_up()+solve_down();
	return 0;
}