//CF 797B
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
int a[111111],dp[111111][2];
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&a[i]);
		dp[i][0]=-1<<30;
		dp[i][1]=-1<<30;
	}
	dp[0][0]=0;
	dp[0][1]=-1<<30;
	for(i=1;i<=n;i=i+1)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][(100000+a[i])%2]+a[i]);
		dp[i][1]=max(dp[i-1][1],dp[i-1][(100001+a[i])%2]+a[i]);
	}
	cout<<dp[n][1]<<endl;
	return 0;
}