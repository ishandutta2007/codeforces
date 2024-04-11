#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 3030;
int n, p, s;

struct Item
{
	int id, a, b;

	Item() : id(), a(), b() {}

	bool operator < (const Item &I) const
	{
		return a - b > I.a - I.b;
	}
};

Item a[N];
int dp1[N][N];
int dp2[N][N];
int par1[N][N];
int par2[N][N];

void restoreAns(int pos)
{
	int p1 = pos, p2 = pos;
	int x = p, y = s;
	while(p1 > 0)
	{
		int z = par1[p1][x];
		p1--;
		x -= z;
		if (z)
			printf("%d ", a[p1].id);
	}
	printf("\n");
	while(p2 < n)
	{
		int z = par2[p2][y];
		if (z)
			printf("%d ", a[p2].id);
		p2++;
		y -= z;
	}
	printf("\n");
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &p, &s);
	for (int i = 0; i < n; i++)
		a[i].id = i + 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].a);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].b);
	sort(a, a + n);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp1[i][j] = dp2[i][j] = -1;
	dp1[0][0] = 0;
	dp2[n][0] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (dp1[i + 1][j] < dp1[i][j])
			{
				dp1[i + 1][j] = dp1[i][j];
				par1[i + 1][j] = 0;
			}
			if (dp1[i + 1][j + 1] < dp1[i][j] + a[i].a)
			{
				dp1[i + 1][j + 1] = dp1[i][j] + a[i].a;
				par1[i + 1][j + 1] = 1;
			}
		}
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j + i < n; j++)
		{
			if (dp2[i][j] < dp2[i + 1][j])
			{
				dp2[i][j] = dp2[i + 1][j];
				par2[i][j] = 0;
			}
			if (dp2[i][j + 1] < dp2[i + 1][j] + a[i].b)
			{
				dp2[i][j + 1] = dp2[i + 1][j] + a[i].b;
				par2[i][j + 1] = 1;
			}
		}

	int bst = -1, maxVal = -1;
	for (int i = p; i + s <= n; i++)
	{
		if (dp1[i][p] + dp2[i][s] > maxVal)
		{
			maxVal = dp1[i][p] + dp2[i][s];
			bst = i;
		}
	}
	printf("%d\n", maxVal);
	restoreAns(bst);

	return 0;
}