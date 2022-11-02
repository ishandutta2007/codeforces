#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

#define N 2000

int val, id[N], c[N];
bool z[N], ot[N];
char s[N * 100];

bool comp(int a, int b)
{
	return c[a] < c[b];
}

int main()
{
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	scanf("%d\n", &val);
	int n = 0;
	gets(s);
	for (int i = 0; i < N; i++)
		c[i] = N;
	if (s[0] == '-')
		ot[0] = true;
	for (int i = 0; i < strlen(s);)
	{
		id[n] = n;
		if (isdigit(s[i]))
		{
			c[n] = 0;
			while (isdigit(s[i]))
			{
				c[n] = c[n] * 10 + s[i] - '0';
				i++;
			}
			i++;
		}
		if (c[n] == N) c[n] = 1;
		if (ot[n])
			c[n] = -c[n];
		z[n++] = s[i] == '+';
		i += 3;
		if (s[i] == '-')
			ot[n] = true;
		else ot[n] = false;
		i++;
	}
	std::sort(id, id + n, comp);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (z[id[i]])
			val++;
		ans += c[id[i]] * val;
		if (!z[id[i]])
			val++;
	}
	printf("%d", ans);
}