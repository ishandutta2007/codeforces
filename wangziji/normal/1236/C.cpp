#include <iostream>
using namespace std;
int ans[1005][1005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=n;j++)
			{
				++now;
				ans[j][i]=now;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				++now;
				ans[j][i]=now;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}