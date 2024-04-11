#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 2000;
int a[N];
int n, r, t;
int b[N];
const int T = 630;
int ans = T;

bool check()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = a[i] - t; j < a[i]; j++)
			cnt += b[j];
		if (cnt < r)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d", &n, &t, &r);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i] += 300;
	}
	for (int i = 0; i < T; i++)
		b[i] = 1;
	if (!check())
	{
		printf("-1\n");
		return 0;
	}
	for (int i = T - 1; i >= 0; i--)
	{
		b[i] = 0;
		if (!check())
			b[i] = 1;
		ans -= (1 - b[i]);
	}
	printf("%d\n", ans);

	return 0;
}