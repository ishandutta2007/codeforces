#include <bits/stdc++.h>
using namespace std;
int t, n, a[320];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				printf("%d%c", j == 1 || j == i, j == i ? '\n' : ' ');
			}
		}
	}
	return 0;
}