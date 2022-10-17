#include <bits/stdc++.h>
using namespace std;
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isleap(int y)
{
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
int getindex(int y, int m, int d)
{
	int re = d;
	for (int i = 1900; i < y; i++)
	{
		if (isleap(i))
		{
			re += 366;
		}
		else
		{
			re += 365;
		}
	}
	for (int i = 1; i < m; i++)
	{
		if (i == 2 && isleap(y))
		{
			re++;
		}
		re += a[i];
	}
	return re;
}
int main()
{
	int y1, m1, d1, y2, m2, d2;
	scanf("%d:%d:%d", &y1, &m1, &d1);
	scanf("%d:%d:%d", &y2, &m2, &d2);
	printf("%d\n", abs(getindex(y1, m1, d1) - getindex(y2, m2, d2)));
	return 0;
}