#include <iostream>
using namespace std;
char a[4][1000005];
int dp[1000005][10];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	if(n>=4&&m>=4)
	{
		puts("-1");
		return 0;
	}
	if(n<=3)
	{
		for(int i=0;i<n;i++)
			for(int j=1;j<=m;j++)
				cin >> a[i][j];
	}
	else
	{
		for(int j=0;j<m;j++)
			for(int i=1;i<=n;i++)
				cin >> a[j][i];
		swap(n,m);
	}
	for(int j=0;j<(1<<n);j++)
	{
		for(int k=0;k<n;k++)
		{
			if((!!(j&(1<<k)))!=a[k][1]-'0')
				++dp[1][j];
		}
	}
	int ans=1e9;
	for(int i=2;i<=m;i++)
		for(int j=0;j<=7;j++) dp[i][j]=1e9;
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			for(int k=0;k<(1<<n);k++)
			{
				int flag=0;
				for(int l=1;l<n;l++)
				{
					if((!!(k&(1<<l))+!!(k&(1<<l-1))+!!(j&(1<<l))+!!(j&(1<<l-1)))%2==0)
					{
					//	cout << k << " " << j << "\n";
						flag=1;
					}
				}
				if(flag) continue;
				int w=0;
				for(int l=0;l<n;l++)
				{
					if((!!(k&(1<<l)))!=a[l][i]-'0')
						++w;
				}
				dp[i][k]=min(dp[i][k],dp[i-1][j]+w);
			}
		}
	}
	for(int i=0;i<(1<<n);i++)
		ans=min(ans,dp[m][i]);
	cout << ans;
	return 0;
}