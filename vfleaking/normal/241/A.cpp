#include <iostream>
#include <cstdio>
using namespace std;

const int MaxM = 1000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int m, k;
	static int d[MaxM + 1], s[MaxM + 1];

	cin >> m >> k;
	for (int i = 1; i <= m; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &s[i]);

	int time = 0;
	int rest = s[1];
	int best = s[1];
	for (int i = 1; i <= m; i++)
	{
		if (d[i] > rest)
		{
			int stop = (d[i] - rest + best - 1) / best;
			time += stop * k;
			rest += stop * best;
		}
		time += d[i];
		rest -= d[i];

		if (i < m)
		{
			rest += s[i + 1];
			relax(best, s[i + 1]);
		}
	}

	cout << time << endl;

	return 0;
}