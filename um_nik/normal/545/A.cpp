#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;
int n;
bool b[N];
int m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		b[i] = 1;
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			if (x == 1 || x == 3)
				b[i] = 0;
		}
		if (b[i]) m++;
	}
	printf("%d\n", m);
	for (int i = 0; i < n; i++)
		if (b[i])
			printf("%d ", i + 1);
	printf("\n");

	return 0;
}