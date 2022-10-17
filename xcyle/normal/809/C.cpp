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
#define maxn 300005
using namespace std;
const int mo = 1e9 + 7;
const int inv2 = 5e8 + 4;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int q;
struct node
{
	int l, r;
};
vector<node> n, m;
inline int sum(int l, int r)
{
	return ((ll)(l + r) * (r - l + 1) / 2) % mo;
}
inline int lowbit(int x) {return x & (-x);}
inline int que(int N, int M, int K)
{
	if(N < 0 || M < 0 || K < 0) return 0;
	n.clear(), m.clear();
	n.push_back({N, N}), m.push_back({M, M});
//	printf("%d %d %d\n", N, M, K);
	for (; N; N -= lowbit(N)) n.push_back({N - lowbit(N), N - 1});
	for (; M; M -= lowbit(M)) m.push_back({M - lowbit(M), M - 1});
//	printf("%d %d %d\n", N, M, K);
	int res = 0;
	for (auto A: n) for (auto B: m)
	{
		int nl = A.l, nr = A.r, ml = B.l, mr = B.r;
		int siz = max(nr - nl, mr - ml);
//		printf("%d %d %d %d  ", nl, nr, ml, mr);
		int a = (nl ^ ml); a -= (a & siz);
		int L = a, R = a + siz;
//		printf("%d %d  ", L, R);
		ll cnt = (ll)(nr - nl + 1) * (mr - ml + 1) / (R - L + 1);
		cnt %= mo;
//		printf("!!! %d\n", cnt);
		if(L <= K)
		{
			res = (res + (ll)cnt * sum(L + 1, min(R, K) + 1) % mo) % mo;
//			printf("%d\n", (ll)cnt * sum(L + 1, min(R, K) + 1) % mo);
		}
	}
	return res;
}
int main()
{
	q = read();
	while(q--)
	{
		int xl = read() - 1, yl = read() - 1, xr = read() - 1, yr = read() - 1, k = read() - 1;
		ll tmp = (ll)que(xr, yr, k) - que(xl - 1, yr, k) - que(xr, yl - 1, k) + que(xl - 1, yl - 1, k);
		printf("%d\n", (tmp % mo + mo) % mo);
	}
	return 0;
}