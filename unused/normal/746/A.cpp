#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1;; i++)
	{
		if (i * 1 > a || i * 2 > b || i * 4 > c)
		{
			printf("%d", (i - 1) * 7);
			return 0;
		}
	}
}