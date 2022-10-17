#include<bits/stdc++.h>
using namespace std;
int t, n, a[30];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int z = 0;
		for (int i = n - 2; i >= 0; i--)
		{
			if (a[i + 1] == 0)
			{
				z = -1;
				break;
			}
			while (a[i] >= a[i + 1])
			{
				a[i] /= 2;
				z++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}