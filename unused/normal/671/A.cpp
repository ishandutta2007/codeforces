#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, int> dat[100005];
pair<double, int> a[100005], b[100005];

double dist(int x, int y, int z, int w)
{
	return sqrt((long long)(x - z)*(x - z) + (long long)(y - w)*(y - w));
}

int main()
{
	int ax, ay, bx, by, tx, ty, n;
	scanf("%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty, &n);
	double total = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &dat[i].first, &dat[i].second);
		total += dist(tx, ty, dat[i].first, dat[i].second) * 2;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = {
			-dist(tx, ty, dat[i].first, dat[i].second) + dist(ax, ay, dat[i].first, dat[i].second),
			i
		};
	}

	for (int i = 0; i < n; i++)
	{
		b[i] = {
			-dist(tx, ty, dat[i].first, dat[i].second) + dist(bx, by, dat[i].first, dat[i].second),
			i
		};
	}

	a[n] = b[n] = { 0, -1 };

	sort(a, a + n + 1);
	sort(b, b + n + 1);

	if (a[0].second != b[0].second)
	{
		if (a[0].first <= 0 && b[0].first <= 0) printf("%.9f\n", total + a[0].first + b[0].first);
		else printf("%.9f\n", total + min(a[0].first, b[0].first));
	}
	else
	{
		if (a[0].second == -1)
		{
			printf("%.9f\n", total + min(a[1].first, b[1].first));
		}
		else if (a[0].first >= 0 || b[0].first >= 0)
		{
			printf("%.9f\n", total + min(a[0].first, b[0].first));
		}
		else
		{
			double foo = a[0].first;
			foo = min(foo, a[0].first + (b[1].second == -1 ? b[2].first : b[1].first));
			foo = min(foo, (a[1].second == -1 ? a[2].first : a[1].first) + b[0].first);
			foo = min(foo, b[0].first);
			printf("%.9f\n", total + foo);
		}
	}
}