/*input
4
4
0 1 1 1
1 10 100 1000
6
0 0 0 1 1 1
3 4 5 6 7 8
3
1 1 1
1000000000 1000000000 1000000000
1
1
1

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
mt19937_64 rng(0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		ll best = 0;
		for (int t : {0, 1})
		{
			vector<ll>x[2];
			for (int i = 0; i < n; i++)
				x[a[i]].push_back(b[i]);
			for (int t : {0, 1})
				sort(x[t].begin(), x[t].end(), greater<int>());
			if (x[t].empty())
				continue;
			ll gal = x[t].back();
			x[t].pop_back();
			for (int t : {0, 1})
				sort(x[t].begin(), x[t].end());
			int v = t;
			int m = 2;
			while (true)
			{
				v = 1 - v;
				if (x[0].empty() && x[1].empty())
					break;
				if (x[v].empty())
					m = 1;
				else {
					gal += x[v].back() * m;
					x[v].pop_back();
				}
			}
			best = max(best, gal);
		}
		cout << best << "\n";
	}
}