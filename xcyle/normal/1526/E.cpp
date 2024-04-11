#include <iostream>
#include <cstdio>
#define ll long long 
#define maxn 200005
using namespace std;
const int mo = 998244353;

int n, k, s[maxn], rk[maxn];
int fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main()
{
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] =(ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo; 
	}
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		rk[s[i]] = i;
	}
	int cnt = n - 1;
	for (int i = 2; i <= n; i++)
	{
		if(((rk[s[i - 1] + 1] > rk[s[i] + 1] || s[i] == n - 1)) && s[i - 1] != n - 1)
		{
			cnt--;
		}
	}
//	printf("%d", cnt);
	int ans = 0;
	for (int i = 0; i <= cnt; i++)
	{
		ans = (ans + (ll)calc(cnt, i)* calc(k, i + n - cnt) % mo) % mo;
//		printf("%d\n", ans);
	}
	printf("%d", ans);
	return 0;
}