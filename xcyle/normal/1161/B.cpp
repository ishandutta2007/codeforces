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
const int mod = 998244353;
const int bas = 894123;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
ll ans = 0;
vector<int> t[maxn];
int Hash[maxn], poww[maxn];
int check(int x)
{
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 0; j < t[i].size(); j++)
		{
			tmp = (tmp + poww[(t[i][j] + x) % n]) % mod;
		}
		if(tmp != Hash[i]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		if(a > b) swap(a, b);
		int len = b - a, s = a;
		if(2 * (b - a) > n) 
		{
			s = b;
			len = n - (b - a);
		}
		t[len].push_back(a);
		t[len].push_back(b);
//		printf("%d %d\n", len, a);
	}
	poww[0] = 1;
	for (int i = 1; i <= n; i++) poww[i] = (ll)poww[i - 1] * bas % mod;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < t[i].size(); j++)
		{
			Hash[i] = (Hash[i] + poww[t[i][j]]) % mod;
		}
	}
	for (int j = 1; j < n; j++)
	{
		if(n % j == 0)
		{
			if(check(j))
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}