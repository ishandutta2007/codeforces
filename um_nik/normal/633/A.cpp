#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int x, y, z;

int main()
{
	scanf("%d%d%d", &x, &y, &z);
	for (int i = 0; i * x <= z; i++)
	{
		if ((z - i * x) % y == 0)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}