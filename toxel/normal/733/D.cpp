#include<bits/stdc++.h>
const int N = 100010;
using namespace std;

int n, a[N], b[N], c[N];
map <pair <int, int>, pair <int, int>> Hash;

int main()
{
	scanf("%d", &n);
	int ans = 0, num;
	vector <int> sit;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		int _a = a[i], _b = b[i], _c = c[i];
		if (Hash.count({a[i], b[i]}))
		{
			_c += Hash[{a[i], b[i]}].first;
			int mini = min(min(_a, _b), _c);
			if (mini > ans)
			{
				num = 2;
				ans = mini;
				sit = {Hash[{a[i], b[i]}].second, i};
			}
			_c -= Hash[{a[i], b[i]}].first;
		}
		if (Hash.count({a[i], c[i]}))
		{
			_b += Hash[{a[i], c[i]}].first;
			int mini = min(min(_a, _b), _c);
			if (mini > ans)
			{
				num = 2;
				ans = mini;
				sit = {Hash[{a[i], c[i]}].second, i};
			}
			_b -= Hash[{a[i], c[i]}].first;
		}
		if (Hash.count({b[i], c[i]}))
		{
			_a += Hash[{b[i], c[i]}].first;
			int mini = min(min(_a, _b), _c);
			if (mini > ans)
			{
				num = 2;
				ans = mini;
				sit = {Hash[{b[i], c[i]}].second, i};
			}
			_a -= Hash[{b[i], c[i]}].first;
		}
		int mini = min(min(_a, _b), _c);
		if (mini > ans)
		{
			num = 1;
			ans = mini;
			sit = {i};
		}
		if (!Hash.count({a[i], b[i]}) || Hash[{a[i], b[i]}].first < c[i])
			Hash[{a[i], b[i]}] = {c[i], i};
		if (!Hash.count({b[i], a[i]}) || Hash[{b[i], a[i]}].first < c[i])
			Hash[{b[i], a[i]}] = {c[i], i};
		if (!Hash.count({a[i], c[i]}) || Hash[{a[i], c[i]}].first < b[i])
			Hash[{a[i], c[i]}] = {b[i], i};
		if (!Hash.count({c[i], a[i]}) || Hash[{c[i], a[i]}].first < b[i])
			Hash[{c[i], a[i]}] = {b[i], i};
		if (!Hash.count({c[i], b[i]}) || Hash[{c[i], b[i]}].first < a[i])
			Hash[{c[i], b[i]}] = {a[i], i};
		if (!Hash.count({b[i], c[i]}) || Hash[{b[i], c[i]}].first < a[i])
			Hash[{b[i], c[i]}] = {a[i], i};
	}
	printf("%d\n", num);
	for (int i = 0; i < sit.size(); i++)
		printf("%d ", sit[i]);
	printf("\n");
	return 0;
}