/*input
5
1 3
2 4
5 9
6 8
7 10

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int pa[n];
	iota(pa, pa + n, 0);
	pair<int, int>a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	map<int, int>M;
	int kiek = 0;
	function<int(int)>root = [&](int i)->int
	{
		if (pa[i] == i)
			return i;
		return pa[i] = root(pa[i]);
	};
	for (int i = 0; i < n; i++)
	{
		for (auto it = M.upper_bound(a[i].first); it != M.end() && it->first < a[i].second; it++)
		{
			int j = it->second;
			pa[root(i)] = root(j);
			kiek++;
			if (kiek >= n)
			{
				cout << "NO\n";
				return 0;
			}
		}
		M[a[i].second] = i;
	}
	if (kiek != n - 1)
	{
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (root(i) != root(0))
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
}