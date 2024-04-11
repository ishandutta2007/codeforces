#include <bits/stdc++.h>
using namespace std;

int MOD;
int len[1000005];
int fact[1000005];
int comb[5005];
bool v2[5005];
int dp1[5005][5005][2];
bool v1[5005][5005][2];
int n, m;
vector<int> primes;
vector<int> powers;

int D1(int color, int len, bool forb)
{
	if (color > len) return 0;
	if (color == len)
	{
		if (forb) return fact[len - 1] * 1ll * (len - 1) % MOD;
		else return fact[len];
	}
	if (color == 0 || len == 0) return 0;

	if (v1[color][len][forb] == false)
	{
		v1[color][len][forb] = true;

		int avail = color - forb;

		// 1:       
		// 2:    
		dp1[color][len][forb] = avail * 1ll * (D1(color - 1, len - 1, false) + D1(color, len - 1, true)) % MOD;
	}

	return dp1[color][len][forb];
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int C()
{
	vector<int> upper, lower;

	for (int i = 1; i <= 5000; i++)
	{
		upper.push_back(m - i + 1);
		lower.push_back(i);

		for (int &z : lower)
		{
			for (int &y : upper)
			{
				int g = gcd(z, y);
				z /= g; y /= g;
				if (z == 1) break;
			}
		}

		comb[i] = 1;
		for (int x : upper) comb[i] = comb[i] * 1ll * x % MOD;

		upper.erase(remove_if(upper.begin(), upper.end(), [](int t) {return t == 1;}), upper.end());
		lower.erase(remove_if(lower.begin(), lower.end(), [](int t) {return t == 1;}), lower.end());
	}
}

int e[2][5005];

int main()
{
	scanf("%d%d%d", &n, &m, &MOD);
	C();

	fact[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		fact[i] = fact[i - 1] * 1ll * i % MOD;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &len[i]);
	}

	int *d1 = e[0], *d2 = e[1];

	for (int i = 1; i <= len[0]; i++)
	{
		d1[i] = comb[i] * 1ll * D1(i, len[0], false) % MOD;
	}

	for (int i = 1; i < n; i++)
	{
		int total = 0;

		for (int j = 1; j <= len[i - 1]; j++)
		{
			total = (total + d1[j]) % MOD;
		}

		for (int j = 1; j <= min(len[i], len[i - 1]); j++)
		{
			d2[j] = (long long)(total + MOD - d1[j]) * comb[j] % MOD * D1(j, len[i], false) % MOD;
			d2[j] = (d2[j] + d1[j] * 1ll * (comb[j] - 1) % MOD * D1(j, len[i], false)) % MOD;
		}

		for (int j = len[i - 1] + 1; j <= len[i]; j++)
		{
			d2[j] = total * 1ll * comb[j] % MOD * D1(j, len[i], false) % MOD;
		}

		swap(d1, d2);
	}

	int ans = 0;
	for (int i = 1; i <= len[n - 1]; i++) ans = (ans + d1[i]) % MOD;
	printf("%d\n", ans);

	fflush(stdout);
	_Exit(0);
}