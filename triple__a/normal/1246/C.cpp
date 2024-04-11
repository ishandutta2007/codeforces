#include<bits/stdc++.h>
using namespace std;

const int maxn=2007;
const int mod=1e9+7;
int n,m;
int dp[maxn][maxn][2],block[maxn][maxn][2],sum[maxn][maxn][2],vec[maxn][2];
char s[maxn][maxn];

int calc(int u,int v,int w){
	if (w==0){
		for (;vec[v][1]<u;++vec[v][1]){
			if (block[vec[v][1]+1][v][1]<=n-u) break;
		}
		return (sum[u-1][v][1]-sum[vec[v][1]-1][v][1]+mod)%mod;
	}
	else{
		for (;vec[u][0]<v;++vec[u][0]){
			if (block[u][vec[u][0]+1][0]<=m-v) break;
		}
		return (sum[u][v-1][0]-sum[u][vec[u][0]-1][0]+mod)%mod;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if (n==1&&m==1){
		cout<<1<<endl;
		return 0;
	}
	for (int i=1;i<=max(n,m);++i){
		vec[i][0]=vec[i][1]=1;
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			cin>>s[i][j];
			if (s[i][j]=='R') block[i+1][j+1][0]=block[i+1][j+1][1]=1;
		}
	}
	for (int i=0;i<=n;++i){
		for (int j=m;j>0;--j){
			block[i][j-1][0]+=block[i][j][0];
		}
	}
	for (int j=0;j<=m;++j){
		for (int i=n;i>0;--i){
			block[i-1][j][1]+=block[i][j][1];
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (i==0&&j==0) {
				dp[0][0][0]=dp[0][0][1]=1;
				sum[1][1][0]=sum[1][1][1]=1;
				continue;
			}
			dp[i][j][0]=calc(i+1,j+1,0);
			dp[i][j][1]=calc(i+1,j+1,1);
			sum[i+1][j+1][0]=(sum[i+1][j][0]+dp[i][j][0])%mod;
			sum[i+1][j+1][1]=(sum[i][j+1][1]+dp[i][j][1])%mod;
		}
	}
	printf("%d\n",(dp[n-1][m-1][0]+dp[n-1][m-1][1])%mod);
	return 0;
}