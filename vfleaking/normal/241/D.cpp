#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 50000;
const int MaxP = 50000;

const int L = 32;

int main()
{
	int n, p;
	int len = 0;
	static int a[L];
	static int id[L];
	static int mul[L];
	
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t < L)
		{
			a[len] = t;
			id[len] = i;
			for (mul[len] = 1; mul[len] <= t; mul[len] *= 10);
			len++;
		}
	}
	
	n = len;
	
	static bool f[L][L][MaxP];
	for (int i = 0; i < n - 1; i++)
	{
		f[i][a[i]][a[i] % p] = true;
		for (int j = 0; j < L; j++)
			for (int k = 0; k < p; k++)
				if (f[i][j][k])
				{
					f[i + 1][j ^ a[i + 1]][(k * mul[i + 1] + a[i + 1]) % p] = true;
					f[i + 1][j][k] = true;
				}
	}
	
	if (!f[n - 1][0][0])
	{
		puts("No");
		return 0;
	}
	else
	{
		int resLen = 0;
		static int res[L];
		
		int pj = 0, pk = 0;
		for (int i = n - 1; i >= 1; i--)
		{
			if (f[i - 1][pj][pk])
				continue;
			
			if (pj == a[i] && pk == a[i] % p)
			{
				pj = pk = 0;
				res[resLen++] = id[i];
				break;
			}
			else
			{
				pj ^= a[i];
				for (int k = 0; k < p; k++)
					if ((k * mul[i] + a[i]) % p == pk && f[i - 1][pj][k])
					{
						pk = k;
						break;
					}
				res[resLen++] = id[i];
			}
		}
		if (pj != 0)
			res[resLen++] = id[0];
		
		puts("Yes");
		cout << resLen << endl;
		for (int i = 0; i < resLen; i++)
			printf("%d ", res[i]);
		cout << endl;
	}
	
	return 0;
}