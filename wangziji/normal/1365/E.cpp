#include <iostream>
#define int long long
using namespace std;
int a[1005];
signed main(int argc, char** argv) {
	int ans=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
				ans=max(ans,a[i]|a[j]|a[k]);
		}
	}
	cout << ans;
	return 0;
}