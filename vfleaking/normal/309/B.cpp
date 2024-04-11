#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 1000000;
const int MaxL = 5000000;

int main()
{
	int n, r, c;
	static char buf[MaxN + MaxL];
	char *pBuf = buf;
	static char *a[MaxN];
	static int sumL[MaxN + 1];

	cin >> n >> r >> c;
	sumL[0] = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = pBuf;
		scanf("%s", a[i]);
		int l = strlen(a[i]);
		sumL[i + 1] = sumL[i] + l;
		pBuf += l + 1;
	}

	static int next[MaxN + 1];
	for (int i = 0, j = 0; i < n; i++)
	{
		if (j < i)
			j = i;
		while (j < n && sumL[j + 1] - sumL[i] + j - i <= c)
			j++;
		next[i] = j;
	}
	next[n] = n;

	static int t[MaxN + 1];
	static int go[MaxN + 1];

	copy(next, next + n + 1, t);
	for (int i = 0; i <= n; i++)
		go[i] = i;
	for (int k = r; k > 0; k >>= 1)
	{
		if (k & 1)
		{
			for (int i = 0; i <= n; i++)
				go[i] = go[t[i]];
		}
		for (int i = 0; i <= n; i++)
			t[i] = t[t[i]];
	}

	int res = 0, resP = 0;
	for (int i = 0; i < n; i++)
		if (go[i] - i > res)
			res = go[i] - i, resP = i;
	
	for (int i = resP; i != go[resP]; i = next[i])
	{
		for (int k = i; k < next[i]; k++)
		{
			printf("%s", a[k]);
			if (k + 1 < next[i])
				putchar(' ');
			else
				putchar('\n');
		}
	}

	return 0;
}