#include <bits/stdc++.h>
using namespace std;

int T, n, a[105];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int maxi = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				double d = (a[j] - a[i]) / (double) (j - i);
				double s = a[i] - d * (i - 1);
				int ans = 0;
				for (int k = 1; k <= n; k++)
					if (abs(a[k] - (s + (k - 1) * d)) <= 1e-6) ans++;
				maxi = max(maxi, ans);
			}
		printf("%d\n", n - maxi);
	}
	return 0;
}