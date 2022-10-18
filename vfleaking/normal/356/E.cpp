#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long s64;

const int NLetter = 26;

const int MaxN = 100000;
const int MaxLogN = 17;

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

int n;
char s[MaxN + 2];

int sa[MaxN], rank[MaxN + 1];
int height[MaxN + 1];

int st[MaxN][MaxLogN + 1];
int preLog2[MaxN + 1];

inline bool sa_init_equal(const int *y, const int &k, const int &i, const int &j)
{
	return y[i] == y[j] && (i + k <= n ? y[i + k] : -1) == (j + k <= n ? y[j + k] : -1);
}

inline void sa_init()
{
	int *x = rank, *y = height;

	int nR;
	static int w[MaxN + 1];

	fill(w, w + NLetter, 0);
	for (int i = 1; i <= n; i++)
		w[s[i] - 'a']++;
	for (int i = 1; i < NLetter; i++)
		w[i] += w[i - 1];
	for (int i = n; i >= 1; i--)
		sa[--w[s[i] - 'a']] = i;
	nR = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || s[sa[i]] != s[sa[i - 1]])
			nR++;
		y[sa[i]] = nR - 1;
	}

	for (int k = 1; nR < n; k <<= 1, swap(x, y))
	{
		int len = 0;
		for (int i = n - k + 1; i <= n; i++)
			x[len++] = i;
		for (int i = 0; i < n; i++)
			if (sa[i] - k >= 1)
				x[len++] = sa[i] - k;

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

	if (y != rank)
		copy(y + 1, y + n + 1, rank + 1);

	for (int i = 1, j = 0; i <= n; i++)
	{
		if (j > 0)
			j--;
		if (rank[i] == 0)
			continue;
		int p = sa[rank[i] - 1];
		while (i + j <= n && p + j <= n && s[i + j] == s[p + j])
			j++;
		height[rank[i]] = j;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		st[i][0] = height[i];
		for (int j = 1; i + (1 << j) - 1 < n; j++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}

	preLog2[1] = 0;
	for (int i = 2; i <= n; i++)
		preLog2[i] = preLog2[i >> 1] + 1;
}

inline int getLcp(int le, int ri)
{
	if (le == ri)
		return n - le + 1;
	le = rank[le], ri = rank[ri];
	if (le > ri)
		swap(le, ri);
	le++;
	int k = preLog2[ri - le + 1];
	return min(st[le][k], st[ri - (1 << k) + 1][k]);
}

int cntC[MaxN + 1][NLetter];
bool isGood[MaxN + 1][MaxLogN + 1];

inline bool isEqual(const int &x, const int &y, const int &l)
{
	return getLcp(x, y) >= l;
}

inline s64 sqr(const int &x)
{
	return (s64)x * x;
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);

	sa_init();

	for (int i = 1; i <= n; i++)
		copy(cntC[i - 1], cntC[i - 1] + NLetter, cntC[i]), cntC[i][s[i] - 'a']++;

	for (int i = n; i >= 1; i--)
	{
		isGood[i][0] = true;
		for (int j = 1; i + (1 << (j + 1)) - 2 <= n; j++)
		{
			int mid = i + (1 << j) - 1;
			int ri = i + (1 << (j + 1)) - 2;
			isGood[i][j] = isGood[i][j - 1] && isEqual(i, mid + 1, (1 << j) - 1) && cntC[ri][s[mid] - 'a'] - cntC[i - 1][s[mid] - 'a'] == 1;
		}
	}

	s64 inh = 0;
	static s64 deltaVal[MaxN + 1][NLetter];
	static s64 deltaValPreMod[1 + MaxN + 1];

	for (int i = 1; i <= n; i++)
		for (int j = 0; i + (1 << (j + 1)) - 2 <= n; j++)
		{
			s64 cur = sqr((1 << (j + 1)) - 1);
			int mid = i + (1 << j) - 1;
			int ri = i + (1 << (j + 1)) - 2;

			if (isGood[i][j])
			{
				inh += cur;

				for (char c = 'a'; c <= 'z'; c++)
					if (c != s[mid])
					{
						if (cntC[ri][c - 'a'] - cntC[i - 1][c - 'a'] > 0)
							deltaVal[mid][c - 'a'] -= cur;
					}
				if (j != 0)
				{
					deltaValPreMod[i] -= cur, deltaValPreMod[mid] += cur;
					deltaValPreMod[mid + 1] -= cur, deltaValPreMod[ri + 1] += cur;
				}
			}
			else
			{
				if (isGood[i][j - 1] && isEqual(i, mid + 1, (1 << j) - 1))
				{
					for (char c = 'a'; c <= 'z'; c++)
						if (cntC[ri][c - 'a'] - cntC[i - 1][c - 'a'] - (c == s[mid]) == 0)
							deltaVal[mid][c - 'a'] += cur;
				}

				int diffPos = getLcp(i, mid + 1);
				if (diffPos < (1 << j) - 1 && isEqual(i + diffPos + 1, mid + 1 + diffPos + 1, ((1 << j) - 1) - (diffPos + 1)))
				{
					if (isGood[i][j - 1])
					{
						char c = s[i + diffPos];
						if (cntC[ri][s[mid] - 'a'] - cntC[i - 1][s[mid] - 'a'] - (s[mid + 1 + diffPos] == s[mid]) + (c == s[mid]) == 1)
							deltaVal[mid + 1 + diffPos][c - 'a'] += cur;
					}
					if (isGood[mid + 1][j - 1])
					{
						char c = s[mid + 1 + diffPos];
						if (cntC[ri][s[mid] - 'a'] - cntC[i - 1][s[mid] - 'a'] - (s[i + diffPos] == s[mid]) + (c == s[mid]) == 1)
							deltaVal[i + diffPos][c - 'a'] += cur;
					}
				}
			}
		}

	for (int i = 1; i <= n; i++)
		deltaValPreMod[i] += deltaValPreMod[i - 1];
	for (int i = 1; i <= n; i++)
		for (char c = 'a'; c <= 'z'; c++)
			deltaVal[i][c - 'a'] += deltaValPreMod[i];

	s64 res = 0;
	for (int i = 1; i <= n; i++)
		for (char c = 'a'; c <= 'z'; c++)
			relax(res, deltaVal[i][c - 'a']);
	res += inh;

	cout << res << endl;

	return 0;
}