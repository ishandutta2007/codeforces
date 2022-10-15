/*input
4 4
2 3 2
3 5 1
4 7 2
11 15 5
4
1 3
2 5
2 6
5 14

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int ans[10001][4001];
void update(int l, int r, vector<int>hap, vector<pair<pair<int, int>, pair<int, int>>>add, int dx = 0)
{
	vector<pair<pair<int, int>, pair<int, int>>>al, ar;
	for (auto i : add)
	{
		if (i.first.second < l || r < i.first.first);
		else if (i.first.first <= l && r <= i.first.second)
		{
			int c = i.second.first;
			int h = i.second.second;
			for (int t = 4000; t >= c; t--)
			{
				hap[t] = max(hap[t], hap[t - c] + h);
			}
		}
		else
		{
			al.push_back(i);
			ar.push_back(i);
		}
	}
	if (l < r)
	{
		update(l, (l + r) / 2, hap, al, dx);
		update((l + r) / 2 + 1, r, hap, ar, dx);
	}
	else
	{
		for (int t = 0; t <= 4000; t++)
			ans[l - dx][t] = hap[t];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	vector<pair<pair<int, int>, pair<int, int>>>add;
	vector<int>hap(4001, -1e8);
	hap[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int c, h, t;
		cin >> c >> h >> t;
		add.push_back({{t, t + p - 1}, {c, h}});
	}
	int q;
	cin >> q;
	vector<pair<pair<int, int>, int>>queries[2];
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a <= 10000)
			queries[0].push_back({{a, b}, i});
		else
			queries[1].push_back({{a, b}, i});
	}
	int ret[q];
	fill_n(ret, q, 0);
	update(0, 10000, hap, add);
	for (auto i : queries[0])
	{
		int a = i.first.first;
		int b = i.first.second;
		int id = i.second;
		for (int t = 0; t <= b; t++)
			ret[id] = max(ret[id], ans[a][t]);
	}
	update(10001, 20000, hap, add, 10000);
	for (auto i : queries[1])
	{
		int a = i.first.first - 10000;
		int b = i.first.second;
		int id = i.second;
		for (int t = 0; t <= b; t++)
			ret[id] = max(ret[id], ans[a][t]);
	}
	for (int i = 0; i < q; i++)
		cout << ret[i] << "\n";
}