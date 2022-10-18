#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int MaxN = 300;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

inline int gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int main()
{
	int n;
	static int al[MaxN], ac[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &al[i]);

		int ral = 1;
		for (int k = 2; k * k <= al[i]; k++)
			if (al[i] % k == 0)
			{
				while (al[i] % k == 0)
					al[i] /= k;
				ral *= k;
			}
		if (al[i] > 1)
			ral *= al[i];
		al[i] = ral;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &ac[i]);

	map<int, int> f, g;
	f[0] = 0;

	for (int i = 0; i < n; i++)
	{
		swap(f, g);
		f = g;

		for (map<int, int>::iterator it = g.begin(); it != g.end(); it++)
		{
			int g = gcd(it->first, al[i]);
			if (!f.count(g))
				f[g] = it->second + ac[i];
			else
				tension(f[gcd(it->first, al[i])], it->second + ac[i]);
		}
	}

	if (f.count(1))
		cout << f[1] << endl;
	else
		cout << -1 << endl;

	return 0;
}