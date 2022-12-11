#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
vector<int> cnt;
int dp[5000][5000];
bool v[5000][5000];
constexpr int MOD = 1'000'000'007;
int n, k;
int fact[100005];
int finv[100005];
int total;

int C(int a, int b)
{
	if (b < 0 || a < b) return 0;
	return fact[a] * 1ll * finv[b] % MOD * finv[a - b] % MOD;
}

int D(int idx, int chosen)
{
	if (idx == cnt.size())
	{
		return C(n - total, k - chosen);
	}

	if (v[idx][chosen] == false)
	{
		v[idx][chosen] = true;
		dp[idx][chosen] = (D(idx + 1, chosen) +
			cnt[idx] * 1ll * D(idx + 1, chosen + 1)) % MOD;
	}
	return dp[idx][chosen];
}

bool lucky(int t)
{
	while (t)
	{
		if (t % 10 != 4 && t % 10 != 7) return false;

		t /= 10;
	}
	return true;
}

int main()
{
	fact[0] = 1;
	for (int i = 1; i <= 100000; i++) fact[i] = fact[i - 1] * 1ll * i % MOD;
	finv[100000] = 716327852;
	for (int i = 99999; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1ll) % MOD;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (lucky(tmp)) mp[tmp]++;
	}

	for (auto &&e : mp)
	{
		cnt.push_back(e.second);
		total += e.second;
	}

	printf("%d\n", D(0, 0));
}