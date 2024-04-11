#include <bits/stdc++.h>
using namespace std;

char str[55];
int len;
int zero;
int n;
pair<int, unsigned> dat[500005];
vector<unsigned long long> avail[40];
constexpr int MOD = 1000000007;

int dp[500005][45];
bool v[500005][45];
int comb[45][45];

int C(int a, int b)
{
	if (b == a || b == 0) return 1;
	if (comb[a][b] == 0)
	{
		comb[a][b] = (C(a - 1, b - 1) + C(a - 1, b)) % MOD;
	}
	return comb[a][b];
}

int D(int idx, int z)
{
	if (z < 0) return 0;
	if (idx == n) return z == 0;
	if (v[idx][z] == false)
	{
		v[idx][z] = true;
		dp[idx][z] =
			(z * 1ll * (D(idx + 1, z) + D(idx + 1, z - 1)) + (dat[idx].first - len) * 1ll * D(idx + 1, z)) % MOD;
	}

	return dp[idx][z];
}

unordered_map<unsigned long long, int> memo[20];
int cnt;

int recur(unsigned long long flag, int idx)
{
	auto itr = memo[idx].emplace(flag, 0);
	auto &ret = itr.first->second;

	if (itr.second)
	{
		if (idx == cnt)
		{
			int z = __builtin_popcountll(flag);//__popcnt(flag) + __popcnt(flag >> 32);

			for (int i = 0; i <= z; i++)
			{
				ret = (ret + D(idx, zero - i) * 1ll * C(z, i)) % MOD;
			}
		}
		else
		{
			if (avail[idx].empty())
			{
				for (int p = 0; p < dat[idx].first; p++)
				{
					bool wrong = false;
					for (int j = p; j < len; j += dat[idx].first)
					{
						if (str[j] == '1')
						{
							wrong = true;
							break;
						}
					}

					if (wrong) continue;

					unsigned long long nf = 0;

					for (int j = p; j < len; j += dat[idx].first) nf |= (1ll << j);
					avail[idx].push_back(nf);
				}
			}
			for (unsigned long long f : avail[idx])
			{
				ret = (ret + recur(flag | f, idx + 1)) % MOD;
			}
		}
	}

	return ret;
}

int main()
{
	scanf("%s", str);

	while (str[len])
	{
		if (str[len] == '0') zero++;
		len++;
	}

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%u", &dat[i].first, &dat[i].second);
	}
	sort(dat, dat + n);
	while (cnt < n && dat[cnt].first < len) ++cnt;
	int ans = recur(0, 0);

	for (int i = 0; i < n; i++)
	{
		int mul = dat[i].first;
		int now = 0; unsigned flag = 1;
		--dat[i].second;
		while (flag <= dat[i].second)
		{
			if (flag & dat[i].second) ans = ans * 1ll * mul % MOD;
			mul = (mul * 1ll * mul) % MOD;
			flag <<= 1;
		}
	}

	printf("%d\n", ans);
	fflush(stdout);
	_Exit(0);
}