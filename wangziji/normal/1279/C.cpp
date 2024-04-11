#include <iostream>
#define int long long
using namespace std;
int a[100005],pos[100005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			pos[a[i]]=i;
		}
		int ans=0,mx=0;
		for(int i=1;i<=m;i++)
		{
			int t;
			cin >> t;
			if(pos[t]<mx) ++ans;
			else ans+=(pos[t]-i)*2+1;
			mx=max(mx,pos[t]);
		}
		cout << ans << "\n";
	}
	return 0;
}