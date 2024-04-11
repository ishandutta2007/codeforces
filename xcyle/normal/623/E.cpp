/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 200005
#define poly vector<int>
using namespace std;
const int mo = 1e9 + 7;
const int mod[3] = {998244353, 1004535809, 469762049};
const ll INF = 4e16;
ll n; int k, len, tr[maxn];
int fac[maxn], ifac[maxn];
inline int qpow(int x, int step, int MO)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % MO;
		x = (ll)x * x % MO;
	}
	return res;
}
inline int INV(int x, int MO) {return qpow(x, MO - 2, MO);}
inline void NTT(poly &f, int tp, int fl)
{
	ru(i, 0, len - 1) if(i < tr[i]) swap(f[i], f[tr[i]]);
	for (int i = 2; i <= len; i <<= 1)
	{
		int bas = qpow(fl ? 3 : INV(3, mod[tp]), (mod[tp] - 1) / i, mod[tp]);
		for (int j = 0; j < len; j += i)
		{
			int now = 1;
			for (int k = j; k < j + i / 2; k++)
			{
				int tmp = (ll)now * f[k + i / 2] % mod[tp];
				f[k + i / 2] = (f[k] + mod[tp] - tmp) % mod[tp];
				f[k] = (f[k] + tmp) % mod[tp];
				now = (ll)now * bas % mod[tp];
			}
		}
	}
	if(!fl)
	{
		int tmp = INV(len, mod[tp]);
		ru(i, 0, len - 1) f[i] = (ll)f[i] * tmp % mod[tp]; 
	}
}
poly solve(int n)
{
	if(n == 1) 
	{
		poly res; res.resize(len, 0);
		ru(i, 1, k) res[i] = 1; 
		return res;
	}
	poly A, B;
	if(n & 1)
	{
		A = solve(n - 1), B = solve(1); 
		ru(i, 0, k) A[i] = (ll)A[i] * qpow(2, i, mo) % mo * ifac[i] % mo;
		ru(i, 0, k) B[i] = (ll)B[i] * ifac[i] % mo;
	}
	else 
	{
		A = B = solve(n / 2);
		ru(i, 0, k) A[i] = (ll)A[i] * qpow(2, (ll)i * (n / 2) % (mo - 1), mo) % mo * ifac[i] % mo;
		ru(i, 0, k) B[i] = (ll)B[i] * ifac[i] % mo;
	}
	poly a[3], b[3];
	ru(i, 0, 2)
	{
		a[i] = A, b[i] = B;
		NTT(a[i], i, 1), NTT(b[i], i, 1);
		ru(j, 0, len - 1) a[i][j] = (ll)a[i][j] * b[i][j] % mod[i];
		NTT(a[i], i, 0);
	}
	ru(i, 0, k)
	{
		__int128 tmp = (ll)(mod[1] + a[1][i] - a[0][i]) * INV(mod[0], mod[1]) % mod[1] * mod[0] + a[0][i];
		tmp = (__int128)(mod[2] + a[2][i] - tmp % mod[2]) * INV((ll)mod[0] * mod[1] % mod[2], mod[2]) % mod[2] * mod[0] * mod[1] + tmp;
//		printf("%d %d %d\n", (ll)a[0][i] * fac[i] % mo, (ll)a[1][i] * fac[i] % mo, (ll)a[2][i] * fac[i] % mo);
		A[i] = tmp % mo * fac[i] % mo;
	}
	return A;
}
void test()
{
	len = 8;
	ru(i, 0, len - 1) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? (len >> 1) : 0);
	poly A = {0, 1, 2, 3, 0, 0, 0, 0};
	NTT(A, 0, 1); ru(i, 0, 7) A[i] = (ll)A[i] * A[i] % mod[0]; NTT(A, 0, 0);
	for (auto x: A) printf("%d ", x); printf("\n"); 
}
int main()
{
//	test();
	fac[0] = 1;
	ru(i, 1, maxn - 1) fac[i] = (ll)fac[i - 1] * i % mo;
	ifac[maxn - 1] = INV(fac[maxn - 1], mo);
	rd(i, maxn - 2, 0) ifac[i] = (ll)ifac[i + 1] * (i + 1) % mo;
	scanf("%lld%d", &n, &k);
	if(n > k) {printf("0\n"); return 0;}
	for (len = 1; len <= 2 * k; len <<= 1);
	ru(i, 0, len - 1) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? (len >> 1) : 0);
	poly tmp = solve(n);
//	ru(i, 0, k) printf("%d ", tmp[i]); printf("\n");
	int ans = 0;
	ru(i, 0, k) ans = (ans + (ll)fac[k] * ifac[i] % mo * ifac[k - i] % mo * tmp[i] % mo) %mo;
	printf("%d\n", ans);
	return 0;
}