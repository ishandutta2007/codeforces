#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MaxN = 100000;
const int MaxB = 100000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

inline int getint()
{
	char c;
	while (c = getchar(), '0' > c || c > '9');

	int res = c - '0';
	while (c = getchar(), '0' <= c && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int main()
{
	int nCases;
	int n, maxB, repeat;
	int all;
	static int b[MaxN];

	cin >> nCases >> n >> maxB >> repeat;
	tension(repeat, n);
	tension(repeat, maxB);
	maxB++;

	while (nCases--)
	{
		for (int i = 0; i < n; i++)
			b[i] = getint();

		int len = 0;
		static int sta[MaxN];
		static int pos[MaxB + 1];
		fill(pos, pos + maxB, 0);
		for (int i = 0; i < repeat; i++)
			for (int j = 0; j < n; j++)
			{
				if (len == 0 || b[j] > sta[len - 1])
					sta[pos[b[j]] = len++] = b[j];
				else
				{
					while (sta[pos[b[j]]] < b[j])
						pos[b[j]]++;
					sta[pos[b[j]]] = b[j];
				}
			}
		cout << len << endl;
	}

	return 0;
}