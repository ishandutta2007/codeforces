/*input
3 1
2 > 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll X[80][80][40];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>x[3];
	while (k--)
	{
		int a, b;
		string s;
		cin >> a >> s >> b;
		if (s == "=")
		{
			x[2].push_back({a, b});
		}
		if (s == "<")
		{
			x[0].push_back({a, b});
		}
		if (s == ">")
		{
			x[0].push_back({b, a});
		}
		if (s == "<=")
		{
			x[1].push_back({a, b});
		}
		if (s == ">=")
		{
			x[1].push_back({b, a});
		}
	}
	for (int a = 0; a < 80; a++)
		for (int b = 0; b < 80; b++)
			for (int c = 0; c < 40; c++)
				X[a][b][c] = -1;
	function<ll(int, int, int)>DP = [&](int l, int r, int k)->ll
	{
		if (l == r - 1)
			return 1;
		if (X[l][r][k] != -1)
			return X[l][r][k];
		ll ans = 0;
		{
			bool ok = true;
			int a[2 * n + 1];
			fill_n(a, 2 * n + 1, 0);
			for (int i = 1; i <= l; i++)
				a[i] = k - 1;
			for (int i = r; i <= 2 * n; i++)
				a[i] = k - 1;
			a[l + 1] = a[l + 2] = k;
			{
				for (pair<int, int>b : x[0])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] < a[b.second]);
						}
					}
				}
				for (pair<int, int>b : x[1])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] <= a[b.second]);
						}
					}
				}
				for (pair<int, int>b : x[2])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] == a[b.second]);
						}
					}
				}
			}
			if (ok)
			{
				ans += DP(l + 2, r, k + 1);
			}
		}
		if (r - l + 1 == 4)
			return X[l][r][k] = ans;
		{
			bool ok = true;
			int a[2 * n + 1];
			fill_n(a, 2 * n + 1, 0);
			for (int i = 1; i <= l; i++)
				a[i] = k - 1;
			for (int i = r; i <= 2 * n; i++)
				a[i] = k - 1;
			a[r - 1] = a[r - 2] = k;
			{
				for (pair<int, int>b : x[0])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] < a[b.second]);
						}
					}
				}
				for (pair<int, int>b : x[1])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] <= a[b.second]);
						}
					}
				}
				for (pair<int, int>b : x[2])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] == a[b.second]);
						}
					}
				}
			}
			if (ok)
				ans += DP(l, r - 2, k + 1);
		}
		{
			bool ok = true;
			int a[2 * n + 1];
			fill_n(a, 2 * n + 1, 0);
			for (int i = 1; i <= l; i++)
				a[i] = k - 1;
			for (int i = r; i <= 2 * n; i++)
				a[i] = k - 1;
			a[l + 1] = a[r - 1] = k;
			{
				for (pair<int, int>b : x[0])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] < a[b.second]);
						}
					}
				}
				for (pair<int, int>b : x[1])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] <= a[b.second]);
						}
					}
				}
				for (pair<int, int>b : x[2])
				{
					if (min(a[b.first], a[b.second]) != 0)
					{
						if (max(a[b.first], a[b.second]) == k)
						{
							ok &= (a[b.first] == a[b.second]);
						}
					}
				}
			}
			if (ok)
				ans += DP(l + 1, r - 1, k + 1);
		}
		return X[l][r][k] = ans;
	};
	cout << DP(0, 2 * n + 1, 1) << "\n";
}