#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
using namespace std;

const int MaxN = 100;
const int L = 100000;
const int H = 100;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

inline int handle(
		const int &n, const int &m, const int &a, const int &b,
		const int *mirrorU, const int *mirrorD, const int *value)
{
	double k = (double)L / (H * m + a + b);
	int res = 0;
	
	static bool book[MaxN + 1];
	book[0] = true;
	fill(book + 1, book + n + 1, false);
	
	for (double i = a * k; i < L; i += 2 * H * k)
	{
		int t = mirrorD[(int)floor(i)];
		if (book[t])
			return 0;
		book[t] = true;
		res += value[t];
	}
	for (double i = a * k + H * k; i < L; i += 2 * H * k)
	{
		int t = mirrorU[(int)floor(i)];
		if (book[t])
			return 0;
		book[t] = true;
		res += value[t];
	}
	return res;
}

int main()
{
	int hl, hr, n;
	static int value[MaxN + 1];
	static int mirrorU[L], mirrorD[L];
	
	cin >> hl >> hr >> n;
	for (int i = 1; i <= n; i++)
	{
		char type;
		int l, r;
		
		cin >> value[i] >> type >> l >> r;
		switch (type)
		{
			case 'F':
				for (int j = l; j < r; j++)
					mirrorD[j] = i;
				break;
			case 'T':
				for (int j = l; j < r; j++)
					mirrorU[j] = i;
				break;
		}
	}
	
	int res = 0;
	for (int m = 0; m <= n; m += 2)
	{
		relax(res, handle(n, m, hl, hr, mirrorU, mirrorD, value));
		relax(res, handle(n, m, H - hl, H - hr, mirrorD, mirrorU, value));
	}
	for (int m = 1; m <= n; m += 2)
	{
		relax(res, handle(n, m, hl, H - hr, mirrorU, mirrorD, value));
		relax(res, handle(n, m, H - hl, hr, mirrorD, mirrorU, value));
	}
	cout << res << endl;
	
	return 0;
}