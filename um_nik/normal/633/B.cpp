#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int m, n;
int ans[20];

int main()
{
	scanf("%d", &m);
	int x = 0;
	for (int i = 1; x <= m; i++)
	{
		int y = i;
		while(y % 5 == 0)
		{
			x++;
			y /= 5;
		}
		if (x == m)
			ans[n++] = i;
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}