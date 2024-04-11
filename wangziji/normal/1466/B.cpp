#include <iostream>
using namespace std;
int cnt[200005],vis[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=0;i<=n*2+3;i++)
			cnt[i]=vis[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			++cnt[x];
		}
		for(int i=0;i<=n*2+1;i++)
		{
			ans+=(cnt[i]||vis[i]);
			if((vis[i]&&cnt[i])||(!vis[i]&&cnt[i]>=2))
				vis[i+1]=1;
		}
		cout << ans << "\n";
	}
	return 0;
}