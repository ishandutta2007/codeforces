#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	static int p[MaxN + 1];

	cin >> n;

	if ((n / 2) % 2 != 0)
		cout << "-1" << endl;
	else
	{
		for (int i = 1; i <= n - i + 1; i += 2)
		{
			if (i == n - i + 1)
				p[i] = i;
			else
			{
				p[i] = i + 1;
				p[i + 1] = n - i + 1;
				p[n - i + 1] = n - i;
				p[n - i] = i;
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", p[i]);
		cout << endl;
	}

	return 0;
}