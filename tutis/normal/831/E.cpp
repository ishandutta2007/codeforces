/***
7
7 1 2 3 4 5 6
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct BIT
{
	int A[100007];
	void init()
	{
		fill_n(A, 100007, 0);
	}
	void add(int i, int k)
	{
		for (; i < 100007; i += (i) & (-i))
			A[i] += k;
	}
	int get(int i)
	{
		int s = 0;
		for (; i > 0; i -= (i) & (-i))
			s += A[i];
		return s;
	}
	int get(int l, int r)
	{
		return get(r) - get(l - 1);
	}
};
struct comp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first != b.first)
			return a.first > b.first;
		return a.second > b.second;
	}
};
vector<int>Ko[100007];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		Ko[c].push_back(i);
	}
	BIT X;
	X.init();
	for (int i = 1; i <= n; i++)
		X.add(i, 1);
	int st = 0;
	ll ans = 0;
	for (int c = 0; c <= 100000; c++)
	{
		int maxi = Ko[c].size();
		for (int i = 0; i < Ko[c].size(); i++)
		{
			if (Ko[c][i] >= st)
			{
				maxi = min(maxi, i);
				ans += X.get(st, Ko[c][i]);
				X.add(Ko[c][i], -1);
				st = Ko[c][i];
			}
		}
		for (int i = 0; i < maxi; i++)
		{
			if (Ko[c][i] >= st)
			{
				ans += X.get(st, Ko[c][i]);
				X.add(Ko[c][i], -1);
				st = Ko[c][i];
			}
			else
			{
				ans += X.get(st, n);
				ans += X.get(1, Ko[c][i]);
				X.add(Ko[c][i], -1);
				st = Ko[c][i];
			}
		}
	}
	cout << ans;
}