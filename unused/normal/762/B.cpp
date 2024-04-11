#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int m;
	scanf("%d", &m);
	vector<pair<int, char>> vt;
	vt.reserve(m);
	for (int i = 0; i < m; i++)
	{
		int x; char y;
		scanf("%d %c%*s", &x, &y);
		vt.emplace_back(x, y);
	}

	sort(vt.begin(), vt.end());
	long long total = 0;
	int ans = 0;
	for (auto &&e : vt)
	{
		if (e.second == 'U')
		{
			if (a)
			{
				--a; ++ans; total += e.first;
			}
			else if (c)
			{
				--c; ++ans; total += e.first;
			}
		}
		else
		{
			if (b)
			{
				--b; ++ans; total += e.first;
			}
			else if (c)
			{
				--c; ++ans; total += e.first;
			}
		}
	}

	printf("%d %lld", ans, total);
}