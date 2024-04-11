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
#define maxn 100005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[maxn];
vector<int> tmp;
int g[maxn], f[maxn];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		tmp.clear();
		for (int l = 1, r; l <= a[i]; l = r + 1)
		{
			int cnt = (a[i] + l - 1) / l;
			tmp.push_back(cnt);
			f[cnt] = (g[(a[i - 1] + (a[i] / cnt) - 1) / (a[i] / cnt)] + (ll)i * (cnt - 1) % mo) % mo;
			if(cnt == 1) break;
			r = (a[i] - 1) / (cnt - 1);
		}
		ans = (ans + f[1]) % mo;
		for (int j = 0; j < tmp.size(); j++) g[tmp[j]] = f[tmp[j]]; 
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}