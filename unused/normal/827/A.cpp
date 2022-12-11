#include <bits/stdc++.h>
using namespace std;

char str[1000005];
char ans[3000005];
int p[3000005];

int getp(int t)
{
	return p[t] == t ? t : p[t] = getp(p[t]);
}

void mg(int a, int b)
{
	a = getp(a); b = getp(b);
	p[min(a, b)] = max(a, b);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= 3000000; i++) p[i] = i;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%s%d", str, &x);
		int len = strlen(str);

		while (x--)
		{
			int idx;
			scanf("%d", &idx);
			--idx;

			int z = getp(idx);
			while (z < idx + len)
			{
				ans[z] = str[z - idx];
				mg(z, z + 1);
				z = getp(z);
			}
		}
	}

	int endp = 3000000;
	while (ans[endp] == 0) --endp;
	while (endp >= 0)
	{
		if (ans[endp] == 0) ans[endp] = 'a';
		--endp;
	}

	puts(ans);
}