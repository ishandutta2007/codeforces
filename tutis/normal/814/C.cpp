/**
15
yamatonadeshiko
10
1 a
2 a
3 a
4 a
5 a
1 b
2 b
3 b
4 b
5 b
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int q;
	cin >> q;
	int D[n + 1][n + 1][27];
	for (int M = 0; M <= n; M++)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j < 27; j++)
				D[M][i][j] = 0;
		}
	}
	//M=0;
	D[0][0][(int)(s[0] - 'a')] = 1;
	for (int i = 1; i < n; i++)
	{
		D[0][i][(int)(s[i] - 'a')] = max(1, 1 + D[0][i - 1][(int)(s[i] - 'a')]);
	}
	for (int M = 1; M <= n; M++)
	{
		for (char x = 'a'; x <= 'z'; x++)
		{
			D[M][0][(int)(x - 'a')] = 1;
			for (int i = 1; i < n; i++)
			{
				if (s[i] != x)
					D[M][i][(int)(x - 'a')] = 1 + D[M - 1][i - 1][(int)(x - 'a')];
				if (s[i] == x)
					D[M][i][(int)(x - 'a')] = 1 + D[M][i - 1][(int)(x - 'a')];
			}
		}
	}
	int A[n + 1][27];
	for (int M = 1; M <= n; M++)
	{
		for (int x = 0; x < 27; x++)
		{
			int ats = 0;
			for (int i = 0; i < n; i++)
			{
				ats = max(ats, D[M][i][x]);
			}
			A[M][x] = ats;
		}
	}
	while (q--)
	{
		int m;
		char c;
		cin >> m >> c;
		cout << A[m][(int)(c - 'a')] << '\n';
	}
	return 0;
}