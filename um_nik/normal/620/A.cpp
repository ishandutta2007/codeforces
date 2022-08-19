#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int x, y, xx, yy;
	scanf("%d%d%d%d", &x, &y, &xx, &yy);
	printf("%d\n", max(abs(x - xx), abs(y - yy)));

	return 0;
}