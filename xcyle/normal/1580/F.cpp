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
#define maxn 550005
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
int g = 3, invg = qpow(3, mo - 2);
inline void add(int &x, int y) {x += y; if(x >= mo) x -= mo;}
int n, m, L, ans, tr[maxn];
void NTT(poly &F, int len, int tp)
{
	ru(i, 0, len - 1) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? (len >> 1) : 0);
	ru(i, 0, len - 1) if(i < tr[i]) swap(F[i], F[tr[i]]); 
	for (int i = 2; i <= len; i <<= 1)
	{
		int bas = qpow(tp ? g : invg, (mo - 1) / i);
		for (int j = 0; j < len; j += i)
		{
//			continue
			int now = 1;
			ru(k, j, j + i / 2 - 1)
			{
				int tmp = (ll)now * F[k + i / 2] % mo;
				F[k + i / 2] = (F[k] + mo - tmp) % mo;
				F[k] = (F[k] + tmp) % mo;
				now = (ll)now * bas % mo;
			}
		}
	} 
	if(!tp)
	{
		int tmp = qpow(len, mo - 2);
		ru(i, 0, len - 1) F[i] = (ll)F[i] * tmp % mo;
	}
} 
poly inv(poly F)
{
	ru(i, 0, L - 1) if(F[i]) F[i] = mo - F[i];
	F[0] = (F[0] + 1) % mo;
	poly G; G.resize(2 * L, 0); G[0] = qpow(F[0], mo - 2);
	for (int i = 2; i <= L; i <<= 1)
	{
		poly tmp; tmp.resize(2 * i, 0);
		ru(j, 0, i - 1) tmp[j] = F[j];
		NTT(tmp, 2 * i, 1);
		poly H = G;
		NTT(G, 2 * i, 1);
		ru(j, 0, 2 * i - 1) G[j] = (ll)G[j] * G[j] % mo * tmp[j] % mo;
		NTT(G, 2 * i, 0);
		ru(j, 0, i - 1) G[j] = ((ll)2 * H[j] % mo + mo - G[j]) % mo;//, printf("%d ", G[j]); printf("\n"); 
		ru(j, i, 2 * i - 1) G[j] = 0;
		//for (auto x: F) printf("%d ", x); printf("\n");
	}
	return G;
}
poly solve(int m)
{
	if(m == 0) 
	{
		poly F; F.resize(L, 0); F[0] = 1;
		return F;
	}
	poly B = solve(m / 2), A; A.resize(L, 0);
	for (int i = 1; i < L; i += 2) swap(A[i], B[i]);
	A[1] = ((m + 1) / 2) % mo;
	poly invA = inv(A);
//	poly tmp = inv(invA);
//	ru(i, 0, 10) printf("%d ", tmp[i]); printf("\n");
//	ru(i, 0, 10) printf("%d ", A[i]); printf("\n");
	ru(i, n + 1, L - 1) invA[i] = 0;
	(n & 1) ? ans = 0 : ans = (ll)ans * 2 % mo; 
	ru(i, 1, n) add(ans, (ll)A[i] * i % mo * invA[n - i] % mo);
//	ru(i, 0, 10) printf("%d ", invA[i]); printf("\n");
//	ru(i, 0, 10) printf("%d ", B[i]); printf("\n"); 
	NTT(B, L, 1), NTT(invA, L, 1);
	ru(i, 0, L - 1) B[i] = (ll)B[i] * B[i] % mo;
	NTT(B, L, 0);
	ru(i, n + 1, L - 1) B[i] = 0;
	NTT(B, L, 1);
	ru(i, 0, L - 1) B[i] = (ll)B[i] * invA[i] % mo; 
	NTT(B, L, 0);
//	for (auto x: B) printf("%d ", x); printf("\n"); 
	ru(i, 0, n) A[i] = (A[i] + B[i]) % mo;
//	for (auto x: A) printf("%d ", x); printf("\n");printf("%d\n", ans);
	return A;
}
int main()
{
//	poly A; A.resize(8, 0); A[0] = A[1] = A[2] = A[3] = 1;
//	for (auto x: A) printf("%d ", x); printf("\n");
//	L = 8, A = inv(A);
//	for (auto x: A) printf("%d ", x); printf("\n");
//	A = inv(A);
//	for (auto x: A) printf("%d ", x); printf("\n");
//	return 0;
	n = read(), m = read();
	L = 1; while(L <= 2 * n) L <<= 1;
	solve(m);
	printf("%d\n", ans); 
	return 0;
}