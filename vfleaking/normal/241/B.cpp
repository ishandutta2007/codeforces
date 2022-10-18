#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned u32;
typedef long long s64;

const int MaxN = 50000;
const int Mod = 1000000007;

int n;
u32 m;
u32 a[MaxN + 1];
int sum[MaxN + 1][31];

const int MaxTrieN = MaxN * 31;

int trie_n;
int trie_l[MaxTrieN + 1], trie_r[MaxTrieN + 1];
int trie[MaxTrieN + 1][2];

void trie_init()
{
	trie_n = 1;
	trie_l[1] = 1;
	trie_r[1] = n + 1;
}
void trie_insert(int val, int idx)
{
	int p = 1;
	for (int i = 30; i >= 0; i--)
	{
		int c = val >> i & 1;
		if (!trie[p][c])
		{
			trie_n++;
			trie_l[trie_n] = idx;
			trie[p][c] = trie_n;
		}
		p = trie[p][c];
		trie_r[p] = idx + 1;
	}
}

inline void calcCount(u32 &limit, u32 &res)
{
	static int p[MaxN + 1];
	for (int i = 1; i <= n; i++)
		p[i] = 1;

	res = 0u;
	limit = 0;
	for (int j = 30; j >= 0; j--)
	{
		u32 cur = 0;
		for (int i = 1; i <= n; i++)
		{
			int q = trie[p[i]][!(a[i] >> j & 1)];
			cur += trie_r[q] - trie_l[q];
		}
		if ((res + cur + 1) / 2 <= m)
			res += cur;
		else
			limit |= 1 << j;
		for (int i = 1; i <= n; i++)
			p[i] = trie[p[i]][(a[i] ^ limit) >> j & 1];
	}
	res /= 2;
}

inline int calcSum(const u32 &limit)
{
	s64 res = 0;
	for (int i = 1; i <= n; i++)
	{
		s64 cnt;
		int p = 1;
		for (int j = 30; j >= 0; j--)
		{
			if (!(limit >> j & 1))
			{
				int q = trie[p][!(a[i] >> j & 1)];

				int l = trie_l[q], r = trie_r[q];
				cnt = r - l;
				res += cnt * ((limit | 1 << j) & (~0 << j));

				for (int k = 0; k < j; k++)
				{
					cnt = sum[r - 1][k] - sum[l - 1][k];
					if (a[i] >> k & 1)
						cnt = r - l - cnt;
					res += cnt << k;
				}
			}

			p = trie[p][(a[i] ^ limit) >> j & 1];
		}
	}

	res /= 2;
	return res % Mod;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%u", &a[i]);
	
	if (m == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	sort(a + 1, a + n + 1);

	trie_init();
	for (int i = 1; i <= n; i++)
		trie_insert(a[i], i);

	for (int i = 0; i < 31; i++)
		sum[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 31; j++)
			sum[i][j] = sum[i - 1][j] + (a[i] >> j & 1);

	u32 cnt;
	u32 limit;
	calcCount(limit, cnt);

	int res = (calcSum(limit) + (s64)(m - cnt) * limit % Mod) % Mod;
	cout << res << endl;
	
	return 0;
}