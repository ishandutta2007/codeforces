#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int l[4], r[4];
int a[4];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
		scanf("%d%d", &l[i], &r[i]);
	if (r[0] + l[1] + l[2] <= n)
	{
		a[0] = r[0];
		n -= r[0];
		if (l[2] + r[1] <= n)
		{
			a[1] = r[1];
			a[2] = n - r[1];
		}
		else
		{
			a[2] = l[2];
			a[1] = n - l[2];
		}
	}
	else
	{
		a[1] = l[1];
		a[2] = l[2];
		a[0] = n - l[1] - l[2];
	}
	for (int i = 0; i < 3; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}