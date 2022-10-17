#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 200005
using namespace std;
const int mo = 998244353;
int n, m;
char s[maxn];
int fac[maxn], inv[maxn], ifac[maxn];
inline int Abs(int x)
{
	return x >= 0 ? x : -x;
}
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
	scanf("%d%d%s", &n, &m, s + 1);
	int cnt = 0, num = 0;
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == 'b')
		{
			if(i & 1) cnt++;
			else cnt--;
		}
		else if(s[i] == 'w')
		{
			if(i & 1) cnt--;
			else cnt++;
		}
		else
		{
			num++;
		}
	}
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo; 
	}
	int ans = 0, tmp = 0;
//	printf("%d %d\n", num, cnt);
	for (int i = -n; i <= n; i++)
	{
		if((i + num) % 2 != 0 || (i + cnt) % 4 != 0) continue;
//		printf("%d\n", i);
		ans = (ans + (ll)calc(num, (i + num) / 2) * Abs(i + cnt) % mo) % mo;
		tmp = (tmp + calc(num, (i + num) / 2)) % mo;
	}
//	printf("%d\n", tmp);
	printf("%d\n", (ll)ans * pow(tmp, mo - 2) % mo * pow(2, mo - 3) % mo);
	return 0;
}