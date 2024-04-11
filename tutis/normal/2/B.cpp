/*input
3
1 2 3
4 5 6
7 8 6
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using pii = pair<int, int>;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int ans = 1e9;
	string ret = string(n - 1, 'R') + string(n - 1, 'D');
	int k2[n][n];
	int k5[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				k2[i][j] = k5[i][j] = 1e9;
				if (ans > 1)
				{
					ans = 1;
					ret = string(i, 'D') + string(j, 'R') + string(n - 1 - i, 'D') + string(n - 1 - j, 'R');
				}
			}
			if (a[i][j] != 0)
			{
				k2[i][j] = 0;
				int x = a[i][j];
				while (x % 2 == 0)
				{
					x /= 2;
					k2[i][j]++;
				}
			}
			if (a[i][j] != 0)
			{
				k5[i][j] = 0;
				int x = a[i][j];
				while (x % 5 == 0)
				{
					x /= 5;
					k5[i][j]++;
				}
			}
		}
	pair<int, int>c2[n][n];
	pair<int, int>c5[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
			{
				c2[i][j] = {0, 'D'};
				c5[i][j] = {0, 'D'};
			}
			else if (j == 0)
			{
				c2[i][j] = {c2[i - 1][j].first, 'D'};
				c5[i][j] = {c5[i - 1][j].first, 'D'};
			}
			else if (i == 0)
			{
				c2[i][j] = {c2[i][j - 1].first, 'R'};
				c5[i][j] = {c5[i][j - 1].first, 'R'};
			}
			else
			{
				c2[i][j] = min(pii{c2[i - 1][j].first, 'D'}, {c2[i][j - 1].first, 'R'});
				c5[i][j] = min(pii{c5[i - 1][j].first, 'D'}, {c5[i][j - 1].first, 'R'});
			}
			c2[i][j].first += k2[i][j];
			c5[i][j].first += k5[i][j];
		}
	int i = n - 1;
	int j = n - 1;
	if (c2[i][j].first < ans && c2[i][j].first <= c5[i][j].first)
	{
		ans = c2[i][j].first;
		ret = "";
		while (i + j > 0)
		{
			ret.push_back(c2[i][j].second);
			if (ret.back() == 'D')
				i--;
			else
				j--;
		}
		reverse(ret.begin(), ret.end());
	}
	else if (c5[i][j].first < ans)
	{
		ans = c5[i][j].first;
		ret = "";
		while (i + j > 0)
		{
			ret.push_back(c5[i][j].second);
			if (ret.back() == 'D')
				i--;
			else
				j--;
		}
		reverse(ret.begin(), ret.end());
	}
	cout << ans << " " << ret << "\n";
}