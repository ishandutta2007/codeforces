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

#define MAXN 555555

using namespace std;

struct Point
{
	int x, y, z;
};

int tmax[MAXN], n, res = 0;
pair <int, int> tx[MAXN];
Point a[MAXN];

bool cmp(Point x, Point y)
{
	return ((x.z > y.z) || 
		(x.z == y.z && x.x > y.x) || 
		(x.z == y.z && x.x == y.x && x.y < y.y));
}

int fmax(int x)
{
	int res = 0;
	while (x)
		{
			res = max(res, tmax[x]);
			x &= x-1;
		}
	return res;
}

void modify(int x, int y)
{
	while (x <= n+1)
		{
			tmax[x] = max(tmax[x], y);
			x = (x | (x-1)) + 1;
		}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i].z);
	for (int i = 0; i < n; i++) 	
		{
			scanf("%d", &a[i].x);		
			tx[i] = make_pair(-a[i].x, i);
		}
	for (int i = 0; i < n; i++) scanf("%d", &a[i].y);
	sort(tx, tx + n);
	int q= 0;
	for (int i = 0; i < n; i++)
		if (!i || tx[i].first != tx[i-1].first)
			a[tx[i].second].x = ++q;
		else a[tx[i].second].x = q;
	sort(a, a + n, cmp);
	memset(tmax, 0, sizeof(tmax));
	for (int i = 0; i < n; i++)
		{
			modify(a[i].x, a[i].y);
			int qw = fmax(a[i].x-1);
			if (qw > a[i].y) res++;
		}
	printf("%d", res);
	return 0;
}