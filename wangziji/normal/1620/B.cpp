#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005],c[500005],d[500005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		int ans=0;
		cin >> y >> x;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		ans=max(ans,(a[n]-a[1])*x);
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		ans=max(ans,(a[n]-a[1])*x);
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		ans=max(ans,(a[n]-a[1])*y);
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		ans=max(ans,(a[n]-a[1])*y);
		cout << ans << "\n";
	}
	return 0;
}