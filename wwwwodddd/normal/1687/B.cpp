#include <bits/stdc++.h>
using namespace std;
int n, m, x;
pair<int, int> l[520];
int v[520];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		printf("? ");
		for (int j = 0; j < m; j++)
		{
			printf("%d", i == j);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &l[i].first);
		l[i].second = i;
	}
	sort(l, l + m);
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		if (i == 0)
		{
			s += l[i].first;
			v[l[i].second] = 1;
		}
		else
		{
			v[l[i].second] = 1;
			printf("? ");
			for (int j = 0; j < m; j++)
			{
				printf("%d", v[j]);
			}
			printf("\n");
			fflush(stdout);
			scanf("%d", &x);
			if (s + l[i].first > x)
			{
				v[l[i].second] = 0;
			}
			else
			{
				s += l[i].first;
			}
		}
	}
	printf("! %d\n", s);
	fflush(stdout);
	return 0;
}