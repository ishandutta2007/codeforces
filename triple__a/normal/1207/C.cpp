#include<bits/stdc++.h>
#define int long long
using namespace std;


const int INF=1e15;
const int maxn=200007;

int u[maxn],dp[maxn][3];
int t,n,a,b;
#undef int
int main(){
	int t;
	cin>>t;
	while(t--){
	cin>>n>>a>>b;
	for (int i=1;i<=n;++i){
		char c;
		cin>>c;
		u[i]=c-'0';
	}
	u[n+1]=0;
	dp[0][0]=b;
	dp[0][1]=INF;
	for (int i=0;i<n;++i){
		if (u[i+2]==1||u[i+1]==1){
			dp[i+1][1]=min(dp[i][0]+2*a+2*b,dp[i][1]+a+2*b);
			dp[i+1][0]=INF;
		}
		else{
			dp[i+1][1]=min(dp[i][0]+2*a+2*b,dp[i][1]+a+2*b);
			dp[i+1][0]=min(dp[i][0]+a+b,dp[i][1]+2*a+b);
		}
	}
	cout<<dp[n][0]<<endl;
	}
	return 0;
}