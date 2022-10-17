#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[500020];
int c[3][500020];
void change(int x, int y)
{
	for (int i = x; i <= m; i += i & -i)
	{
		c[x % 3][i] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[x % 3][i];
	}
	return re;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		m = 2 * n + 2;
		for (int i = 0; i <= m; i++)
		{
			c[0][i] = 0;
			c[1][i] = 0;
			c[2][i] = 0;
		}
		scanf("%s", s);
		int t = n + 1;
		change(t, 1);
		long long z = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '+')
			{
				t--;
			}
			else
			{
				t++;
			}
			z += query(t);
			change(t, 1);
		}
		cout << z << endl;
	}
	return 0;
}