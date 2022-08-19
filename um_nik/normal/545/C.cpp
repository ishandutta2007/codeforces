#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int a[N], h[N];
int x;
int ans;
int n;

int main()
{
	x = -((int)1e9);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &h[i]);
	for (int i = 0; i < n; i++)
	{
		if (x <= a[i] - h[i])
		{
			x = a[i] + 1;
			ans++;
			continue;
		}
		x = a[i] + 1;
		if (i == n - 1 || a[i] + h[i] < a[i + 1])
		{
			x = a[i] + h[i] + 1;
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}