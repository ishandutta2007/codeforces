#include <iostream>
#include <cstring>
using namespace std;
int a[10005],s[10005];
signed main() {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++) cin >> a[i];
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=max(0,a[i]-s[i]-1);
			s[i]=max(s[i],a[i]-1);
			for(int j=i+2;j<=min(n,i+a[i]);j++)
				++s[j];
			s[i+1]+=max(0,s[i]-a[i]+1);
		}
		cout << ans << "\n";
	}
	return 0;
}