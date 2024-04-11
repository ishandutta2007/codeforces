#include <iostream>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,s;
		cin >> n >> s;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int mx=0,sum=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum-max(mx,a[i])>s)
			{
				break;
			}
			if(a[i]>mx) ans=i;
			mx=max(mx,a[i]);
		}
		if(sum<=s) ans=0;
		cout << ans << "\n";
	}
	return 0;
}