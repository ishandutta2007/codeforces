/*input
10 3
4 7 2
1 10 3
8 9 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	pair<pair<int, int>, pair<int, int>>X[m];
	int Veiks[n + 1];
	for (int i = 0; i <= n; i++)
		Veiks[i] = 0;
	for (int i = 0; i < m; i++)
	{
		int s, d, c;
		cin >> s >> d >> c;
		X[i] = {{s, d - 1}, {c, i + 1}};
		Veiks[d] = m + 1;
	}
	sort(X, X + m, [](auto x, auto y) {
		if (x.first.second != y.first.second)
			return x.first.second < y.first.second;
		return x.first.first < y.first.first;
	});
	for (auto x : X)
	{
		int kiek = x.second.first;
		for (int i = x.first.first; i <= x.first.second && kiek > 0; i++)
		{
			if (Veiks[i] == 0)
			{
				kiek--;
				Veiks[i] = x.second.second;
			}
		}
		if (kiek > 0)
		{
			cout << "-1";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << Veiks[i] << " ";


}