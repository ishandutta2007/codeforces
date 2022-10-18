#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, x;

	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % 2 == 0)
			{
				if (j < n / 2)
					putchar('>');
				else if (j < n - 1)
				{
					if (j % 2 == 0)
						putchar('>');
					else
						putchar('.');
				}
				else
					putchar('v');
			}
			else
			{
				if (j == 0)
					putchar('^');
				else if (j < (n + 1) / 2)
				{
					if (j % 2 == 0)
						putchar('<');
					else
						putchar('.');
				}
				else
					putchar('<');
			}
		}
		putchar('\n');
	}

	cout << 1 << " " << n << endl;

	return 0;
}