#include <bits/stdc++.h>
using namespace std;

unsigned n;
char dat[100];
constexpr unsigned MOD = 1000000007;

unsigned limit;

unsigned memo[75][1048576];
bool T[75][1048576];

unsigned D(unsigned idx, unsigned st)
{
	bool fin = (st && __builtin_popcount(st + 1) == 1);
	if (idx == n) return fin;

	auto &res = memo[idx][st];
	if (T[idx][st] == false)
	{
		T[idx][st] = true;
		res = fin;
		unsigned z = 0;
		for (unsigned r = idx; r < n; r++)
		{
			z = (z << 1) | (dat[r] & 1);
			if (z == 0) continue;
			if (z > 20) break;

			res += D(r + 1, st | (1u << (z - 1)));
			if (res >= MOD) res -= MOD;
		}
	}

	return res;
}

int main()
{
	scanf("%u%s", &n, dat);

	unsigned ans = 0;

	for (unsigned i = 0; i < n; i++)
	{
		ans += D(i, 0);
		if (ans >= MOD) ans -= MOD;
	}

	printf("%u\n", ans);

	fflush(stdout);
	_Exit(0);
}