#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n / 2);
	for (int i = 1; i < n / 2; i++)
		printf("2 ");
	printf("%d\n", 2 + (n & 1));

	return 0;
}