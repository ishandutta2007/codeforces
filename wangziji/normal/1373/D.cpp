#include <iostream>
#define int long long
using namespace std;
int a[200005],b[200005],cnt;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int ans=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i+=2)
			ans+=a[i];
		int mx=0;
		cnt=0;
		for(int i=2;i<=n;i+=2)
			b[++cnt]=a[i]-a[i-1];
		int now=0;
		for(int i=1;i<=cnt;i++)
			now+=b[i],now=max(now,(int)0),mx=max(mx,now);
		cnt=0;
		for(int i=3;i<=n;i+=2)
			b[++cnt]=-a[i]+a[i-1];
		now=0;
		for(int i=1;i<=cnt;i++)
			now+=b[i],now=max(now,(int)0),mx=max(mx,now);
		cout << ans+mx << "\n"; 
	}
	return 0;
}