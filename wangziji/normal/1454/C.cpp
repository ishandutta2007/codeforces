#include <iostream>
using namespace std;
int vis[200005],w[200005],a[200004];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) w[i]=vis[i]=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1]) ++w[a[i]];
			++vis[a[i]];
		}
		++vis[a[1]];
		++w[a[1]],++w[a[n]];
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]])
			{
				ans=min(ans,-w[a[i]]+vis[a[i]]+1);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}