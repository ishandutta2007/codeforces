#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int N = 111;
const int M = (int)1e4 + 3;
int n;
int m;
int ans[M][N];
int a[N];
pii b[N];

bool ended()
{
	for (int i = 0; i < n; i++)
		if (a[0] != a[i])
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while(!ended())
	{
		for (int i = 0; i < n; i++)
			b[i] = mp(a[i], i);
		sort(b, b + n);
		reverse(b, b + n);
		int p = 1;
		while(p < n && (p < 2 || b[p].first == b[0].first)) p++;
		if (p % 2 == 0)
		{
			for (int i = 0; i < p; i += 2)
			{
				ans[m][b[i].second] = ans[m][b[i + 1].second] = 1;
				m++;
			}
		}
		else
		{
			ans[m][b[0].second] = ans[m][b[1].second] = ans[m][b[2].second] = 1;
			m++;
			for (int i = 3; i < p; i += 2)
			{
				ans[m][b[i].second] = ans[m][b[i + 1].second] = 1;
				m++;
			}
		}
		for (int i = 0; i < p; i++)
		{
			int q = b[i].second;
			a[q] = max(0, a[q] - 1);
		}
	}
	printf("%d\n", a[0]);
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d", ans[i][j]);
		printf("\n");
	}

	return 0;
}