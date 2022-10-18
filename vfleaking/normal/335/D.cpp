#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int L = 3000;

int main()
{
	static int a[L + 2][L + 2];
	static int s[L + 1][L + 1];
	static int fR[L + 1][L + 1];
	static int fD[L + 1][L + 1];

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1,&x2, &y2);
		for (int x = x1 + 1; x <= x2; x++)
			for (int y = y1 + 1; y <= y2; y++)
				a[x][y] = i;
	}

	for (int x = 1; x <= L; x++)
		for (int y = 1; y <= L; y++)
			s[x][y] = (a[x][y] == 0) + s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1];

	for (int x = L; x >= 0; x--)
		for (int y = L; y >= 0; y--)
		{
			fR[x][y] = a[x][y + 1] == a[x + 1][y + 1] ? 0 : fR[x][y + 1] + 1;
			fD[x][y] = a[x + 1][y] == a[x + 1][y + 1] ? 0 : fD[x + 1][y] + 1;
		}

	for (int sx = 0; sx < L; sx++)
		for (int sy = 0; sy < L; sy++)
			for (int l = 1; l <= fR[sx][sy] && l <= fD[sx][sy] && s[sx + l][sy + l] - s[sx + l][sy] - s[sx][sy + l] + s[sx][sy] == 0; l++)
				if (fR[sx + l][sy] >= l && fD[sx][sy + l] >= l)
				{
					vector<int> li;
					for (int x = sx + 1; x <= sx + l; x++)
						for (int y = sy + 1; y <= sy + l; y++)
							li.push_back(a[x][y]);
					sort(li.begin(), li.end()), li.erase(unique(li.begin(), li.end()), li.end());
					printf("YES %d\n", (int)li.size());
					for (int i = 0; i < (int)li.size(); i++)
						printf("%d ", li[i]);
					printf("\n");
					return 0;
				}

	printf("NO\n");

	return 0;
}