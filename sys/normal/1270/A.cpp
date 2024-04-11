#include <bits/stdc++.h>
using namespace std;
int t, k, a, b, maxi1, maxi2; 
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		maxi1 = maxi2 = 0;
		scanf("%d%d%d", &k, &a, &b);
		for (int i = 1; i <= a; i++)
		{
			int x;
			scanf("%d", &x);
			maxi1 = max(maxi1, x);
		}
		for (int i = 1; i <= b; i++)
		{
			int x;
			scanf("%d", &x);
			maxi2 = max(maxi2, x);
		}
		if (maxi1 < maxi2) puts("NO");
		else puts("YES");
	}
	return 0;
}