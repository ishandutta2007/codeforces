#include <iostream>
#include <cstring>
using namespace std;
int vis[1005];
int main(int argc, char** argv) {
	int T;
	cin>> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			vis[x]=1;
		}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int x;
			cin >> x;
			ans+=vis[x];
		 } 
		 cout << ans << "\n";
	}
	return 0;
}