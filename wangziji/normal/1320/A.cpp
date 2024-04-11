#include <iostream>
#define int long long
using namespace std;
int ans[1000005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		ans[t-i+300000]+=t;
	}
	int mx=0;
	for(int i=1;i<=1000000;i++) mx=max(mx,ans[i]);
	cout << mx;
	
	return 0;
}