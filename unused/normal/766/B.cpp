#include <bits/stdc++.h>
using namespace std;

int dat[100005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);
	sort(dat, dat + n);
	for (int i = 2; i < n; i++)
	{
		if (dat[i-2] + dat[i-1] > dat[i])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}