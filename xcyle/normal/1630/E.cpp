/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int fac[maxn], ifac[maxn], inv[maxn];
int miu[maxn], vis[maxn], prime[maxn], cntt;
int cnt[maxn], g[maxn], f[maxn];
inline int gcd(int x, int y){return !y ? x : gcd(y, x % y);}
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
inline bool cmp(int x, int y)
{
	return x > y;
}
void solve()
{
	int n = read();
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) cnt[read()]++;
	sort(cnt + 1, cnt + n + 1, cmp);
	int d = 0;
	for (int i = 1; i <= n; i++) d = gcd(d, cnt[i]);
	if(d == n)
	{
		printf("1\n");
		return;
	}
	for (int i = 1; i <= n; i++)// 
	{
		g[i] = f[i] = 0;
		if(n % i != 0 || d % (n / i) != 0) continue;
		g[i] = fac[i];
		for (int j = 1; j <= n && cnt[j]; j++)
		{
			g[i] = (ll)g[i] * ifac[cnt[j] / (n / i)] % mo;
		}
	}
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			f[j] = (f[j] + (mo + miu[j / i] * g[i]) % mo) % mo;
		}
		if(n % i != 0 || d % (n / i) != 0) continue;
		tot = (tot + (ll)f[i] * inv[i] % mo) % mo;
	}
	for (int i = 1; i <= n; i++)// 
	{
		g[i] = f[i] = 0;
		if(n % i != 0 || d % (n / i) != 0) continue;
		g[i] = 0;
		int tmp = 1;
		for (int j = 1; j <= n && cnt[j]; j++)
		{
			tmp = (ll)tmp * ifac[cnt[j] / (n / i)] % mo;
		}
		for (int j = 1; j <= n && cnt[j]; j++)
		{
			int num = cnt[j] / (n / i);
//			printf("? %d\n", num);
			if(num >= 2) g[i] = (g[i] + (ll)tmp * fac[num] % mo * ifac[num - 2] % mo) % mo;
		}
		g[i] = (ll)g[i] % mo * fac[i - 2] % mo;
//		printf("! %d %d %d\n", i, tmp, g[i]);
	}
	int tot2 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			f[j] = (f[j] + (mo + miu[j / i] * g[i]) % mo) % mo;
		}
		if(n % i != 0 || d % (n / i) != 0) continue;
//		printf("%d\n", f[i]);
		tot2 = (tot2 + (ll)f[i] * (n / i) % mo) % mo;
	}
//	printf("%d %d\n", tot, tot2);
	printf("%d\n", (ll)((ll)tot * n % mo + mo - tot2) % mo * pow(tot, mo - 2) % mo);
}
int main()
{
	fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	miu[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		if(!vis[i])
		{
			miu[i] = -1;
			prime[++cntt] = i;
		}
		for (int j = 1; j <= cntt && i * prime[j] < maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				miu[i * prime[j]] = 0;
				break;
			}
			miu[i * prime[j]] = -miu[i];
		}
	}
	int T = read();
	while(T--) solve(); 
	return 0;
}