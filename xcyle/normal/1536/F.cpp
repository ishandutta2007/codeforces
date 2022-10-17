#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 1000005
using namespace std;
const int mo = 1e9 + 7;
int n, fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main()
{
	scanf("%d", &n);
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo; 
	}
	int ans = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		ans = (ans + (ll)calc(i * 2, n - 2 * i) * fac[i * 2 - 1] % mo) % mo;
	}
	printf("%d", (ll)ans * 2 % mo * n % mo) % mo;
	return 0;
}