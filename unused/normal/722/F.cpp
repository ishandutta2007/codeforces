#include "bits/stdc++.h"
using namespace std;

int sz[100005];
vector<pair<int,int>> pos[100005];

int mod[] = { 32, 27, 25, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

constexpr int TSIZE = 131072;
array<long long, 12> tree[TSIZE * 2 + 1];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void update(int pos, const long long *val)
{
	pos += TSIZE;
	for (int i = 0; i < 12; i++) tree[pos][i] = val[i];
	while (pos >>= 1)
	{
		for (int i = 0; i < 12; i++)
			tree[pos][i] = tree[pos << 1][i] & tree[pos << 1 | 1][i];
	}
}

bool query(int s, int e)
{
	array<long long, 12> ret;
	for (int i = 0; i < 12; i++) ret[i] = -1;

	s += TSIZE; e += TSIZE;

	while (s <= e)
	{
		if (s & 1)
		{
			for (int i = 0; i < 12; i++) ret[i] &= tree[s][i];
			s++;
		}
		if ((e & 1) == 0)
		{
			for (int i = 0; i < 12; i++) ret[i] &= tree[e][i];
			e--;
		}
		s >>= 1; e >>= 1;
	}

	for (int i = 0; i < 12; i++) if (ret[i] == 0) return false;
	return true;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sz[i]);
		for (int j = 0; j < sz[i]; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			pos[tmp].emplace_back(i, j);
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int s = 0, ans = 0;
		for (int e = s; s < pos[i].size(); s = e)
		{
			e++;
			while (e < pos[i].size() && pos[i][e].first - pos[i][s].first == e - s) e++;

			for (int j = s; j < e; j++)
			{
				array<long long, 12> val;

				for (int k = 0; k < 12; k++)
				{
					int g = gcd(mod[k], sz[pos[i][j].first]);
					if (g == 1)
					{
						val[k] = -1;
						continue;
					}

					val[k] = 0;
					for (int flag = pos[i][j].second % g; flag < mod[k]; flag += g)
						val[k] |= 1ll << flag;
				}

				update(j, &val[0]);
			}

			for (int j = s; j < e; j++)
			{
				int lo = ans + 1, hi = e - j;
				while (lo <= hi)
				{
					int mid = (lo + hi) / 2;

					if (query(j, j + mid - 1))
					{
						ans = mid;
						lo = mid + 1;
					}
					else
					{
						hi = mid - 1;
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}