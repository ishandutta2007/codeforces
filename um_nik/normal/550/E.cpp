#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e6 + 10;
int n;
int a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (a[n - 1])
	{
		printf("NO\n");
		return 0;
	}
	if (n == 1)
	{
		printf("YES\n");
		printf("0\n");
		return 0;
	}
	if (a[n - 2])
	{
		printf("YES\n");
		for (int i = 0; i < n - 1; i++)
			printf("%d->", a[i]);
		printf("%d\n", a[n - 1]);
		return 0;
	}
	if (n == 2)
	{
		printf("NO\n");
		return 0;
	}
	if (a[n - 3] == 0)
	{
		printf("YES\n");
		for (int i = 0; i < n - 3; i++)
			printf("%d->", a[i]);
		printf("(0->0)->0\n");
		return 0;
	}
	int idx = n - 3;
	while(idx >= 0 && a[idx]) idx--;
	if (idx == -1)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < idx; i++)
		printf("%d->", a[i]);
	printf("(0->(");
	for (int i = idx + 1; i < n - 2; i++)
		printf("%d->", a[i]);
	printf("0))->0\n");

	return 0;
}