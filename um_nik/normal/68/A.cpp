#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int x;
	int l, r;
	x = 10000000;
	for (int i = 0; i < 4; i++)
	{
		int y;
		scanf("%d", &y);
		x = min(x, y);
	}
	scanf("%d%d", &l, &r);
	r = min(r, x - 1);
	int ans = r - l + 1;
	printf("%d\n", max(ans, 0));

	return 0;
}