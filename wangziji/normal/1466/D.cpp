#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[100005],deg[100005];
pair <int,int> b[100005];
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n,ans=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			ans+=a[i],deg[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			++deg[u],++deg[v];
		}
		for(int i=1;i<=n;i++)
			b[i]={a[i],deg[i]-1};
		sort(b+1,b+n+1);
		reverse(b+1,b+n+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=b[i].second;j++)
			{
				cout << ans << " ";
				ans+=b[i].first;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}