#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (b & 1)
		printf("%d\n", b / 2 + 1);
	else
		printf("%d\n", (a - b) / 2 + 1);

	return 0;
}