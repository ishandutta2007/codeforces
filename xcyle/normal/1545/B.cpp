#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 200005
using namespace std;
const int mo = 998244353;
int T, n, t[2], a[maxn];
char s[maxn];
int fac[maxn], inv[maxn], ifac[maxn];
inline int calc(int x, int y)
{
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			fac[i] = (ll)fac[i - 1] * i % mo;
			inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
			ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
		}
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
		int j = n;
		for (int i = n; i >= 1; i--)
		{
			while((a[j] ||j > i) && j) j--;
			if(j && (i & 1) == (j & 1)) swap(a[i], a[j]);
		}
//		for (int i = 1; i <= n; i++) printf("%d ", a[i]);
//		printf("\n");
		int cnt = 0, num = 0;
		for (int i = 1; i <= n; i += 2)
		{
			if(!a[i] || ! a[i + 1]) break;
			cnt++;
		}
		for (int i = 2 * cnt + 1; i <= n; i++) num += 1 - a[i];
		printf("%d\n", calc(cnt + num, num));
	}
	return 0;
}