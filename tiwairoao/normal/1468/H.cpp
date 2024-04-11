#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 500005
int n, k, m, A[N], S[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 1; i <= n; i++)
			S[i] = 1;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &A[i]);
			S[A[i]] = 0;
		}
		if ((n - m) % (k - 1))
		{
			puts("NO");
			continue;
		}
		int flg = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!S[i])
			{
				S[i] += S[i - 1];
				if (min(S[i], n - m - S[i]) >= (k - 1) / 2)
					flg = 1;
			}
			else
				S[i] += S[i - 1];
		}
		if (flg)
			puts("YES");
		else
			puts("NO");
	}
}