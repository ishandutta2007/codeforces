#include <bits/stdc++.h>
using namespace std;

int main()
{
	int s, x1, x2, t1, t2, p, d;
	scanf("%d%d%d%d%d%d%d", &s, &x1, &x2, &t1, &t2, &p, &d);

	int ans1 = abs(x1 - x2) * t2;
	if (t1 >= t2)
	{
		printf("%d", ans1);
		return 0;
	}

	int d2 = (x1 < x2) ? 1 : -1;
	if (d2 != d)
	{
		int ans2 = ((d == -1) ? p + x2 : s - p + s - x2) * t1;
		printf("%d", min(ans1, ans2));
		return 0;
	}
	else
	{
		int ans2;

		if (p * d <= x1 * d)
		{
			ans2 = abs(p - x2) * t1;
		}
		else if (d == 1)
		{
			ans2 = ((s - p) + s + x2) * t1;
		}
		else
		{
			ans2 = (p + s + (s - x2)) * t1;
		}

		printf("%d", min(ans1, ans2));
	}
}