#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

typedef unsigned u32;

const int MaxN = 70000;
const int MaxS = 70000;

inline u32 lowbit(const u32 &x)
{
	return x & ~(x - 1);
}

int main()
{
	int n, s;
	static int orig[MaxN + 1];
	static PII a[MaxN];

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		scanf("%d", &orig[i + 1]), a[i] = PII(orig[i + 1], i + 1);

	sort(a, a + n);

	s -= a[n - 1].first;
	if (s < 0)
	{
		cout << "-1" << endl;
		return 0;
	}

	static int preLog2[1 << 16];
	preLog2[1] = 0;
	for (int x = 2; x < (1 << 16); x++)
		preLog2[x] = preLog2[x >> 1] + 1;

	int ts = (s >> 5) + 1;
	static u32 f[(MaxS >> 5) + 1];
	static int last[((MaxS >> 5) + 1) << 5];

	for (int j = 0; j <= s; j++)
		last[j] = -1;

	f[0] |= 1 << 0;

	for (int i = 0; i < n - 1; i++)
	{
		int af = a[i].first >> 5;
		int as = a[i].first & 31;

		for (int jf = ts - 1; jf >= af; jf--)
		{
			u32 cur = f[jf - af] << as;
			if (jf - af - 1 >= 0 && as != 0)
				cur |= f[jf - af - 1] >> (32 - as);
			for (u32 rest = cur & ~f[jf]; rest != 0u; rest -= lowbit(rest))
			{
				u32 x = lowbit(rest);
				if (x < (1u << 16))
					x = preLog2[x];
				else
					x = preLog2[x >> 16] + 16;
				f[jf] |= 1u << x;
				last[jf << 5 | x] = i;
			}
		}
	}

	if (s != 0 && last[s] == -1)
	{
		cout << "-1" << endl;
		return 0;
	}

	static bool used[MaxN + 1];
	static int child[MaxN + 1];
	used[a[n - 1].second] = true;
	for (int rest = s; rest > 0; rest -= a[last[rest]].first)
		used[a[last[rest]].second] = true;

	for (int i = 1; i <= n; i++)
		child[i] = 0;
	for (int i = n - 2, fa = n - 1; i >= 0; i--)
		if (!used[a[i].second])
			child[a[fa].second] = a[i].second, fa = i;

	for (int i = 1; i <= n; i++)
	{
		if (child[i])
			printf("%d 1 %d\n", orig[i] - orig[child[i]], child[i]);
		else
			printf("%d 0\n", orig[i]);
	}

	return 0;
}