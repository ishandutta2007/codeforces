#include <iostream>
#define int long long
#define mod 1000000007
using namespace std;
int dp[2005][2005][2],qzh1[2005][2005],qzh2[2005][2005],qzh[2005][2005][2];
signed main() {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char t;
			cin >> t;
			qzh1[i][j]=qzh1[i][j-1]+(t=='R');
			qzh2[i][j]=qzh2[i-1][j]+(t=='R');
		}
	}
	dp[1][1][0]=dp[1][1][1]=1;
	if(n==m&&m==1) dp[1][1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			qzh[i][j][1]=(qzh[i][j-1][1]+dp[i][j][1])%mod;
			qzh[i][j][0]=(qzh[i-1][j][0]+dp[i][j][0])%mod;
			if(i==j&&j==1)
				continue;
			int l=1,r=j-1,now=j;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(qzh1[i][m]-qzh1[i][mid]<m-j+1)
					now=mid,r=mid-1;
				else
					l=mid+1;
			}
			dp[i][j][0]+=qzh[i][j-1][1]-qzh[i][now-1][1];
			l=1,r=i-1,now=i;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(qzh2[n][j]-qzh2[mid][j]<n-i+1)
					now=mid,r=mid-1;
				else
					l=mid+1;
			}
			dp[i][j][1]+=qzh[i-1][j][0]-qzh[now-1][j][0];
			qzh[i][j][1]=(qzh[i][j-1][1]+dp[i][j][1])%mod;
			qzh[i][j][0]=(qzh[i-1][j][0]+dp[i][j][0])%mod;
			dp[i][j][1]%=mod,dp[i][j][0]%=mod;
		}
	}
	cout << (dp[n][m][0]+dp[n][m][1]+mod+mod)%mod << endl;
	return 0;
}