#include <iostream>
#include <cstdio>
using namespace std;

const int MaxL = 100000;
const int NLet = 26;

int tr_n;
int tr[MaxL + 2][NLet];

int main()
{
	tr_n = 1;
	int n, nK;
	cin >> n >> nK;
	for (int i = 0; i < n; i++)
	{
		static char str[MaxL + 1];
		scanf("%s", str);

		int p = 1;
		for (int k = 0; str[k]; k++)
		{
			int c = str[k] - 'a';
			if (!tr[p][c])
				tr[p][c] = ++tr_n;
			p = tr[p][c];
		}
	}

	static bool f[MaxL + 1], g[MaxL + 1];
	for (int v = tr_n; v >= 1; v--)
	{
		f[v] = false;
		for (int c = 0; c < NLet; c++)
			if (tr[v][c] && !f[tr[v][c]])
				f[v] = true;

		bool hasSon = false;
		for (int c = 0; c < NLet; c++)
			if (tr[v][c])
				hasSon = true;
		if (!hasSon)
			g[v] = true;
		else
		{
			g[v] = false;
			for (int c = 0; c < NLet; c++)
				if (tr[v][c] && !g[tr[v][c]])
					g[v] = true;
		}
	}

	bool res;
	if (!f[1])
		res = false;
	else if (g[1])
		res = true;
	else
		res = nK % 2 == 1;

	if (res)
		cout << "First" << endl;
	else
		cout << "Second" << endl;

	return 0;
}