#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <time.h>
#include <algorithm>
#define mkp make_pair
#define inf 1000000000
#define MOD 1000000007
#define eps 1e-7
 
using namespace std;
typedef long long ll;
 
int n;
int mask[72];
ll f[2][72];
ll dp[2][1 << 20];
 
bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return 0;
	return 1;
}
 
void init()
{
	for (int i = 0; i < 72; i++)
		f[0][i] = 1;
	int cnt = 0;
	for (int i = 2; i < 72; i++)
	{
		if (!prime(i))
			continue;
		for (int j = 1; j < 72; j++)
		{
			int x = j;
			while (x%i == 0)
			{
				x /= i;
				mask[j] ^= (1 << cnt);
			}
		}
		cnt++;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	init();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		f[0][x] = f[1][x] = (f[0][x] + f[1][x]) % MOD;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= 70; i++)
	{
		int nxt = (i + 1) % 2;
		int cur = i % 2;
		for (int msk = 0; msk < (1<<20); msk++)
		{
			dp[nxt][msk^mask[i]] = dp[nxt][msk^mask[i]] + dp[cur][msk] * f[1][i];
			dp[nxt][msk] = dp[nxt][msk] + dp[cur][msk] * f[0][i];
			if (dp[nxt][msk^mask[i]] >= MOD)
				dp[nxt][msk^mask[i]] %= MOD;
			if (dp[nxt][msk] >= MOD)
				dp[nxt][msk] %= MOD;
		}
		for (int msk = 0; msk < (1<<20); msk++)
			dp[cur][msk] = 0;
	}
	cout << (dp[1][0] - 1 + MOD)%MOD << endl;
}