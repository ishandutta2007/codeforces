#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, x[Maxn], pos[Maxn], p[Maxn];
set <int> Se;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
	{
		char ch = getchar();
		while (ch != '+' && ch != '-') ch = getchar();
		if (ch == '-')
		{
			scanf("%d", &x[i]);
			pos[x[i]] = i;
		}
		else Se.insert(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!pos[i]) continue;
		set <int> :: iterator it = Se.lower_bound(pos[i]);
		if (it == Se.begin())
		{
			puts("NO");
			return 0;
		}
		it--;
		p[*it] = i;
		Se.erase(*it);
	}
	Se.clear();
	for (int i = 1; i <= 2 * n; i++)
	{
		if (x[i])
		{
			if (*Se.begin() != x[i])
			{
				puts("NO");
				return 0;
			}
			Se.erase(Se.begin());
		}
		else
		{
			if (!p[i])
			{
				puts("NO");
				return 0;
			}
			Se.insert(p[i]);
		}
	}
	puts("YES");
	for (int i = 1; i <= 2 * n; i++)
		if (p[i]) printf("%d ", p[i]);
	return 0;
}