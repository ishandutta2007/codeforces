/*input
4 2
1 2000 2000 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	bool buvo[n + 1];
	fill_n(buvo, n + 1, false);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int>x;
	int ans = 0;
	for (int t = 0; t < k; t++)
	{
		pair<int, int> mx = { -1, -1};
		for (int i = 1; i <= n; i++)
		{
			if (!buvo[i])
			{
				mx = max(mx, {a[i], i});
			}
		}
		ans += mx.first;
		buvo[mx.second] = true;
		x.push_back(mx.second);
	}
	sort(x.begin(), x.end());
	cout << ans << "\n";
	if (x.size() == 1)
	{
		cout << n << "\n";
		return 0;
	}
	for (int i = 0; i < x.size(); i++)
	{
		if (i == 0)
		{
			cout << x[i] << " ";
		}
		else if (i + 1 < x.size())
		{
			cout << x[i] - x[i - 1] << " ";
		}
		else
		{
			cout << n - x[i - 1] << " ";
		}
	}

}