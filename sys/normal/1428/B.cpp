#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, fa[Maxn], siz[Maxn];
string str;
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[a] = b;
	if (a != b) siz[b] += siz[a];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool flag1 = false, flag2 = false;
		scanf("%d", &n);
		cin >> str;
		for (int i = 0; i < n; i++)
			if (str[i] == '<') flag1 = true;
			else if (str[i] == '>') flag2 = true;
		if (!(flag1 && flag2))
		{
			printf("%d\n", n);
			continue;
		}
		for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
		for (int i = 0; i < n; i++)
			if (str[i] == '-') merge(i + 1, (i + 1) % n + 1);
		int ans = n;
		for (int i = 1; i <= n; i++)
			if (get_fa(i) == i && siz[i] == 1) ans--;
		printf("%d\n", ans);
	}
	return 0;
}