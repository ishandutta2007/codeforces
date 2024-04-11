#include <iostream>
using namespace std;
int dp[200005],a[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int mx=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=n;i>=1;i--)
		{
			if(a[i]+i>n)
				dp[i]=a[i];
			else dp[i]=max(a[i],dp[i+a[i]]+a[i]);
			mx=max(mx,dp[i]);
		}
		cout << mx << "\n";
	 } 
	return 0;
}