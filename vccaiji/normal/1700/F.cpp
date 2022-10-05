#include<bits/stdc++.h>
using namespace std;
int a[2][1100000],b[2][1100000];
long long dp[2][1100000];
int main(){
	int n;
	cin>>n;
	int s=0;
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),s+=a[i][j];
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)scanf("%d",&b[i][j]),s-=b[i][j];
	if(s!=0){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)a[i][j]-=b[i][j];
	for(int i=0;i<2;i++)for(int j=1;j<n;j++)a[i][j+1]+=a[i][j];
	for(int j=1;j<=n;j++)a[1][j]=-a[1][j];
	for(int i=1;i<=n;i++)for(int j=0;j<2;j++){
		dp[j][i]=max(dp[0][i-1]+abs(a[1][i-1]-a[j][i]),dp[1][i-1]+abs(a[0][i-1]-a[j][i]));
	}
	cout<<max(dp[0][n],dp[1][n]);
	return 0;
}