#include <iostream>
#include <cstdio>
#define maxn 2000005
#define ll long long
using namespace std;
const int mo = 998244353;
int n, f[maxn], fac[maxn], inv[maxn], ifac[maxn], pow[maxn], s[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			s[j]++;
		}
	}
	pow[0] = 1;
	pow[1] = 2; 
	for (int i = 2; i <= 2 * n; i++)
	{
		pow[i] = (ll)pow[i - 1] * 2 % mo;
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans = (ans + (ll)(pow[n - i - 1]) * s[i] % mo) % mo;
	}
	printf("%d", (ans + s[n]) % mo);
	return 0;
}