#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005],dp[15];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int ans=1e9;
		for(int x=0;x<=3;x++)
		{
			for(int y=0;y<=3;y++)
			{
				int qwq=0;
				for(int i=1;i<=10;i++) dp[i]=1e9;
				for(int X=0;X<=x;X++)
					for(int Y=0;Y<=y;Y++)
						dp[X+Y+Y]=0;
				for(int i=1;i<=n;i++)
				{
					int qaq=1e9;
					for(int k=0;k<=min(10ll,a[i]);k++)
						if((a[i]-k)%3==0) qaq=min(qaq,dp[k]+(a[i]-k)/3);
					qwq=max(qwq,qaq);
				}
				ans=min(ans,qwq+x+y);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}