/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 10005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, col[maxn], buc[maxn], ansl[maxn], ansr[maxn];
void work(int l, int r)
{
	for (int i = 1; i <= n * k; i++)
	{
		if(l <= col[i] && col[i] <= r && !ansl[col[i]])
		{
			if(buc[col[i]])
			{
				ansl[col[i]] = buc[col[i]], ansr[col[i]] = i;
				for (int j = l; j <= r; j++) buc[j] = 0;
			} 
			else buc[col[i]] = i;
		}
	}
	for (int i = l; i <= r; i++) printf("%d %d\n", ansl[i], ansr[i]);
}
int main()
{
	n = read(), k = read();
	for (int i = 1; i <= n * k; i++) col[i] = read();
	for (int i = 1; i + k - 2 <= n; i += k - 1) work(i, i + k - 2);
	work((n / (k - 1)) * (k - 1) + 1, n); 
	return 0;
}