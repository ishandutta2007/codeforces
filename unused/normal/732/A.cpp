#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (b * j > a * i) break;
			if ((a * i - b * j) % 10 == 0)
			{
				printf("%d", i);
				return 0;
			}
		}
	}
}