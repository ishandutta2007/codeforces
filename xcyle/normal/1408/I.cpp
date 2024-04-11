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
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int n, k, c, a[1 << 17], ifac[20];
int inv2 = (mo + 1) / 2;
int ans[1 << 17];
int g[20], h[20];
inline int count(int t)
{
	int cnt = 0;
	ru(i, 0, c - 1) cnt ^= ((t >> i) & 1);
	return cnt;
}
int B[20];
inline void ln(int *A)
{
	B[0] = 0;
	ru(i, 1, k)
	{
		B[i] = 0;
		B[i] = (ll)i * A[i] % mo;
		ru(j, 0, i - 1) B[i] = (B[i] + mo - (ll)j * B[j] % mo * A[i - j] % mo) % mo;
		B[i] = (ll)B[i] * qpow((ll)i * A[0] % mo, mo - 2) % mo;
	}
	ru(i, 0, k) A[i] = B[i];
}
inline void exp(int *A)
{
	B[0] = 1;
	ru(i, 1, k)
	{
		B[i] = 0;
		ru(j, 0, i - 1) B[i] = (B[i] + (ll)B[j] * (i - j) % mo * A[i - j] % mo) % mo;
		B[i] = (ll)B[i] * qpow(i, mo - 2) % mo;
	}
	ru(i, 0, k) A[i] = B[i];
}
int numcol, cnt[1 << 17];
int V[1 << 17][20];
map<vector<int>, int> col;
int f[1 << 17][20];
int main()
{
	n = read(), k = read(), c = read();
	ru(i, 1, n)
	{
		a[i] = read();
		vector<int> v;
		ru(j, 0, k) v.push_back(a[i] ^ (a[i] - j));
		if(!col[v])
		{
			col[v] = ++numcol;
			ru(j, 0, k) V[numcol][j] = v[j];
		}
		cnt[col[v]]++;
	}
//	printf("!%d\n", numcol);
//	ru(i, 1, numcol) {printf("%d ", cnt[i]);  ru(j, 0, k) printf("%d ", V[i][j]); printf("\n");}
	ifac[19] = 1; ru(i, 1, 19) ifac[19] = (ll)ifac[19] * i % mo;
	ifac[19] = qpow(ifac[19], mo - 2);
	rd(i, 18, 0) ifac[i] = (ll)ifac[i + 1] * (i + 1) % mo;
	ru(i, 0, (1 << (k + 1)) - 1)
	{
		ru(j, 0, k) f[i][j] = (ll)ifac[j] * (((i >> j) & 1) ? mo - 1 : 1) % mo;
		ln(f[i]);
	}
	ru(t, 0, (1 << c) - 1)
	{
		ru(j, 0, k) g[j] = 0;
		ru(i, 1, numcol)
		{
//			printf("%d   ", cnt[i]);
			int st = 0;
			ru(j, 0, k) st |= ((count(t & V[i][j]) & 1) << j);
			ru(j, 0, k) g[j] = (g[j] + (ll)f[st][j] * cnt[i] % mo) % mo;
		}
		exp(g);
//			ru(j, 0, k) printf("%d ", g[j]); printf("\n");
		ans[t] = g[k];
	}
	ru(i, 0, c - 1)
	{
		ru(j, 0, (1 << c) - 1) if((j >> i) & 1)
		{
			int x = ans[j ^ (1 << i)], y = ans[j];
			ans[j ^ (1 << i)] = (ll)(x + y) * inv2 % mo; 
			ans[j] = (ll)(x + mo - y) * inv2 % mo; 
		}
	}
	int tmp = 1, sum = 0;
	ru(i, 1, n) sum ^= a[i];
	ru(i, 1, k) tmp = (ll)tmp * i % mo;
	tmp = (ll)tmp * qpow(qpow(n, mo - 2), k) % mo;
	ru(i, 0, (1 << c) - 1) printf("%d ", (ll)ans[i ^ sum] * tmp % mo);
	return 0;
}