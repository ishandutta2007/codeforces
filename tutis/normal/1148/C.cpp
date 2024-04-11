/*input
4
3 4 1 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int p[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	int k[n + 1];
	for (int i = 1; i <= n; i++)
		k[p[i]] = i;
	vector<pair<int, int>>ans;
	for (int i = 1; i <= n; i++)
	{
		if (k[i] == i)
			continue;
		int a = i;
		int b = k[i];
		if (a > b)
			swap(a, b);
		if (abs(a - b) * 2 >= n)
		{
			ans.push_back({a, b});
			swap(p[a], p[b]);
			k[p[a]] = a;
			k[p[b]] = b;
			continue;
		}
		if (abs(n - b) * 2 >= n)
		{
			ans.push_back({b, n});
			ans.push_back({a, n});
			ans.push_back({b, n});
			swap(p[a], p[b]);
			k[p[a]] = a;
			k[p[b]] = b;
			continue;
		}
		if (abs(1 - a) * 2 >= n)
		{
			ans.push_back({a, 1});
			ans.push_back({b, 1});
			ans.push_back({a, 1});
			swap(p[a], p[b]);
			k[p[a]] = a;
			k[p[b]] = b;
			continue;
		}
		ans.push_back({a, n});
		ans.push_back({b, 1});
		ans.push_back({n, 1});
		ans.push_back({a, n});
		ans.push_back({b, 1});
		swap(p[a], p[b]);
		k[p[a]] = a;
		k[p[b]] = b;
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";
}