#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int a, b, c, d, val[Maxn];
int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int res = a + b + c + d;
	if (abs(a + c - b - d) > 1)
	{
		printf("NO\n");
		return 0;
	}
	int now = 0;
	if (a + c >= b + d)
	{
		if (!a) now = 2;
		for (int i = 1; i <= res; i += 2)
		{
			val[i] = now;
			a--;
			if (!a) now = 2;
		}
		now = 1;
		if (!b) now = 3;
		for (int i = 2; i <= res; i += 2)
		{
			val[i] = now;
			b--;
			if (!b) now = 3;
		}
	}
	else
	{
		if (!a) now = 2;
		for (int i = 2; i <= res; i += 2)
		{
			val[i] = now;
			a--;
			if (!a) now = 2;
		}
		now = 1;
		if (!b) now = 3;
		for (int i = 1; i <= res; i += 2)
		{
			val[i] = now;
			b--;
			if (!b) now = 3;
		}
	}
	for (int i = 1; i < res; i++)
		if (abs(val[i] - val[i + 1]) != 1)
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	for (int i = 1; i <= res; i++)
		printf("%d ", val[i]);
	return 0;
}