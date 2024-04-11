#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	int x = 0, y = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		if (i % 7 == 5 || i % 7 == 6) x++;
		if (i % 7 == 0 || i % 7 == 1) y++;
	}
	printf("%d %d\n", x, y);
	
	return 0;
}