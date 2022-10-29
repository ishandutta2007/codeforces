#include <iostream>
using namespace std;
int dp[200005][2][2];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string a;
		cin >> a;
		a=' '+a;
		if(n==3)
		{
			if(a[1]==a[2]&&a[2]==a[3])
			{
				puts("1");
			}
			else puts("0");
			continue;
		}
		int ans=1e9;
		for(int x=0;x<=1;x++)
		{
			for(int y=0;y<=1;y++)
			{
				dp[2][0][0]=dp[2][0][1]=dp[2][1][0]=dp[2][1][1]=1e9;
				dp[2][x][y]=0;
				int w=0;
				if(x==0&&a[1]!='L') ++w;
				if(x==1&&a[1]!='R') ++w;
				if(y==0&&a[2]!='L') ++w;
				if(y==1&&a[2]!='R') ++w;
				for(int i=3;i<=n;i++)
				{
					dp[i][0][1]=min(dp[i-1][0][0],dp[i-1][1][0])+(a[i]!='R');
					dp[i][1][1]=min(dp[i-1][0][1],dp[i-1][0][1])+(a[i]!='R');
					dp[i][1][0]=min(dp[i-1][0][1],dp[i-1][1][1])+(a[i]!='L');
					dp[i][0][0]=min(dp[i-1][1][0],dp[i-1][1][0])+(a[i]!='L');
				}
				for(int X=0;X<=1;X++)
				{
					for(int Y=0;Y<=1;Y++)
					{
						if(Y==x&&x==y||X==Y&&Y==x) continue;
						ans=min(ans,dp[n][X][Y]+w);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}