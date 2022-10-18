#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
typedef long long s64;

const s64 S64_MAX = 9223372036854775807ll;

const int MaxN = 100000;
const int MaxM = 100000;
const int MaxP = 100;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

// getint
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
	int n, m, p;
	static s64 d[MaxN + 1];
	static int hi[MaxM + 1], ti[MaxM + 1];

	cin >> n >> m >> p;
	
	d[1] = 0;
	for (int i = 2; i <= n; i++)
		d[i] = getint();
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &hi[i], &ti[i]);

	for (int i = 2; i <= n; i++)
		d[i] += d[i - 1];

	static s64 a[MaxM + 1];
	for (int i = 1; i <= m; i++)
		a[i] = ti[i] - d[hi[i]];

	sort(a + 1, a + m + 1);

	static s64 sumA[MaxM + 1];
	sumA[0] = 0;
	for (int i = 1; i <= m; i++)
		sumA[i] = sumA[i - 1] + a[i];

	static s64 f_pool1[MaxM + 1], f_pool2[MaxM + 1];

	s64 *f = f_pool1, *g = f_pool2;

	f[0] = 0;
	for (int i = 1; i <= m; i++)
		f[i] = (s64)i * a[i] - sumA[i];
	swap(f, g);

	for (int pi = 2; pi <= p; pi++, swap(f, g))
	{
		for (int i = 1; i <= m; i++)
			g[i] += sumA[i];

		static int q[MaxM + 1];
		int top, bot;

		top = bot = 0;
		q[bot++] = 0;

		for (int i = 1; i <= m; i++)
		{
			while (bot - top > 1 && g[q[top]] - (s64)q[top] * a[i] >= g[q[top + 1]] - (s64)q[top + 1] * a[i])
				top++;

			f[i] = (s64)i * a[i] - sumA[i] + g[q[top]] - (s64)q[top] * a[i];

			while (bot - top > 1)
			{
				int r = q[bot - 2];
				int s = q[bot - 1];

				if ((double)(g[s] - g[r]) / (s - r) >= (double)(g[i] - g[s]) / (i - s))
					bot--;
				else
					break;
			}
			q[bot++] = i;
		}
	}

	cout << g[m] << endl;

	return 0;
}