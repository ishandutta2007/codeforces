#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105, p = 998244353;
int n, m, k, a[Maxn];
long long p3;
map <int, int> Ma;
struct Matrix
{
	long long val[Maxn][Maxn];
	Matrix ()
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				for (int q = 1; q <= k; q++)
					(ans.val[i][j] += val[i][q] * A.val[q][j]) %= (p - 1);
		return ans;
	}
} res, A;
long long fast_pow(long long x, long long y, int Mod = p)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % Mod;
		now = now * now % Mod;
		y >>= 1;
	}
	return ans;
}
Matrix fast_pow(Matrix x, long long y)
{
	Matrix ans, now = x;
	for (int i = 1; i <= k; i++) ans.val[i][i] = 1;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
int BSGS(int val)
{
	long long now = 1;
	p3 = fast_pow(p3, p - 2);
	for (int i = 0; i <= 20000; i++)
	{
		if (Ma.find(now * val % p) != Ma.end())
			return Ma[now * val % p] + i * 50000;
		now = now * p3 % p;
	}
	return -1;
}
int phi(int x)
{
	int maxi = sqrt(x), result = x;
	for (int i = 2; i <= maxi; i++)
		if (x % i == 0)
		{
			result = result / i * (i - 1);
			while (x % i == 0) x /= i;
		}
	if (x != 1) result = result / x * (x - 1);
	return result;
}
int main()
{
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &a[i]);
	res.val[1][k] = 1;
	for (int i = 2; i <= k; i++)
		A.val[i][i - 1] = 1;
	for (int i = 1; i <= k; i++)
		A.val[i][k] = a[k - i + 1];
	scanf("%d%d", &n, &m);
	int x = (res * fast_pow(A, n - 1)).val[1][1];
	p3 = 1;
	for (int i = 0; i < 50000; i++)
		Ma[p3] = i, p3 = p3 * 3 % p;
	int g = __gcd(x, p - 1), b = BSGS(m), mod = p - 1;
	if (b == -1 || b % g) return puts("-1"), 0;
	x /= g, b /= g, mod /= g;
	printf("%lld", fast_pow(3, b * fast_pow(x, phi(mod) - 1, mod) % mod));
	return 0;
}