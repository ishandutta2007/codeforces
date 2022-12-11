#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int x, y, xx, yy;

int main()
{
	scanf("%d%d%d%d", &x, &y, &xx, &yy);
	if (x <= xx && y <= yy)
	{
		printf("Polycarp\n");
		return 0;
	}
	if (x + y <= max(xx, yy))
	{
		printf("Polycarp\n");
		return 0;
	}
	printf("Vasiliy\n");

	return 0;
}