#include <bits/stdc++.h>
using namespace std;

int dat[101];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);

	sort(dat, dat + n);
	int a1 = 0, a2 = 0;
	int now = 10;
	for (int i = 0; i < n; i++)
	{
		now += dat[i];
		if (now > 720) break;
		++a1;
		a2 += max(0, now - 360);
	}
	printf("%d %d\n", a1, a2);
}