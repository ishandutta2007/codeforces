#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 3000;
const int MaxM = 3000;
const int MaxNL = MaxN * MaxM * 2;

inline int getint()
{
	char c;
	while (c = getchar(), '0' > c || c > '9');
	int res = c - '0';
	while (c = getchar(), '0' <= c && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int n, m, l, q;
int nl;
bool a[MaxN][MaxM];

int ufs[MaxNL];
int ufs_find(int v)
{
	int r = v;
	while (ufs[r] >= 0)
		r = ufs[r];
	for (int u = v, p = ufs[u]; u != r; u = p, p = ufs[u])
		ufs[u] = r;
	return r;
}
void ufs_union(int v, int u)
{
	v = ufs_find(v), u = ufs_find(u);
	if (v == u)
		return;
	if (ufs[v] > ufs[u])
		ufs[v] = u;
	else
	{
		ufs[u] = v;
		if (ufs[v] == ufs[u])
			ufs[v]--;
	}
}

int main()
{
	cin >> n >> m >> q;
	l = m * 2;
	nl = n * l;
	for (int v = 0; v < nl; v++)
		ufs[v] = -1;

	int res = 0;
	while (q--)
	{
		int x = getint(), y = getint();
		x--, y--;

		if (m == 1)
			continue;

		bool ok = true;
		int liA_n = 0;
		static int liA[8];
		int liB_n = 0;
		static int liB[8];
		for (int dx = -1; dx <= 1; dx++)
			if (0 <= x + dx && x + dx < n)
				for (int dy = -1; dy <= 1; dy++)
				{
					int ux = x + dx, uy = (y + dy + l) % l;
					if (a[ux][uy % m])
						liA[liA_n++] = ufs_find(ux * l + uy);
				}
		for (int ex = -1; ex <= 1; ex++)
			if (0 <= x + ex && x + ex < n)
				for (int ey = -1; ey <= 1; ey++)
				{
					int wx = x + ex, wy = (y + ey + m) % l;
					if (a[wx][wy % m])
						liB[liB_n++] = ufs_find(wx * l + wy);
				}
		for (int i = 0; i < liA_n; i++)
			for (int j = 0; j < liB_n; j++)
				if (liA[i] == liB[j])
					ok = false;
		if (!ok)
			continue;
		res++;
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
				if (0 <= x + dx && x + dx < n)
				{
					int ux = x + dx, uy = (y + dy + l) % l;
					if (a[ux][uy % m])
						ufs_union(ux * l + uy, x * l + y);
				}
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
				if (0 <= x + dx && x + dx < n)
				{
					int ux = x + dx, uy = (y + dy + m) % l;
					if (a[ux][uy % m])
						ufs_union(ux * l + uy, x * l + m + y);
				}
		a[x][y] = true;
	}

	cout << res << endl;

	return 0;
}