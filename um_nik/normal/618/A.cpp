#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int x;
	scanf("%d", &x);
	for (int i = 1 << 20, k = 21; i > 0; i >>= 1, k--)
	{
		if (x >= i)
		{
			printf("%d ", k);
			x -= i;
		}
	}
	printf("\n");

	return 0;
}