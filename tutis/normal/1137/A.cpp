/*input
2 3
1 2 1
2 1 2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	vector<int>ans1[n];
	vector<int>ans2[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans1[i].push_back(a[i][j]);
			ans2[j].push_back(a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		sort(ans1[i].begin(), ans1[i].end());
		ans1[i].erase(unique(ans1[i].begin(), ans1[i].end()), ans1[i].end());
	}
	for (int i = 0; i < m; i++)
	{
		sort(ans2[i].begin(), ans2[i].end());
		ans2[i].erase(unique(ans2[i].begin(), ans2[i].end()), ans2[i].end());
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int ans = 0;
			int x = lower_bound(ans1[i].begin(), ans1[i].end(), a[i][j]) - ans1[i].begin();
			int y = lower_bound(ans2[j].begin(), ans2[j].end(), a[i][j]) - ans2[j].begin();
			cout << max(x, y) + max(ans1[i].size() - x, ans2[j].size() - y) << " ";
		}
		cout << "\n";
	}

}