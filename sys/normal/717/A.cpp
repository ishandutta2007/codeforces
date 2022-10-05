#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205, p = 1e9 + 7;
int k;
long long ans, l, r, fac[Maxn], S[Maxn][Maxn], C[Maxn][Maxn];
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
struct Complex
{
	long long Re, Im;
	Complex (long long _re = 0, long long _im = 0)
	{
		Re = _re, Im = _im;
	}
	Complex operator + (const Complex &A) const
	{
		return (Complex){(Re + A.Re) % p, (Im + A.Im) % p};
	}
	Complex operator - (const Complex &A) const
	{
		return (Complex){(Re - A.Re + p) % p, (Im - A.Im + p) % p};
	}
	Complex operator * (const Complex &A) const
	{
		return (Complex){(Re * A.Re + 5 * Im * A.Im) % p, (Re * A.Im + Im * A.Re) % p};
	}
	Complex operator / (const Complex &A) const
	{
		Complex result = *this * (Complex){A.Re, (p - A.Im) % p};
		return result * (Complex){get_inv((A.Re * A.Re % p + p - 5 * A.Im * A.Im % p) % p), 0};
	}
	bool operator == (const Complex &A) const
	{
		return Re == A.Re && Im == A.Im;
	}
} a, b, x, y;
Complex fast_pow(Complex x, long long y)
{
	Complex ans = (Complex){1, 0}, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
Complex work(Complex x)
{
	if (x == (Complex){1, 0}) return (Complex){(r - l + 1) % p, 0};
	return (fast_pow(x, r + 1) + p - 1) / (x + p - 1) - (fast_pow(x, l) + p - 1) / (x + p - 1);
}
int main()
{
	scanf("%d%lld%lld", &k, &l, &r);
	l += 2, r += 2;
	S[0][0] = C[0][0] = fac[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		fac[i] = fac[i - 1] * i % p;
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
			S[i][j] = (S[i - 1][j - 1] + p - S[i - 1][j] * (i - 1) % p) % p;
		}
	}
	a.Im = get_inv(5), b.Im = p - get_inv(5);
	x.Re = x.Im = y.Re = (p + 1) / 2, y.Im = p - (p + 1) / 2;
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= i; j++)
		{
			Complex tmp = fast_pow(x, j) * fast_pow(y, i - j);
			(ans += (fast_pow(a, j) * fast_pow(b, i - j) * S[k][i] * C[i][j] * work(tmp)).Re) %= p;
		}
	printf("%lld", ans * get_inv(fac[k]) % p);
	return 0;
}