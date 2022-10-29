#include <bits/stdc++.h>
using namespace std;
int ans[100][100];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		memset(ans,0,sizeof ans);
		for(int i=1;i<=m;i+=2) ans[1][i]=1;
		for(int i=3;i<=n;i+=2) ans[i][m]=1;
		for(int i=m-2;i>=1;i-=2) ans[n][i]=1;
		for(int i=n-2;i>=3;i-=2) ans[i][1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout << ans[i][j];
			cout << "\n"; 
		}
	}
	return 0;
}