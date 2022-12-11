#include <bits/stdc++.h>
using namespace std;

void err()
{
	printf("-1\n");
	exit(0);
}

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	if (c == d)
	{
		if (a < c || b < c || (a <= c && b <= c)) err();

		if (a > c)
		{
			printf("%s", string(a - c, '4').c_str());
			for (int i = 0; i < c - 1; i++) printf("74");
			printf("%s4\n", string(b - c + 1, '7').c_str());
		}
		else
		{
			printf("7%s", string(a - c + 1, '4').c_str());
			for (int i = 0; i < c - 1; i++) printf("74");
			printf("%s\n", string(b - c, '7').c_str());
		}
	}
	else if (c == d + 1)
	{
		if (a < c || b < c) err();
		// 47474747...
		printf("%s", string(a - c + 1, '4').c_str());
		for (int i = 0; i < c - 1; i++) printf("74");
		printf("%s\n", string(b - c + 1, '7').c_str());
	}
	else if (c + 1 == d)
	{
		// 747474...
		if (a < d || b < d) err();
		printf("7%s", string(a - d + 1, '4').c_str());
		for (int i = 0; i < d - 2; i++) printf("74");
		printf("%s4\n", string(b - d + 1, '7').c_str());
	}
	else
	{
		err();
	}
}