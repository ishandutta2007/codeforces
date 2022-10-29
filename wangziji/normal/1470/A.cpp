#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[300005],b[300005];
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=m;i++)
			cin >> b[i];
		sort(a+1,a+n+1);
		int now=n,ans=0,flag=1;
		for(int i=1;i<=m;i++)
		{
			if(a[now]>i&&now)
			{
				now--,ans+=b[i];
			}
			else
			{
				while(now>=1)
				{
					ans+=b[a[now]];
					now--;
				}
				flag=0;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}