#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 10000;

int n;
bool mat[MaxN + 1][MaxN + 1];

void go(int sV, int tV, int nK, int len)
{
	if (nK % 2 == 1)
	{
		int last = sV;
		for (int i = 0; i < len; i++)
			mat[last][++n] = true, last = n;
		mat[last][tV] = true;

		nK--;
	}

	if (nK == 0)
		return;
	
	n++;
	mat[sV][n] = true;
	n++;
	mat[sV][n] = true;
	n++;
	mat[n - 2][n] = true;
	mat[n - 1][n] = true;
	go(n, tV, nK >> 1, len - 2);
}

int main()
{
	int nK;
	cin >> nK;

	n = 2;

	go(1, 2, nK, 59);

	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			if (mat[v][u])
				mat[u][v] = true;

	cout << n << endl;
	for (int v = 1; v <= n; v++)
	{
		for (int u = 1; u <= n; u++)
			putchar(mat[v][u] ? 'Y' : 'N');
		putchar('\n');
	}

	return 0;
}