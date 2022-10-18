#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

const int MaxN = 50;

int main()
{
	int n;
	static char a[MaxN + 1][MaxN + 1];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	static char res[MaxN * 2][MaxN * 2];
	for (int x = -n + 1; x <= n - 1; x++)
		for (int y = -n + 1; y <= n - 1; y++)
			res[x + n - 1][y + n - 1] = 'x';
	res[n - 1][n - 1] = 'o';

	for (int x1 = 0; x1 < n; x1++)
		for (int y1 = 0; y1 < n; y1++)
			if (a[x1][y1] == '.')
				for (int x2 = 0; x2 < n; x2++)
					for (int y2 = 0; y2 < n; y2++)
						if (make_pair(x1, y1) != make_pair(x2, y2) && a[x2][y2] == 'o')
							res[x1 - x2 + n - 1][y1 - y2 + n - 1] = '.';
	for (int x1 = 0; x1 < n; x1++)
		for (int y1 = 0; y1 < n; y1++)
			if (a[x1][y1] == 'x')
			{
				bool ok = false;
				for (int x2 = 0; x2 < n; x2++)
					for (int y2 = 0; y2 < n; y2++)
						if (make_pair(x1, y1) != make_pair(x2, y2) && a[x2][y2] == 'o')
							ok = ok || res[x1 - x2 + n - 1][y1 - y2 + n - 1] == 'x';
				if (!ok)
				{
					puts("NO");
					return 0;
				}
			}

	puts("YES");
	for (int x = 0; x < 2 * n - 1; x++)
		puts(res[x]);

	return 0;
}