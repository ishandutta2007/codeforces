#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,r;
		cin >> n >> r;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		sort(a+1,a+n+1);
		a[n+1]=0;
		int ans=0,now=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]==a[i+1])
				continue;
			if(a[i]<=now)
				break;
			++ans;
			now+=r;
		}
		cout << ans << endl;
	}
	return 0;
}