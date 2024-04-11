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
#define maxn 2000005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, r;
int fac[maxn], ifac[maxn], inv[maxn];
inline int calc(int x, int y)
{
	if(x < y || y < 0) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
vector<int> a[maxn];
void solve()
{
	scanf("%d%d", &r, &n);
	int ans = 1;
	for (int i = 0; i < a[n].size(); i++)
	{
//		printf("%d ", a[i]);
		ans = (ll)ans * ((ll)2 * calc(a[n][i] + r - 1, r) % mo + calc(a[n][i] + r - 1, r - 1)) % mo;
	}
	printf("%d\n", ans);
}
int main()
{
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	for (int i = 2; i < maxn; i++)
	{
		if(a[i].size()) continue;
		for (int j = i; j < maxn; j += i)
		{
			int tmp = j / i;
			if(tmp % i != 0) a[j].push_back(1);
			else a[j].push_back(a[tmp][a[tmp].size() - 1] + 1);
		}
	}
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}