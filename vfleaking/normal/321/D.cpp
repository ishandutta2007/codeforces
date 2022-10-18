#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 33;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n;
	static int a[MaxN][MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	int l = (n + 1) / 2;
	int res = INT_MIN;
	for (int lastR = 0; lastR < (1 << l); lastR++)
	{
		int cur = 0;
		for (int r = 0; r < l; r++)
		{
			int resR = INT_MIN;
			for (int tv = 0; tv <= 1; tv++)
			{
				int curR = 0;
				for (int c = 0; c < l; c++)
				{
					int resRC = INT_MIN;
					for (int cv = 0; cv <= 1; cv++)
					{
						if (r == l - 1 && cv != (lastR >> c & 1))
							continue;
						if (c == l - 1 && cv != tv)
							continue;
						int curRC = 0;
						curRC += cv == 0 ? a[r][c] : -a[r][c];
						if (r + l < n)
							curRC += (cv ^ (lastR >> c & 1)) == 0 ? a[r + l][c] : -a[r + l][c];
						if (c + l < n)
							curRC += (cv ^ tv) == 0 ? a[r][c + l] : -a[r][c + l];
						if (r + l < n && c + l < n)
							curRC += (cv ^ (lastR >> c & 1) ^ tv ^ (lastR >> (l - 1) & 1)) == 0 ? a[r + l][c + l] : -a[r + l][c + l];
						relax(resRC, curRC);
					}
					if (resRC == INT_MIN)
					{
						curR = INT_MIN;
						break;
					}
					curR += resRC;
				}
				relax(resR, curR);
			}
			cur += resR;
		}
		relax(res, cur);
	}

	cout << res << endl;

	return 0;
}