#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n == 1 || n == 2)
	{
		printf("1\n");
		printf("1\n");
		return 0;
	}
	if (n == 3)
	{
		printf("2\n");
		printf("1 3\n");
		return 0;
	}
	printf("%d\n", n);
	for (int i = n - 1; i > 0; i -= 2)
		printf("%d ", i);
	for (int i = n; i > 0; i -= 2)
		printf("%d ", i);
	printf("\n");

	return 0;
}