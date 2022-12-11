#include <bits/stdc++.h>
using namespace std;

int dat[100005];

int main()
{
	int n, u;
	scanf("%d%d",&n,&u);
	for (int i = 0; i < n; i++) scanf("%d",&dat[i]);

	double ans = -1;
	for (int i = 0; i < n - 2; i++)
	{
		int j = upper_bound(dat + i + 2, dat + n, dat[i] + u) - dat - 1;
		if (j >= i + 2) ans = max(ans, (dat[j] - dat[i + 1]) / double(dat[j] - dat[i]));
	}
	printf("%.9f\n", ans);
}