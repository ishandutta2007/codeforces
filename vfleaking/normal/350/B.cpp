#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;

inline int getint()
{
	char c;
	while (c = getchar(), '0' > c || c > '9');

	int res = c - '0';
	while (c = getchar(), '0' <= c && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int n;
int verType[MaxN + 1], fa[MaxN + 1];
int deg[MaxN + 1];

int f[MaxN + 1];

int go(const int &v)
{
	if (f[v] == -2)
		return f[v] = 0;
	else if (f[v] != -1)
		return f[v];
	else
	{
		f[v] = -2;
		if (fa[v] != 0 && verType[fa[v]] == 0 && deg[fa[v]] == 1)
			return f[v] = go(fa[v]) + 1;
		else
			return f[v] = 1;
	}
}

int main()
{
	cin >> n;
	for (int v = 1; v <= n; v++)
		verType[v] = getint();
	for (int v = 1; v <= n; v++)
		fa[v] = getint();

	for (int v = 1; v <= n; v++)
		deg[fa[v]]++;

	for (int v = 1; v <= n; v++)
		f[v] = -1;
	for (int v = 1; v <= n; v++)
		go(v);

	int resEndV = -1;
	int resLen = 0;
	for (int endV = 1; endV <= n; endV++)
		if (verType[endV] == 1)
		{
			if (f[endV] > resLen)
				resEndV = endV, resLen = f[endV];
		}

	int res_n = 0;
	static int res[MaxN];

	res[res_n++] = resEndV;
	for (int v = resEndV; fa[v] != 0 && verType[fa[v]] == 0 && deg[fa[v]] == 1; v = fa[v])
		res[res_n++] = fa[v];

	cout << res_n << endl;
	for (int i = res_n - 1; i >= 0; i--)
		printf("%d ", res[i]);
	cout << endl;

	return 0;
}