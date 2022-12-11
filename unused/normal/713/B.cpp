#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <array>
using namespace std;

vector<array<int, 4>> ret;
using ll = long long;
int n;

bool getans(int sx, int sy, int ex, int ey)
{
	if (sx <= 0 || sy <= 0 || ex > n || ey > n || sx > ex || sy > ey) return false;
	printf("? %d %d %d %d\n", sx, sy, ex, ey);
	fflush(stdout);
	int tmp;
	scanf("%d", &tmp);
	if (tmp != 1) return false;

	int lo = sy, hi = ey, upper = sy;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		printf("? %d %d %d %d\n", sx, mid, ex, ey);
		fflush(stdout);
		int cnt;
		scanf("%d", &cnt);
		if (cnt == 1)
		{
			upper = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	lo = sy, hi = ey; int lower = ey;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		printf("? %d %d %d %d\n", sx, sy, ex, mid);
		fflush(stdout);
		int cnt;
		scanf("%d", &cnt);
		if (cnt == 1)
		{
			lower = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	lo = sx, hi = ex; int left = sx;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		printf("? %d %d %d %d\n", mid, sy, ex, ey);
		fflush(stdout);
		int cnt;
		scanf("%d", &cnt);
		if (cnt == 1)
		{
			left = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	lo = sx, hi = ex; int right = ex;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		printf("? %d %d %d %d\n", sx, sy, mid, ey);
		fflush(stdout);
		int cnt;
		scanf("%d", &cnt);
		if (cnt == 1)
		{
			right = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	ret.push_back({ left, upper, right, lower });
	return true;
}

int main()
{
	scanf("%d", &n);

	int lo = 1, hi = n;

	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		printf("? 1 1 %d %d\n", mid, n);
		fflush(stdout);
		int cnt;
		scanf("%d", &cnt);
		if (cnt == 1)
		{
			getans(1, 1, mid, n);
			break;
		}
		else if (cnt == 0)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	if (ret.empty())
	{
		lo = 1, hi = n;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			printf("? 1 1 %d %d\n", n, mid);
			fflush(stdout);
			int cnt;
			scanf("%d", &cnt);
			if (cnt == 1)
			{
				getans(1, 1, n, mid);
				break;
			}
			else if (cnt == 0)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
	}

	getans(1, 1, ret[0][0] - 1, n) ||
		getans(1, 1, n, ret[0][1] - 1) ||
		getans(ret[0][2] + 1, 1, n, n) ||
		getans(1, ret[0][3] + 1, n, n);

	printf("! %d %d %d %d %d %d %d %d\n",
		ret[0][0], ret[0][1], ret[0][2], ret[0][3],
		ret[1][0], ret[1][1], ret[1][2], ret[1][3]
		);
	fflush(stdout);
}