#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxM = 100000;
const int MaxNBig = 317;

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

inline void puts64(s64 n)
{
	if (n == 0)
		putchar('0');
	else
	{
		if (n < 0)
			putchar('-'), n = -n;
		int t_n = 0;
		static int t[30];
	
		while (n > 0)
			t[t_n++] = n % 10, n /= 10;
		for (int i = t_n - 1; i >= 0; i--)
			putchar('0' + t[i]);
	}
}

int main()
{
	int n, m, nQ;
	static s64 a[MaxN + 1];
	static s64 inh[MaxM + 1];
	static vector<int> s[MaxM + 1];

	cin >> n >> m >> nQ;
	for (int i = 1; i <= n; i++)
		a[i] = getint();
	for (int i = 1; i <= m; i++)
	{
		int sn = getint();
		for (int j = 0; j < sn; j++)
			s[i].push_back(getint());
	}

	const int Lim = 317;

	int big_n = 0;
	static int big[MaxNBig];
	static bool bigExist[MaxNBig][MaxN + 1];
	static s64 bigDelta[MaxM + 1];
	for (int i = 1; i <= m; i++)
		if ((int)s[i].size() >= Lim)
		{
			inh[i] = 0ll;
			for (vector<int>::iterator ix = s[i].begin(); ix != s[i].end(); ix++)
			{
				inh[i] += a[*ix];
				bigExist[big_n][*ix] = true;
			}
			bigDelta[i] = 0;
			big[big_n++] = i;
		}

	static int affect[MaxM + 1][MaxNBig];
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < big_n; j++)
		{
			affect[i][j] = 0;
			for (vector<int>::iterator ix = s[i].begin(); ix != s[i].end(); ix++)
				if (bigExist[j][*ix])
					affect[i][j]++;
		}

	while (nQ--)
	{
		char type;
		while (type = getchar(), type != '?' && type != '+');

		int num = getint();

		if (type == '?')
		{
			if ((int)s[num].size() < Lim)
			{
				s64 res = 0;
				for (vector<int>::iterator ix = s[num].begin(); ix != s[num].end(); ix++)
					res += a[*ix];
				for (int i = 0; i < big_n; i++)
					res += affect[num][i] * bigDelta[big[i]];
				puts64(res), putchar('\n');
			}
			else
				puts64(inh[num]), putchar('\n');
		}
		else if (type == '+')
		{
			int delta = getint();
			if ((int)s[num].size() < Lim)
			{
				for (vector<int>::iterator ix = s[num].begin(); ix != s[num].end(); ix++)
					a[*ix] += delta;
			}
			else
				bigDelta[num] += delta;
			for (int i = 0; i < big_n; i++)
				inh[big[i]] += (s64)affect[num][i] * delta;
		}
	}

	return 0;
}