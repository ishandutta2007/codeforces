/*input
3
+
+
+
- 2
- 1
- 3

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int p[n + 1];
	set<pair<int, int>, greater<pair<int, int>>>P;
	int t = 0;
	pair<char, int>I[2 * n];
	for (int i = 0; i < 2 * n; i++)
	{
		char c;
		cin >> c;
		I[i].first = c;
		if (c == '-')
		{
			int v;
			cin >> v;
			I[i].second = v;
			p[v] = i;
		}
		else
		{
			P.insert({i, t});
			t++;
		}
	}
	int ans[n];
	for (int i = 1; i <= n; i++)
	{
		auto it = P.lower_bound(make_pair(p[i], 0));
		if (it == P.end())
		{
			cout << "NO\n";
			return 0;
		}
		else
		{
			int a = it->first;
			int b = it->second;
			ans[b] = i;
			P.erase(it);
		}
	}
	t = 0;
	set<int>S;
	for (int i = 0; i < 2 * n; i++)
	{
		if (I[i].first == '+')
		{
			S.insert(ans[t]);
			t++;
		}
		else
		{
			int x = *S.begin();
			S.erase(x);
			if (x != I[i].second)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}