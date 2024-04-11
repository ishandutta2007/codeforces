#include <bits/stdc++.h>
#define int long long
using namespace std;
int vis[100005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			vis[b]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						cout << i << " " << j << "\n";
					}
				}
				break;
			}
		}
	}
	return 0;
}