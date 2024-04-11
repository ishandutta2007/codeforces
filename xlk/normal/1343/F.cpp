#include <bits/stdc++.h>
using namespace std;
int t, n, x;
bitset<201> a[201];
bitset<201> s[201];
bool v[201];
int l[201];
int p[201];
bool gao(int x)
{
	p[1] = x;
	s[1] = s[0];
	s[1][x] = 1;
	memset(v, 0, sizeof v);
	for (int i = 2; i <= n; i++)
	{
		bool find = false;
		for (int j = 1; j < n; j++)
		{
			if (i >= l[j] && !v[j])
			{
				bitset<201>r = (s[i-1] ^ s[i-l[j]] ^ a[j]);
				if (r.count() == 1)
				{
					p[i] = r._Find_first();
					s[i] = s[i - 1];
					s[i][p[i]] = 1;
					v[j] = true;
					find = true;
					break;
				}
			}
		}
		if (!find)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &l[i]);
			a[i].reset();
			for (int j = 0; j < l[i]; j++)
			{
				scanf("%d", &x);
				a[i][x] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (gao(i))
			{
				break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", p[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}