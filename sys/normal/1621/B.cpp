#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int mini = INT_MAX, maxi = 0, c1 = 0, c2 = 0, c3 = INT_MAX;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int l, r, c;
			scanf("%d%d%d", &l, &r, &c);
			if (l < mini) mini = l, c1 = c, c3 = INT_MAX;
			else if (l == mini) c1 = min(c1, c);
			if (r > maxi) maxi = r, c2 = c, c3 = INT_MAX;
			else if (r == maxi) c2 = min(c2, c);
			if (l == mini && r == maxi) c3 = min(c3, c);
			printf("%d\n", min(c1 + c2, c3));
		}
	}
	return 0;
}