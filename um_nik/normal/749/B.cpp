#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int x[5], y[5];
int sumx, sumy;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		sumx += x[i];
		sumy += y[i];
	}
	printf("3\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d %d\n", sumx - 2 * x[i], sumy - 2 * y[i]);
	}
//	scanf("%d", &x[0]);

	return 0;
}