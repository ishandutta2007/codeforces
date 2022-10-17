#include <bits/stdc++.h>
using namespace std;
int y1, m1, d1, y2, m2, d2;
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isleap(int y)
{
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
bool ok(int y2, int m2, int d2)
{
	if (m2 > 12)
	{
		return false;
	}
	if (d2 > a[m2] + (m2 == 2 && y2 % 4 == 0))
	{
		return false;
	}
	int yy = y1 - y2;
	if (m2 > m1 || (m2 == m1 && d2 > d1))
	{
		yy--;
	}
	return yy >= 18;
}
int main()
{
	scanf("%d.%d.%d", &d1, &m1, &y1);
	scanf("%d.%d.%d", &d2, &m2, &y2);
	if (ok(y2, m2, d2) || ok(y2, d2, m2) || ok(m2, y2, d2) || ok(m2, d2, y2) || ok(d2, y2, m2) || ok(d2, m2, y2))
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}