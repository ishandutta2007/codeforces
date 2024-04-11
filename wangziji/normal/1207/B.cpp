#include <iostream>
#include <vector>
using namespace std;
int a[100][100];
vector <pair<int,int> > ans;
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin >>a [i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]&&i!=n&&m-j)
			{
				a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=2;
				ans.push_back({i,j});
			}
			//cout << a[i][j] << " ";
		}
		//cout << endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}