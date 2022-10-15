/*input
8 5
1 1 1 1 1 2 8 2
1 1
0 1 3
1 1
0 3 4
1 2
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int a[N + 1];
	a[0] = 1;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	pair<int, int> x[N + 1];
	for (int i = 1; i <= N; i++)
		x[i] = {i + a[i], 1};
	int k = 400;
	for (int i = N; i >= 1; i--)
	{
		x[i] = {i + a[i], 1};
		if (x[i].first <= N && x[i].first / k == i / k)
			x[i] = {x[x[i].first].first, x[x[i].first].second + 1};
	}
	while (M--)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			int j, y;
			cin >> j >> y;
			a[j] = y;
			for (int i = j; (i / k) == (j / k); i--)
			{
				x[i] = {i + a[i], 1};
				if (x[i].first <= N && x[i].first / k == i / k)
					x[i] = {x[x[i].first].first, x[x[i].first].second + 1};
			}
		}
		else
		{
			int i;
			cin >> i;
			int cnt = 0;
			while (i + a[i] <= N)
			{
				if (x[i].first <= N)
				{
					cnt += x[i].second;
					i = x[i].first;
				}
				else
				{
					i += a[i];
					cnt++;
				}
			}
			cout << i << " " << cnt + 1 << "\n";
		}
	}
}