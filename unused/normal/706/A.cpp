#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int t;
	scanf("%d", &t);
	double ans = 1e100;
	while (t--)
	{
		int c, d,e;
		scanf("%d%d%d", &c, &d, &e);
		ans = min(ans, hypot(c - a, b - d) / e);
	}
	printf("%.9f", ans);
}