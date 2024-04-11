#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 6000005
using namespace std;
const int mo = 1e9 + 7;
int n, q, x;
int f[maxn];
int fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main()
{
	scanf("%d%d", &n, &q);
	inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= 3 * (n + 1); i++)
	{
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		fac[i] = (ll)fac[i - 1] * i % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	for (int i = 1; i <= n; i++)
	{
		f[1] = (f[1] + calc(3 * i, 1)) % mo;
		f[2] = (f[2] + calc(3 * i, 2)) % mo;
	}
	for (int i = 3; i <= 3 * n; i++)
	{
		f[i] = ((ll)3 * f[i - 1] % mo + f[i - 2]) % mo;
		f[i] = (ll)(calc(3 * (n + 1), i + 1) - f[i] + mo) * inv[3] % mo;
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &x);
		printf("%d\n", f[x]);
	}
	return 0; 
}