#include <iostream>
#include <bitset>
using namespace std;
bitset <10005> dp,vis;
int a[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n+n;i++)
			cin >> a[i];
		dp.reset();
		vis.reset();
		dp[0]=1;
		for(int i=1;i<=n+n;i++)
		{
			if(vis[i]) continue;
			int now=1;
			for(int j=i+1;j<=n+n;j++)
			{
				if(a[j]>a[i]) break;
				++now,vis[j]=1;
			}
		//	cout << i << " " << now << "\n";
			dp|=dp<<now;
		}
		if(dp[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}