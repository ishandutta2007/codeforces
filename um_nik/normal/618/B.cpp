#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 60;
int n;
int a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			a[i] = max(a[i], x);
		}
	}
	for (int i = 0; i < n; i++)
		if (a[i] == n - 1)
		{
			a[i] = n;
			break;
		}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}