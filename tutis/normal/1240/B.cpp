/*input
3
7
3 1 6 6 3 1 1
8
1 1 4 4 4 7 8 8
7
4 2 5 2 6 2 7
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		int a[n];
		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int l[n + 1];
		int r[n + 1];
		fill_n(l, n + 1, n + 1);
		fill_n(r, n + 1, -1);
		for (int i = 0; i < n; i++)
		{
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}
		int ans = v.size();
		for (int iki = 0, nuo = 0; iki < v.size(); iki++)
		{
			if (iki > 0)
			{
				if (r[v[iki - 1]] > l[v[iki]])
					nuo = iki;
			}
			ans = min(ans, (int)v.size() - (iki - nuo + 1));
		}
		cout << ans << "\n";
	}
}