#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;
const int MaxC = 775;

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
	static int row[MaxM], col[MaxM];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		row[i] = getint(), col[i] = getint();

	int maxC = (int)ceil((sqrt(24 * m - 15) - 1) / 2);

	static vector<int> impo[MaxN + 1];

	for (int i = 0; i < m; i++)
		impo[n - col[i] + 1].push_back(min(n - row[i], maxC));

	static int f_pool1[MaxC + 1], f_pool2[MaxC + 1];

	int *f = f_pool1, *g = f_pool2;
	g[0] = 0;
	for (int h = 1; h <= n; h++, swap(f, g))
	{
		int endC = min(h, maxC);

		static int cnt[MaxC + 1];
		fill(cnt, cnt + endC + 1, 0);
		for (vector<int>::iterator i = impo[h].begin(); i != impo[h].end(); i++)
			cnt[min(*i, endC)]++;
		for (int i = endC - 1; i >= 0; i--)
			cnt[i] += cnt[i + 1];

		for (int c = endC; c >= 0; c--)
		{
			f[c] = c == endC ? INT_MAX : f[c + 1];
			for (int i = c + 1; i <= endC && i <= c + 1; i++)
			{
				int part1 = 3 * cnt[i];
				int part2 = 2 + i * (i + 1) / 2;
				tension(f[c], g[max(i - 1, 0)] + part1 + part2);
			}
		}
		for (int c = 0; c <= endC; c++)
			tension(f[c], g[max(c - 1, 0)] + 3 * cnt[c]);
	}

	cout << g[0] << endl;

	return 0;
}