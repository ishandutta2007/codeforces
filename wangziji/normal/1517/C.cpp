#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 
int p[505],ans[505][505];
signed main(int argc, char** argv) {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> p[i];
	for(int i=1;i<=n;i++)
	{
		int x=i,y=i,cnt=p[i];
		while(cnt)
		{
			--cnt;
			ans[x][y]=p[i];
			if(!ans[x][y-1]&&y!=1) --y;
			else ++x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
	return 0;
}