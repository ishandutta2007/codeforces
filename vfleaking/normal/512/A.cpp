#include <iostream>
#include <cstdio>
using namespace std;

const int NLet = 26;

const int MaxN = 100;
const int MaxL = 100;

int main()
{
	int n;
	static char s[MaxN][MaxL + 1];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);

	static bool f[NLet][NLet];

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int k;
			for (k = 0; s[i][k] && s[j][k]; k++)
				if (s[i][k] != s[j][k])
				{
					f[s[i][k] - 'a'][s[j][k] - 'a'] = true;
					break;
				}
			if (!s[j][k])
			{
				puts("Impossible");
				return 0;
			}
		}

	static int deg[NLet];
	for (int i = 0; i < NLet; i++)
		for (int j = 0; j < NLet; j++)
			if (f[i][j])
				deg[j]++;

	int q_n = 0;
	static int q[NLet];
	for (int i = 0; i < NLet; i++)
		if (deg[i] == 0)
			q[q_n++] = i;

	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		for (int u = 0; u < NLet; u++)
			if (f[v][u] && --deg[u] == 0)
				q[q_n++] = u;
	}

	if (q_n != NLet)
	{
		puts("Impossible");
		return 0;
	}

	for (int i = 0; i < q_n; i++)
		putchar('a' + q[i]);
	putchar('\n');

	return 0;
}