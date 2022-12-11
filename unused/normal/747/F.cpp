#include <bits/stdc++.h>
using namespace std;

constexpr int INF = (int)2e9 + 5;
using state = array<unsigned, 16>;

state ulltostate(unsigned long long f)
{
	state ret;
	for (int i = 0; i < 16; i++)
		ret[i] = (f >> (i * 4)) & 15;

	return ret;
}

unsigned long long statetoull(state st)
{
	unsigned long long f = 0;
	sort(st.begin(), st.end());

	for (int i = 0; i < 16; i++)
		f |= st[i] << (i * 4);

	return f;
}

unordered_map<unsigned long long, long long> dp[10];
int t;

long long D(int length, state st)
{
	if (length == 0) return 1;

	auto itr = dp[length].emplace(statetoull(st), 0);
	if (itr.second)
	{
		for (int i = 0; i < 16; i++)
		{
			if (st[i] == t) continue;
			st[i]++;
			itr.first->second += D(length - 1, st);
			st[i]--;
		}
	}

	return itr.first->second;
}

int main()
{
	long long k;
	scanf("%lld%d", &k, &t);
	if (k <= 15)
	{
		printf("%llx", k);
		return 0;
	}

	k -= 15;

	int z = 1;
	state st = {};
	st[15] = 1;
	while (D(z, st) * 15 < k)
	{
		k -= D(z, st) * 15;
		z++;
	}

	// z + 1  .
	st[15] = 0;
	bool nz = true;
	while (z >= 1)
	{
		for (int i = nz; i < 16; i++)
		{
			if (st[i] == t) continue;
			st[i]++;
			long long res = D(z, st);
			if (res >= k)
			{
				printf("%x", i);
				break;
			}
			k -= res;
			st[i]--;
		}

		nz = false;
		z--;
	}

	for (int i = 0; i < 16; i++)
	{
		if (st[i] < t)
		{
			if (--k == 0)
			{
				printf("%x", i);
				break;
			}
		}
	}
}