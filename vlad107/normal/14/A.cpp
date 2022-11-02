#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

#define MAXN 55

int main()
{
	int n, m;
	char a[MAXN][MAXN];
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++)
		gets(a[i]);
	int sx = MAXN, sy = MAXN, ex = -1, ey = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == '*')
				{
					if (i < sx) sx = i;
					if (j < sy) sy = j;
				}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == '*')
				{
					if (i+1 > ex) ex = i+1;
					if (j+1 > ey) ey = j+1;
				}
	for (int i = sx; i < ex; i++)
		{
			for (int j = sy; j < ey; j++)
				printf("%c", a[i][j]);
			printf("\n");
		}
}