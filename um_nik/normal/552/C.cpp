#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int x, y;

int main()
{
	cin >> x >> y;
	if (x <= 3)
	{
		printf("YES\n");
		return 0;
	}
	while(y > 0)
	{
		int z = y % x;
		if (z <= 1)
			y /= x;
		else if (z == x - 1)
			y = y / x + 1;
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}