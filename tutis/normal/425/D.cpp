/*input
9
0 0
1 1
2 2
0 1
1 0
0 2
2 0
1 2
2 1

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> X[100001];
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>A;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		X[x].push_back(y);
		A.push_back({x, y});
	}
	for (int x = 0; x <= 100000; x++)
		sort(X[x].begin(), X[x].end());
	auto yra = [&](int x, int y)
	{
		if (x < 0 || x > 100000 || y < 0 || y > 100000)
			return false;
		return binary_search(X[x].begin(), X[x].end(), y);
	};
	ll ans = 0;
	for (int x = 0; x <= 100000; x++)
	{
		if (X[x].size() <= 400)
		{
			for (int t = 0; t < X[x].size(); t++)
			{
				for (int t1 = 0; t1 < t; t1++)
				{
					int y1 = X[x][t1];
					int y2 = X[x][t];
					int d = y2 - y1;
					if (yra(x + d, y1) && yra(x + d, y2))
						ans++;
				}
			}
		}
		else
		{
			for (pair<int, int>i : A)
			{
				if (i.first <= x)
					continue;
				int d = i.first - x;
				int x2 = i.first;
				int x1 = x;
				int y1 = i.second;
				int y2 = y1 + d;
				if (yra(x1, y1) && yra(x1, y2) && yra(x2, y2) && yra(x2, y1))
					ans++;
			}
		}
	}
	cout << ans << "\n";
}