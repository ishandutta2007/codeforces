#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int K = 205;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
	if (p == 0) return 1;
	if (p == 2 || (p & 1)) return mult(x, bin_pow(x, p - 1));
	return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}

struct Num
{
	ll a, b;

	Num() : a(), b() {}
	Num(ll _a, ll _b) : a(_a), b(_b) {}

	Num operator + (const Num &A) const
	{
		return Num(add(a, A.a), add(b, A.b));
	}
	Num operator - (const Num &A) const
	{
		return Num(sub(a, A.a), sub(b, A.b));
	}
	Num operator * (const Num &A) const
	{
		return Num((a * A.a + 5 * b * A.b) % MOD, (a * A.b + b * A.a) % MOD);
	}
	Num operator / (const Num &A) const
	{
		ll Q = sub(mult(A.a, A.a), mult(5 * A.b, A.b));
		if (Q == 0) throw;
		Q = rev(Q);
		return Num(mult(Q, sub(mult(a, A.a), mult(5 * b, A.b))), mult(Q, sub(mult(b, A.a), mult(a, A.b))));
	}
};

Num bin_pow(Num A, ll p)
{
	if (p == 0) return Num(1, 0);
	if (p == 2 || (p & 1)) return A * bin_pow(A, p - 1);
	return bin_pow(bin_pow(A, p / 2), 2);
}

ll C[K][K];
ll A[K][K];

void precalc()
{
	for (int i = 0; i < K; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < K; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	A[0][0] = 1;
	for (int i = 0; i < K - 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			A[i + 1][j] = sub(A[i + 1][j], mult(i, A[i][j]));
			A[i + 1][j + 1] = add(A[i + 1][j + 1], A[i][j]);
		}
	}
	return;
}

Num calcGeom(Num A, ll n)
{
	if (A.a == 1 && A.b == 0)
	{
		return Num(n % MOD, 0);
	}
	return (bin_pow(A, n) - Num(1, 0)) / (A - Num(1, 0));
}

ll solve(int k, ll r)
{
	Num P1 = Num(rev(2), rev(2)), P2 = Num(rev(2), sub(0, rev(2)));
	Num res = Num();
	for (int m = 0; m <= k; m++)
	{
		Num cur = Num();
		for (int l = 0; l <= m; l++)
		{
			Num x = calcGeom(bin_pow(P2, l) * bin_pow(P1, m - l), r) * Num(C[m][l], 0);
			if (l & 1)
				cur = cur - x;
			else
				cur = cur + x;
		}
		cur = cur / bin_pow(Num(0, 1), m);
		res = res + cur * Num(A[k][m], 0);
	}
	if (res.b != 0) throw;
	return res.a;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();
	int k;
	ll l, r;
	scanf("%d%lld%lld", &k, &l, &r);
	l += 2;
	r += 3;
	ll ans = sub(solve(k, r), solve(k, l));
	for (int i = 1; i <= k; i++)
		ans = mult(ans, rev(i));
	printf("%lld\n", ans);

	return 0;
}