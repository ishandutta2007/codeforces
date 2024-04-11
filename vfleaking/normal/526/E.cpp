#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 1000000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int main()
{
	int n, q;
	static int a[MaxN + MaxN];
	static s64 sum[MaxN + MaxN + 1];

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	copy(a, a + n, a + n);

	for (int i = 0; i < n * 2; i++)
		sum[i + 1] = sum[i] + a[i];

	while (q--)
	{
		s64 b;
		cin >> b;

		static int next[MaxN];
		static int goal[MaxN];
		static int steps[MaxN];
		for (int i = 0, j = 0; i < n; i++)
		{
			while (j < n * 2 && sum[j + 1] - sum[i] <= b)
				j++;
			next[i] = j;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (next[i] >= n)
				goal[i] = i, steps[i] = 1;
			else
				goal[i] = goal[next[i]], steps[i] = steps[next[i]] + 1;
		}
		int res = n;
		for (int i = 0; i < n; i++)
			if (next[i] >= n)
			{
				int p = next[i] - n;
				if (p == n)
					tension(res, 1);
				else
					tension(res, steps[p] + (goal[p] < i));
			}
		printf("%d\n", res);
	}

	return 0;
}