#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, string> > a[10020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		int x, y;
		cin >> s >> x >> y;
		a[x].push_back(make_pair(-y, s));
	}
	for (int i = 1; i <= m; i++)
	{
		sort(a[i].begin(), a[i].end());
		if (a[i].size() > 2 && a[i][1].first == a[i][2].first)
		{
			cout << "?" << endl;
		}
		else
		{
			cout << a[i][0].second << " " << a[i][1].second << endl;
		}
	}
	return 0;
}