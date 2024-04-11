#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
char s[1005][1005];
int dp[1005][2],cnt[1005],sum[1005];
int main(){
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(s[j][i]=='#')
				cnt[i]++;
	}
	for(int i=1;i<=m;i++)	sum[i]=sum[i-1]+cnt[i];
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=m;i++){
		for(int j=x;j<=y;j++){
			if(i-j+1>0){
				dp[i][0]=min(dp[i][0],dp[i-j][1]+n*j-(sum[i]-sum[i-j]));
				dp[i][1]=min(dp[i][1],dp[i-j][0]+(sum[i]-sum[i-j]));
			}
		}
//		cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<min(dp[m][0],dp[m][1])<<endl;
}