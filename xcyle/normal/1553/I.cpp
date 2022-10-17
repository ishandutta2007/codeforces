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
#define poly vector<int>
#define maxn 300005
#define pb push_back
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], tr[maxn];
struct node {poly v[2][2];};
inline int qpow(int x, int step)
{
	int res = 1;
	for(; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int g = 3, invg = qpow(g, mo - 2);
void NTT(poly &f, int n, int tp)
{
	ru(i, 0, n - 1) if(i < tr[i]) swap(f[i], f[tr[i]]);
	for (int i = 2; i <= n; i <<= 1)
	{
		int bas = qpow(tp ? g : invg, (mo - 1) / i);
		for (int j = 0; j < n; j += i)
		{
			int now = 1;
			ru(k, j, j + i / 2 - 1)
			{
//				printf("%d %d\n", f[k + i / 2], now);
				int tmp = (ll)f[k + i / 2] * now % mo;
				f[k + i / 2] = (f[k] + mo - tmp) % mo;
				f[k] = (f[k] + tmp) % mo;
				now = (ll)now * bas % mo;
			}
		}
	}
	if(!tp)
	{
		int tmp = qpow(n, mo - 2);
		for (auto &x: f) x = (ll)x * tmp % mo; 
	}
}
node work(int l, int r)
{
	if(l == r)
	{
		node res;
		ru(j, 0, 1) ru(k, 0, 1) res.v[j][k].resize(2, 0);
		res.v[0][0][0] = 1 + (a[l] != 1);
		res.v[0][1][0] = 2;
		res.v[1][0][1] = 1;
		res.v[1][1][1] = 1;
		return res;
	}
	node L = work(l, mid), R = work(mid + 1, r), res;
	int N = 1;
	while(N <= r - l + 1) N *= 2;
	ru(i, 0, N - 1) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? (N >> 1) : 0);
	ru(i, 0, 1) ru(j, 0, 1)
	{
		res.v[i][j].resize(N, 0);
		while((int)L.v[i][j].size() < N) L.v[i][j].pb(0);
		NTT(L.v[i][j], N, 1);
		while((int)R.v[i][j].size() < N) R.v[i][j].pb(0);
		NTT(R.v[i][j], N, 1);
	}
	ru(i, 0, 1) ru(j, 0, 1) ru(k, 0, 1)
	{
		ru(l, 0, N - 1) res.v[i][k][l] = (res.v[i][k][l] + (ll)L.v[i][j][l] * R.v[j][k][l] % mo) % mo;
	}
	ru(i, 0, 1) ru(j, 0, 1) NTT(res.v[i][j], N, 0);
	return res;
}
void test()
{
	int n = 8;
	poly A, B; A.resize(8, 0), B.resize(8, 0);
	ru(i, 0, 3) A[i] = B[i] = 1; 
	ru(i, 0, 7) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
	NTT(A, 8, 1), NTT(B, 8, 1);
	ru(i, 0, 7) A[i] = (ll)A[i] * B[i] % mo;
	NTT(A, 8, 0);
	ru(i, 0, 7) printf("%d ", A[i]); printf("\n");
}
int main()
{
//	test();
	n = read();
	ru(i, 1, n) a[i] = read();
	int tmp = 0;
	ru(i, 1, n)
	{
		if(i + a[i] - 1 > n) {printf("0\n"); return 0;}
		for (int j = i; j <= i + a[i] - 1; j++)
		{
			if(a[j] != a[i]) {printf("0\n"); return 0;}
		}
		a[++tmp] = a[i];
		i += a[i] - 1;
	}
	n = tmp;
	poly res = work(1, n).v[0][0];
	int fac = 1;
	rd(i, n - 1, 0) fac = (ll)fac * (n - i) % mo, res[i] = (ll)res[i] * fac % mo;
	int ans = 0, temp = 1;
	ru(i, 0, n) ans = (ans + (ll)temp * res[i] % mo) % mo, temp = mo - temp;
	printf("%d\n", ans);
	return 0;
}