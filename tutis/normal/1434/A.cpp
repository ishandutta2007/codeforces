/*input
1 1 2 2 3 3
7
13 4 11 12 11 13 12

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a[6];
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	int n;
	cin >> n;
	int b[n];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(b, b + n);
	sort(a, a + 6, greater<int>());
	map<int, vector<pair<int, int>>>M;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int x = b[i] - a[j];
			if (M.find(x) == M.end())
				M[x] = {};
			M[x + 1].push_back({i, j});
		}
	}
	multiset<int, greater<int>>V;
	for (int i = 0; i < n; i++)
		V.insert(b[i] - a[0]);
	ll ret = 2e9;
	for (auto i : M)
	{
		ll lo = i.first;
		for (auto j : i.second)
		{
			int id = j.first;
			int c = j.second;
			if (c == 5)
			{
				V.erase(V.find(b[id] - a[c]));
			}
			else
			{
				V.erase(V.find(b[id] - a[c]));
				V.insert(b[id] - a[c + 1]);
			}
		}
		if (V.size() == n)
		{
			ll hi = *V.begin();
			ret = min(ret, hi - lo);
		}
	}
	cout << ret << "\n";
}