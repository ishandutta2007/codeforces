/*input
3 3
2 3 8
4 2 9
3 1 7

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			cin >> a[i][j];
	vector<int>ans;
	for (int i = 0; i < m; i++)
		ans.push_back(i);
	for (int i = 0; i < n - 1; i++)
	{
		vector<pair<int, int>>delt;
		for (int j = 0; j < m; j++)
			delt.push_back({a[n - 1][j] - a[i][j], j});
		sort(delt.begin(), delt.end());
		int k = 0;
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += delt[j].first;
			if (sum <= 0)
				k = j + 1;
		}
		vector<int>ans1;
		for (int j = k; j < m; j++)
			ans1.push_back(delt[j].second);
		if (ans1.size() < ans.size())
			ans = ans1;
	}
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i + 1 << " ";
}