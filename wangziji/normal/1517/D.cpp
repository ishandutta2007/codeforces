#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int ans[22][505][505],a[505][505],b[505][505];
signed main(int argc, char** argv) {
	int n,m,k;
	cin >> n >> m >> k;
	if(k&1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout << "-1 ";
			cout << "\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			cin >> a[i][j];
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			cin >> b[i][j];
	for(int x=1;x<=k/2;x++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans[x][i][j]=1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i!=1) ans[x][i][j]=min(ans[x][i][j],ans[x-1][i-1][j]+b[i-1][j]);
				if(i!=n) ans[x][i][j]=min(ans[x][i][j],ans[x-1][i+1][j]+b[i][j]);
				if(j!=1) ans[x][i][j]=min(ans[x][i][j],ans[x-1][i][j-1]+a[i][j-1]);
				if(j!=m) ans[x][i][j]=min(ans[x][i][j],ans[x-1][i][j+1]+a[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout << ans[k/2][i][j]*2 << " ";
		cout << "\n";
	}
	return 0;
}