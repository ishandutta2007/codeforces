#include <bits/stdc++.h>
using namespace std;

int dat[105];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}

	int i1 = min_element(dat, dat + n) - dat;
	int i2 = max_element(dat, dat + n) - dat;
	for (int i = i1 + 1; i < n; i++) if (dat[i1] == dat[i]) i1 = i;
	for (int i = i2 - 1; i >= 0; i--) if (dat[i2] == dat[i]) i2 = i;

	if (i1 < i2) printf("%d\n", i2 + n - 2 - i1);
	else printf("%d\n", i2 + n - 1 - i1);
}