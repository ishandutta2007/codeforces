#include <bits/stdc++.h>
using namespace std;
bool f(int64_t a, int64_t b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int64_t a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	int64_t N = n;
	int64_t X[N];
	for (int64_t i = 0; i < n; i++)
	{
		cin >> X[i];
	}
	sort(X, X + N, f);
	set<pair<int64_t, int64_t>> D[n + 1];
	D[0].insert(make_pair(h, w));
	if (h >= a and w >= b)
	{
		cout << 0;
		return 0;
	}
	swap(a, b);
	if (h >= a and w >= b)
	{
		cout << 0;
		return 0;
	}
	for (int64_t i = 1; i <= N; i++)
	{
		for (pair<int64_t, int64_t> c : D[i - 1])
		{
			if ((c.first * X[i - 1] >= a and c.second >= b) or (c.first >= a and c.second * X[i - 1] >= b))
			{
				cout << i;
				return 0;
			}
			swap(a, b);
			if ((c.first * X[i - 1] >= a and c.second >= b) or (c.first >= a and c.second * X[i - 1] >= b))
			{
				cout << i;
				return 0;
			}
			if (c.first >= a)
			{
				D[i].insert(make_pair(c.first, c.second * X[i - 1]));
			}
			else if (c.second >= b)
			{
				D[i].insert(make_pair(c.first * X[i - 1], c.second));
			}
			else
			{
				D[i].insert(make_pair(c.first, c.second * X[i - 1]));
				D[i].insert(make_pair(c.first * X[i - 1], c.second));
			}
		}
	}
	cout << - 1;
}