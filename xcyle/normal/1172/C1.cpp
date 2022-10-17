#include <iostream>
#include <cstdio>
#define maxn 200005
#define maxm 3005
#define ll long long
using namespace std;
const int mo = 998244353;
int n, m, type[maxn], w;
int a[maxn], cnta, tota, ida[maxn];
int b[maxn], cntb, totb, idb[maxn];
int f[maxm][maxm], ans[maxn];
int fac[maxm], ifac[maxm], inv[maxm];
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
inline int up(int x, int step)
{
	int res = 1;
	for(int i = x; i <= x + step - 1; i++)
	{
		res = (ll)res * i % mo;
	}
	return res;
}
inline int down(int x, int step)
{
	int res = 1;
	for (int i = x; i >= x - step + 1; i--)
	{
		res = (ll)res * i % mo; 
	}
	return res;
}
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main()
{
	scanf("%d%d", &n, &m);
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= m; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &type[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w);
		if(type[i]) 
		{
			a[++cnta] = w;
			ida[cnta] = i;
			tota += w;
		}
		else 
		{
			b[++cntb] = w;
			idb[cntb] = i;
			totb += w;
		}
	}
	f[0][0] = 1;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int nowa = tota + j, nowb = totb - (i - j);
			f[i + 1][j + 1] = (f[i + 1][j + 1] + (ll)f[i][j] * nowa % mo * pow(nowa + nowb, mo - 2) % mo) % mo;
			f[i + 1][j] = (f[i + 1][j] + (ll)f[i][j] * nowb % mo * pow(nowa + nowb, mo - 2) % mo) % mo;
		}
	}
	for (int i = 1; i <= cnta; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= m - j; k++)
			{
				int tmp = (ll)f[m][j + k] * pow(up(tota, j + k), mo - 2) % mo 
				* up(a[i], j + 1) % mo * up(tota - a[i], k) % mo * calc(j + k, k) % mo;
				ans[ida[i]] = (ans[ida[i]] + tmp) % mo;
//				if(ida[i] == 1) printf("%d %d %d %d\n", j, k, tmp, ans[ida[i]]);
			}
		}
	}
	for (int i = 1; i <= cntb; i++)
	{
		for (int j = 0; j <= min(m, b[i]); j++)
		{
			for (int k = 0; k <= min(m - j, totb - b[i]); k++)
			{
				if(totb < j + k) break;
				ans[idb[i]] = (ans[idb[i]] + (ll)f[m][m - j - k] * pow(down(totb, j + k), mo - 2) % mo 
				* down(b[i], j + 1) % mo * down(totb - b[i], k) % mo * calc(j + k, k)% mo) % mo;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}
//	printf("%d %d\n", (ll)10 * pow(6, mo - 2) % mo, (ll)(pow(2, mo - 2) + 2 * pow(3, mo - 2)) % mo);
	return 0;
}