/*input
3 4
1 3
1 3
4 5
1 2
1 3
1 4
1 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>>inter;
int yy[505050][20];
int ans(int x, int y)
{
	int ret = 0;
	for (int t = 19; t >= 0; t--)
	{
		if (yy[x][t] < y && yy[x][t] > x)
		{
			ret += (1 << t);
			x = yy[x][t];
		}
	}
	x = yy[x][0];
	ret++;
	if (x >= y)
		return ret;
	return 202020;
}
vector<int>add[505050];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>a;
	int l[n], r[n];
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
		add[l[i]].push_back(i);
	}
	deque<int>xx;
	for (int x = 0; x <= 500000; x++)
	{
		for (int i : add[x])
		{
			while (!xx.empty() && r[xx.back()] < r[i])
				xx.pop_back();
			xx.push_back(i);
		}
		while (!xx.empty() && r[xx.front()] < x)
			xx.pop_front();
		if (!xx.empty())
			yy[x][0] = r[xx.front()];
		else
			yy[x][0] = x;
	}
	for (int t = 1; t < 20; t++)
		for (int x = 0; x <= 500000; x++)
		{
			yy[x][t] = yy[yy[x][t - 1]][t - 1];
		}
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		int k = ans(x, y);
		if (k > n)
			k = -1;
		cout << k << "\n";
	}
	return 0;
}