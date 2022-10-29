#include <iostream>
#define inf 123456789
using namespace std;
int a[200005],dp[200005][5];
int main(int argc, char** argv) {
	int A,B,C;cin >> A >> B >> C;int n=A+B+C;
	for(int i=1;i<=A;i++){int t;cin >> t;a[t]=1;}
	for(int i=1;i<=B;i++){int t;cin >> t;a[t]=2;}
	for(int i=1;i<=C;i++){int t;cin >> t;a[t]=3;}
	for(int i=1;i<=n;i++) dp[i][1]=dp[i][2]=dp[i][3]=inf,
	dp[i][1]=min(dp[i][1],dp[i-1][1]+(a[i]!=1)),
	dp[i][2]=min(dp[i][2],dp[i-1][1]+(a[i]!=2)),
	dp[i][2]=min(dp[i][2],dp[i-1][2]+(a[i]!=2)),
	dp[i][3]=min(dp[i][3],dp[i-1][1]+(a[i]!=3)),
	dp[i][3]=min(dp[i][3],dp[i-1][2]+(a[i]!=3)),
	dp[i][3]=min(dp[i][3],dp[i-1][3]+(a[i]!=3));
	cout << min(dp[n][1],min(dp[n][2],dp[n][3]));
	return 0;
}