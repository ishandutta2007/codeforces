#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MaxN = 100000;
const int MaxM = 2000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n, m;
	static int a[MaxN];
	static int b[MaxM];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < m; j++)
		scanf("%d", &b[j]);

	sort(a, a + n), sort(b, b + m);

	static int head[MaxN];
	static int f[MaxN + 1], g[MaxN + 1];

	for (int i = 0, b_p = 0; i < n; i++)
	{
		head[i] = (i > 0 && a[i - 1] + 1 == a[i]) ? head[i - 1] : i;

		while (b_p < m && b[b_p] <= a[i])
			b_p++;
		f[i + 1] = g[head[i]];
		for (int j = b_p - 1; j >= 0 && a[i] - b[j] <= i; j--)
			relax(f[i + 1], g[head[i - (a[i] - b[j])]] + (b_p - j));

		relax(g[i + 1], f[i + 1]);
		for (int j = b_p; j < m && i + b[j] - a[i] < n; j++)
			relax(g[i + b[j] - a[i] + 1], f[i + 1] + j - b_p + 1);
		relax(g[i + 1], g[i]);
	}

	cout << g[n] << endl;

	return 0;
}