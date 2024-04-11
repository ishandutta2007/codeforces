#include <iostream>
#include <cstdio>
using namespace std;

const int MaxA = 160000;
const int MaxN = 400;
const int MaxM = 400;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n, m;
	static int a[MaxN + 1][MaxM + 1];
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	int res = 0;

	for (int edR = 1; edR <= n; edR++)
	{
		static int f[MaxM + 1];
		for (int c = 1; c <= m; c++)
			f[c] = 0;

		static int last[MaxA + 1];
		fill(last + 1, last + MaxA + 1, 0);

		static int prev[MaxN * MaxM + 1], next[MaxN * MaxM + 1];
		for (int c = 1; c <= m; c++)
			for (int r = edR; r >= 1; r--)
			{
				int v = (r - 1) * m + c;
				prev[v] = last[a[r][c]], next[v] = 0;
				if (last[a[r][c]])
					next[last[a[r][c]]] = v;
				last[a[r][c]] = v;
			}
		for (int stR = 1; stR <= edR; stR++)
			for (int c = m; c >= 1; c--)
			{
				int v = (stR - 1) * m + c;
				if (prev[v])
					next[prev[v]] = next[v];
				if (next[v])
					prev[next[v]] = prev[v];
			}

		for (int stR = edR; stR >= 1; stR--)
			for (int c = 1; c <= m; c++)
			{
				int v = (stR - 1) * m + c;
				if (prev[v])
					next[prev[v]] = v;
				if (next[v])
					prev[next[v]] = v;
				if (prev[v])
					relax(f[c], (prev[v] - 1) % m + 1);
				if (next[v])
					relax(f[(next[v] - 1) % m + 1], c);
				relax(f[c], f[c - 1]);
				relax(res, (edR - stR + 1) * (c - f[c]));
			}
	}

	cout << res << endl;

	return 0;
}