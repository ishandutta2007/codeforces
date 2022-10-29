#include <iostream>
using namespace std;
int a[100005],vis[10005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int ans=0;
		for(int i=0;i<=1000;i++) vis[i]=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans+=(!vis[a[j]-a[i]]++);
		}
		cout << ans << "\n";
	}
	return 0;
}