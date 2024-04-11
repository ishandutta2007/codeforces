#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 20000;

int main()
{
	int n, m, ct;
	static int a[MaxN + 1];

	cin >> n >> m >> ct;
	for (int i = 1; i <= n; i++)
	{
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		a[i] = (hh * 60 + mm) * 60 + ss;
	}
	
	bool ok = false;
	int nC = 0;
	static int col[MaxN + 1];
	static int cnt[MaxN + 1];
	for (int i = 1, j = 1, tot_c = 0; i <= n; i++)
	{
		while (a[j] <= a[i] - ct)
		{
			if (--cnt[col[j]] == 0)
				tot_c--;
			j++;
		}
		if (tot_c < m)
			col[i] = ++nC;
		else
			col[i] = col[i - 1];
		if (cnt[col[i]]++ == 0)
			tot_c++;
		ok = ok || tot_c == m;
	}

	if (!ok)
		printf("No solution\n");
	else
	{
		printf("%d\n", nC);
		for (int i = 1; i <= n; i++)
			printf("%d\n", col[i]);
	}

	return 0;
}