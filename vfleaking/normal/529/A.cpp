#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MaxN = 2000000;
const int NLetter = 128;

namespace SA
{
	int n;
	char s[MaxN + 1];

	int sa[MaxN];
	int rank[MaxN];
	int height[MaxN];

	inline bool sa_init_equal(int *y, int k, int i, int j)
	{
		return y[i] == y[j] && y[(i + k) % n] == y[(j + k) % n];
	}

	void sa_init()
	{
		int *x = rank, *y = height;
		static int w[MaxN];
		fill(w, w + NLetter, 0);
		for (int i = 0; i < n; i++)
			w[(int)s[i]]++;
		for (int i = 1; i < NLetter; i++)
			w[i] += w[i - 1];
		for (int i = n - 1; i >= 0; i--)
			sa[--w[(int)s[i]]] = i;

		int nR = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || s[sa[i]] != s[sa[i - 1]])
				nR++;
			y[sa[i]] = nR - 1;
		}
		for (int k = 1; k < n && nR < n; k <<= 1, swap(x, y))
		{
			int len = 0;
			for (int i = 0; i < n; i++)
				x[len++] = (sa[i] + n - k) % n;
			fill(w, w + nR, 0);
			for (int i = 0; i < n; i++)
				w[y[x[i]]]++;
			for (int i = 1; i < nR; i++)
				w[i] += w[i - 1];
			for (int i = n - 1; i >= 0; i--)
				sa[--w[y[x[i]]]] = x[i];

			nR = 0;
			for (int i = 0; i < n; i++)
			{
				if (i == 0 || !sa_init_equal(y, k, sa[i], sa[i - 1]))
					nR++;
				x[sa[i]] = nR - 1;
			}
		}
	}
}

int main()
{
	int n;
	static char s[MaxN + 1];
	scanf("%s", s);

	n = strlen(s);

	SA::n = n;
	copy(s, s + n, SA::s);

	SA::sa_init();

	static int sum[MaxN + 1];
	sum[0] = 0;
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
	
	static int pre[MaxN + 1];
	pre[0] = sum[0];
	for (int i = 0; i < n; i++)
		pre[i + 1] = min(pre[i], sum[i]);

	static int suf[MaxN + 1];
	suf[n] = sum[n];
	for (int i = n - 1; i >= 0; i--)
		suf[i] = min(suf[i + 1], sum[i]);

	int res_n = 0;
	static char res[MaxN + 1];

	int d = abs(sum[n]);
	for (int k = 0; k < n; k++)
	{
		int p = SA::sa[k];
		int sm = min(suf[p] - sum[p], sum[n] - sum[p] + pre[p]);
		if (sum[n] > 0)
		{
			if (sm >= 0)
			{
				for (int i = 0; i < n; i++)
					res[res_n++] = s[(p + i) % n];
				for (int i = 0; i < d; i++)
					res[res_n++] = ')';
				break;
			}
		}
		else
		{
			if (d + sm >= 0)
			{
				for (int i = 0; i < d; i++)
					res[res_n++] = '(';
				for (int i = 0; i < n; i++)
					res[res_n++] = s[(p + i) % n];
				break;
			}
		}
	}

	printf("%s\n", res);

	return 0;
}