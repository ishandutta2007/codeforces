#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int y;

bool isLeap(int x)
{
	if (x % 400 == 0) return true;
	if (x % 100 == 0) return false;
	if (x % 4 == 0) return true;
	return false;
}

int main()
{
	cin >> y;
	int x = y;
	int z = 0;
	while(true)
	{
		z++;
		if (isLeap(x)) z++;
		z %= 7;
		x++;
		if (z == 0)
		{
			if (isLeap(x) ^ isLeap(y) ^ 1)
				break;
		}
	}
	printf("%d\n", x);

	return 0;
}