#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 1000005
using namespace std;
const int mo = 998244353;
int n, fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
inline int pow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
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
	int ans = 0, last = 1;
	for (int i = 1; i <= n; i++)
	{
		last = (mo - last) % mo;
		int temp = (ll)2 * last % mo * calc(n, i) % mo * pow(3, i) % mo;
        int tt = (ll)n * (n - i) % (mo - 1);
		ans = (ans + (ll)temp * pow(3, tt) % mo) % mo;
	}
	int tmp = 0;
	last = 1;
	for (int i = 1; i <= n; i++)
	{
		last = (mo - last) % mo;
		int temp = (pow(mo - pow(3, mo - 1 - n + i) + 1, n) - 1 + mo) % mo;
        int tt = (ll)n * (n - i) % (mo - 1);
		tmp = (tmp + (ll)last * calc(n, i) % mo * temp % mo * pow(3, tt) % mo) % mo;
	}
	//printf("%d %d %d\n", ans, tmp, ((long long)3 * tmp % mo + ans) % mo);
	ans = ((long long)3 * tmp % mo + ans) % mo;
	printf("%d", (mo - ans) % mo);
	return 0;
}