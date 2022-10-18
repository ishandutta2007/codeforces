#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

const int MaxN = 150;
const int MaxS = 11175;

template <class T>
inline void tense(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int main()
{
	int n, k, sm;
	static int a[MaxN + 1];

	cin >> n >> k >> sm;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sm = min(sm, MaxS);

	static int f[MaxN + 1][MaxS + 1];
	for (int j = 0; j <= k; j++)
		for (int s = 0; s <= sm; s++)
			f[j][s] = INF;

	f[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = k - 1; j >= 0; j--)
			for (int s = 0; s <= sm; s++)
				if (f[j][s] != INF)
				{
					if (s + i - j <= sm)
						tense(f[j + 1][s + i - j], f[j][s] + a[i + 1]);
				}

	int res = INF;
	for (int s = 0; s <= sm; s++)
		tense(res, f[k][s]);
	cout << res << endl;

	return 0;
}