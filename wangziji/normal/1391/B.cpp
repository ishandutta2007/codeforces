#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin >> c;
				if(c=='R'&&j==m) ++ans;
				else if(c=='D'&&i==n) ++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}