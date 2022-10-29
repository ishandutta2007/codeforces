#include <iostream>
#define int long long
using namespace std;
int cnt[100],a[500005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		for(int j=0;j<=20;j++)
		{
			if(a[i]&(1<<j))
				++cnt[j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=0;j<=20;j++)
			if(cnt[j]) --cnt[j],now|=(1<<j);
		ans+=now*now;
	}
	cout << ans;
	return 0;
}