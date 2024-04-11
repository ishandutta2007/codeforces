//CF 859C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int a[55],dp[55][2][2];
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	memset(dp,0,sizeof(dp));
	for(i=n;i>=1;i=i-1){
		dp[i][0][0]=max(dp[i+1][0][0],dp[i+1][1][0]+a[i]);
		dp[i][0][1]=min(dp[i+1][1][1],dp[i+1][0][1]+a[i]);
		dp[i][1][0]=min(dp[i+1][0][0],dp[i+1][1][0]+a[i]);
		dp[i][1][1]=max(dp[i+1][1][1],dp[i+1][0][1]+a[i]);
	}
	cout<<dp[1][0][1]<<' '<<dp[1][0][0]<<endl;
	return 0;
}