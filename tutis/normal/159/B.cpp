/*input
2 2
1 2
2 1
3 4
5 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n, m;
	cin >> n >> m;
	map<int, pair<multiset<int>, multiset<int>>>M;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		M[y].first.insert(x);
	}
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		M[y].second.insert(x);
	}
	int u = 0;
	int v = 0;
	for (auto it : M)
	{
		multiset<int>x = it.second.first;
		multiset<int>y = it.second.second;
		u += min(x.size(), y.size());
		for (int i : x)
		{
			auto it = y.find(i);
			if (it != y.end())
			{
				y.erase(it);
				v++;
			}
		}
	}
	cout << u << " " << v << "\n";
	return 0;
}