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
#define maxn 1000005
using namespace std;
const ll INF = 1e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int k; ll val[10];
ll dp[maxn];
int a[maxn], tot, tmp[6] = {1, 2, 4, 5, 7, 8};
void init()
{
	int bas = 1;
	ru(i, 1, maxn - 1) dp[i] = -INF;
	int pw = 1;
	while(pw * 2 <= k)
	{
		a[++tot] = pw;
		pw <<= 1;
	}
	k -= (pw - 1);
	if(k > 0) a[++tot] = k;
	ru(i, 0, 5)
	{
		ru(j, 1, tot) if((ll)a[j] * 9 * bas < maxn) rd(k, maxn - 1, a[j] * 9 * bas) dp[k] = max(dp[k], dp[k - a[j] * 9 * bas] + a[j] * val[i] * 3);
		if(k >= 0)
		{
			rd(k, maxn - 1, 0)
			{
				ru(j, 1, 3) if(k >= 3 * bas * j) dp[k] = max(dp[k], dp[k - 3 * bas * j] + j * val[i]);
			}
		}
		rd(k, maxn - 1, 0)
		{
			ru(j, 0, 5) if(k >= tmp[j] * bas) dp[k] = max(dp[k], dp[k - tmp[j] * bas]);
			ru(j, 1, 3) if(k >= 3 * bas * j) dp[k] = max(dp[k], dp[k - 3 * bas * j] + j * val[i]);
		}
		bas *= 10;
	} 
}
int main()
{
	k = read() - 2; ru(i, 0, 5) val[i] = read();
	init(); int q = read();
	while(q--) printf("%lld\n", dp[read()]);
	return 0;
}