#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int ans=1e18;
	for(int x=1;x<=1000000;x++)
	{
		int t=1;
		for(int i=1;i<n;i++)
		{
			t*=x;
			if(t>5e12) break;
		}
		if(t>5e12) break;
		t=1;
		int qwq=0;
		for(int i=1;i<=n;i++)
		{
			qwq+=max(t,a[i])-min(t,a[i]);
			t*=x;
		}
		ans=min(ans,qwq);
	}
	cout << ans;
	return 0;
}