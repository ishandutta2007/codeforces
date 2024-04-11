/*input
13
1 1 4 2 1 2 2 3 5 4 2 1 1
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
mt19937 rng(123);
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int>M;
	int mx = 1;
	vector<vector<int>>ans;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		M[a]++;
		ans = {{a}};
	}
	map<int, int>KK;
	for (auto i : M)
		KK[i.second]++;
	vector<pair<int, int>>K_(KK.begin(), KK.end());
	vector<pair<int, int>>V;
	for (auto i : M)
		V.push_back({i.second, i.first});
	sort(V.begin(), V.end(), greater<pair<int, int>>());
	vector<int>p;
	for (int x = 1; x * x <= n; x++)
		p.push_back(x);
	shuffle(p.begin(), p.end(), rng);
	for (int x : p)
	{
		int kiek = 0;
		for (pair<int, int>i : K_)
			kiek += i.second * min(x, i.first);
		int y = kiek / x;
		if (y < x)
			continue;
		if (x * y > mx)
		{
			mx = x * y;
			ans = vector<vector<int>>(x, vector<int>(y, -1));
			int liko = x * y;
			int i = 0;
			int j = 0;
			int kk = 1;
			for (pair<int, int>ii : V)
			{
				int k = min({liko, x, ii.first});
				liko -= k;
				while (k--)
				{
					ans[i][j] = ii.second;
					i++;
					j++;
					if (j >= y)
					{
						j = 0;
					}
					if (i >= x)
					{
						i = 0;
						j = kk;
						kk++;
					}
				}
				if (liko == 0)
					break;
			}
		}
	}
	cout << mx << "\n";
	cout << ans.size() << " " << ans[0].size() << "\n";
	for (vector<int>i : ans)
	{
		for (int j : i)
			cout << j << " ";
		cout << "\n";
	}
}