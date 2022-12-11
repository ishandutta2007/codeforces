#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> row[100005];
pair<int, int> column[100005];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) row[b] = { c, i };
		else column[b] = { c, i };
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (row[i].second < column[j].second) printf("%d ", column[j].first);
			else printf("%d ", row[i].first);
		}
		printf("\n");
	}
}