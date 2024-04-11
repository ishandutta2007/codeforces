#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n, h;
	static pair<int, int> a[MaxN];

	cin >> n >> h;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].first), a[i].second = i;

	sort(a, a + n);

	int res;
	static int num[MaxN + 1];

	if (n == 2)
	{
		res = 0;
		for (int i = 0; i < n; i++)
			num[a[i].second] = 1;
	}
	else
	{
		int t1 = (a[n - 1].first + a[n - 2].first) - (a[0].first + a[1].first);
		int t2 = max(a[n - 1].first + a[n - 2].first, a[0].first + a[n - 1].first + h) - min(a[0].first + a[1].first + h, a[1].first + a[2].first);
		if (t1 < t2)
		{
			res = t1;
			for (int i = 0; i < n; i++)
				num[a[i].second] = 1;
		}
		else
		{
			res = t2;
			num[a[0].second] = 1;
			for (int i = 1; i < n; i++)
				num[a[i].second] = 2;
		}
	}

	cout << res << endl;
	for (int i = 0; i < n; i++)
		printf("%d ", num[i]);
	cout << endl;

	return 0;
}