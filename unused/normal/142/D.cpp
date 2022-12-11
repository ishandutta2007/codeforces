#include <bits/stdc++.h>
using namespace std;

bool gonly, ronly;
vector<int> vt;
char str[105];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	if (m == 1)
	{
		printf("Second\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int emp = find(str, str + m, '-') - str;
		if (emp == m) continue;

		int gidx = find(str, str + m, 'G') - str;
		int ridx = find(str, str + m, 'R') - str;
		if (gidx == m && ridx == m) continue;
		else if (gidx == m) ronly = true;
		else if (ridx == m) gonly = true;
		else vt.push_back(abs(gidx - ridx) - 1);
	}
	if (gonly && ronly) printf("Draw\n");
	else if (gonly) printf("First\n");
	else if (ronly) printf("Second\n");
	else
	{
		for (int f = 1; f <= 128; f <<= 1)
		{
			int res = 0;
			for (int t : vt)
			{
				if (t & f) res++;
			}
			if (res % (k + 1))
			{
				printf("First\n");
				return 0;
			}
		}
		printf("Second\n");
	}
}