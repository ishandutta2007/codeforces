#include <iostream>
using namespace std;
int a[100],dp[88][2000][88],n,b[100],cnt;
int main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]) b[++cnt]=i;
	}
	b[cnt+1]=n+1;
	for(int k=0;k<=cnt+1;k++)
		for(int i=0;i<=n*n/4;i++)
			for(int j=(k==0);j<=n;j++) dp[k][i][j]=-1e9;
	for(int i=1;i<=cnt+1;i++)
		for(int j=0;j<=n*n/4;j++)
			for(int k=0;k<=n+1;k++)
				for(int l=k+1;l<=n+1&&dp[i-1][j][k]<1e8;l++)
					dp[i][j+max(b[i],l)-min(b[i],l)][l]=max(dp[i][j+max(b[i],l)-min(b[i],l)][l],dp[i-1][j][k]+(k-i+1)*(l-k-1));
	int lst=0;
	for(int i=0;i<=n*(n-1)/2;i++)
	{
		int mx=0;
		if(i<=n*n/4)
		{
			cout << dp[cnt+1][i][n+1] << " ";
			lst=dp[cnt+1][i][n+1];
		}
		else cout << lst << " ";
	}
    return 0;
}