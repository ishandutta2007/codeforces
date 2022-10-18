#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 5000;
const int MaxM = 5000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

inline int getint()
{
	char c;
	while (c = getchar(), ('0' > c || c > '9') && c != '-');

	if (c != '-')
	{
		int res = c - '0';
		while (c = getchar(), '0' <= c && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
	else
	{
		int res = 0;
		while (c = getchar(), '0' <= c && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
}

int main()
{
	int n, m;
	static int type[MaxM], le[MaxM], ri[MaxM], d[MaxM];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		type[i] = getint(), le[i] = getint(), ri[i] = getint(), d[i] = getint();

	static int a[MaxN + 1];
	for (int i = 1; i <= n; i++)
		a[i] = 1000000000;
	for (int i = 0; i < m; i++)
	{
		if (type[i] == 1)
		{
			for (int j = le[i]; j <= ri[i]; j++)
				a[j] += d[i];
		}
		else
		{
			for (int j = le[i]; j <= ri[i]; j++)
				tension(a[j], d[i]);
		}
	}
	for (int i = m - 1; i >= 0; i--)
	{
		if (type[i] == 1)
		{
			for (int j = le[i]; j <= ri[i]; j++)
				a[j] -= d[i];
		}
		else
		{
			bool ok = false;
			for (int j = le[i]; j <= ri[i]; j++)
				if (a[j] == d[i])
				{
					ok = true;
					break;
				}
			if (!ok)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	cout << endl;

	return 0;
}