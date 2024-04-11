#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
int n, m, a, b;
int A[N];
int Check(int x)
{
	if (b - a <= x)
		return 0;
	int t = 0;
	for (int i = 1; i <= x; i++)
		t = max(t, x - i + A[i]);
	return t < b - 1;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &m, &a, &b);
		if (a > b)
			a = n - a + 1, b = n - b + 1;
		for (int i = 1; i <= m; i++)
			scanf("%d", &A[i]);
		sort(A + 1, A + m + 1);
		int l = 0, r = m;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (Check(mid))
				l = mid;
			else
				r = mid - 1;
		}
		printf("%d\n", l);
	}
}