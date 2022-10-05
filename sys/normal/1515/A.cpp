#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int T, n, x, w[Maxn];
int main()
{
	srand(time(NULL));
	scanf("%d", &T);
	while (T--)
	{
		w[0] = 0;
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]), w[0] += w[i];
		if (w[0] == x)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		while (true)
		{
			int sum;
			END:sum = 0;
			random_shuffle(w + 1, w + 1 + n);
			for (int i = 1; i <= n; i++)
			{
				sum += w[i];
				if (sum == x) goto END;
			}
			for (int i = 1; i <= n; i++)
				printf("%d ", w[i]);
			puts("");
			break;
		}
	}
	return 0;
}