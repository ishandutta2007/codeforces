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
#define mp make_pair
#define se second
#define fi first
using namespace std;
const ll INF = 5e12;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int check(int t)
{
//	printf("%d  ", t);
	int pos = n + 1, las = 0, sum = 0;
	ru(i, 1, n)
	{
		if(t < a[i]) {pos = i; break;}
		t -= a[i];
		if(a[i] == 1000) las = max(las, sum);
		sum += a[i] / 10;
	}
	las = min(las, 1000);
//	printf("%d %d %d\n", pos, sum, las);
	if(pos > n) return 1;
	if(t >= 1000)
	{
		if(las + t >= 2000)
		{
			pos++;
			sum -= 1000;
			t -= 1000; sum += 100;
		}
		else
		{
			while(pos <= n)
			{
				if(a[pos] == 1000)
				{
					t -= 1000; sum += 100;
					pos++;
					break;
				}
				if(sum >= a[pos])
				{
					sum -= a[pos];
					pos++;
				}
				else break;
			}
		}
	}
	sum += t;
	while(pos <= n)
	{
		if(sum >= a[pos])
		{
			sum -= a[pos];
			pos++;
		}
		else return 0;
	}
	return 1;
}
int main()
{
	n = read();
	ru(i, 1, n) a[i] = read();
	int l = 0, r = n * 2000;
	while(l < r)
	{
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}