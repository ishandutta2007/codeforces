#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int h1, h2;
int h, a, b;

int main()
{
	cin >> h1 >> h2 >> a >> b;
	h = h2 - h1 - 8 * a;
	h = max(h, 0);
	a = 12 * (a - b);
	if (h == 0)
		printf("0\n");
	else if (a <= 0)
		printf("-1\n");
	else
		printf("%d\n", (h + a - 1) / a);

	return 0;
}