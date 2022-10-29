#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int dp[100],cnt[100];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		memset(dp,0,sizeof dp);
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<30;i++)
		{
			if((1<<i+1)-1<=n)
			{
				cnt[i]=(1<<i);
			}else
			{
				cnt[i]=n-(1<<i)+1;
	//		cout << dp[i] << " ";
				break;
			}
	//		cout << dp[i] << " ";
		}
	//	puts("");
		for(int i=0;i<=30;i++)
		{
			dp[i]+=cnt[i];
			for(int j=i+1;j<=30;j++)
				dp[j]+=dp[i]%m*cnt[j]%m,dp[j]%=m;
		}
		int ans=0;
		for(int i=0;i<=30;i++)
			ans+=dp[i]%m,ans%=m;
		cout << ans << "\n";
	}
	return 0;
}