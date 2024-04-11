#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 2000;
const int MaxM = 2000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}
template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
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

int n, m;
int a[MaxN + 1];

inline bool check(const int &d)
{
	static int f[MaxN + 1];
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		{
			f[i] = 1;
			for (int j = 1; j < i; j++)
			{
				int l = i - j;
				if ((abs(a[i] - a[j]) + l - 1) / l <= d)
					relax(f[i], f[j] + 1);
			}
		}
	return *max_element(f + 1, f + n + 1) >= m;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		a[i] = getint();

	m = n - m;

	check(0);

	int le = 0, ri = 2000000000;
	while (le != ri)
	{
		int mid = ((s64)le + ri) >> 1;
		if (!check(mid))
			le = mid + 1;
		else
			ri = mid;
	}
	cout << le << endl;

	return 0;
}