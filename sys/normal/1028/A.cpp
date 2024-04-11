#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;
int n, m, A, B;
string str[Maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
		int s = -1, t = -1;
		for (int j = 0; j < (int) str[i].size(); j++)
		{
			if (str[i][j] == 'B' && s == -1) s = j;
			if (str[i][j] == 'B') t = j;
		}
		if (s != -1) B = (s + t) / 2 + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int s = -1, t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (str[j][i] == 'B' && s == -1) s = j;
			if (str[j][i] == 'B') t = j;
		}
		if (s != -1) A = (s + t) / 2;
	}
	printf("%d %d", A, B);
	return 0;
}