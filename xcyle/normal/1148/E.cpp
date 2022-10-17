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
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, s[maxn], t[maxn];
int id[maxn], tmp[maxn];
inline bool cmp(int x, int y)
{
	return s[x] < s[y];
}
struct node{int a, b, c;};
vector<node> ans;
int main()
{
	n = read();
	ll sum = 0;
	for (int i = 1; i <= n; i++) s[i] = read(), sum += s[i];
	for (int i = 1; i <= n; i++) t[i] = read(), sum -= t[i];
	if(sum)
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) tmp[i] = s[i], id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) s[i] = tmp[id[i]];
	sort(t + 1, t + n + 1);
	for (int i = 1, j = 1; i <= n; i++)
	{
		if(s[i] > t[i])
		{
			printf("NO\n");
			return 0;
		}
		while(s[i] != t[i])
		{
			while(s[j] <= t[j] && j <= n) j++;
			int tmp = min(t[i] - s[i], s[j] - t[j]);
			s[i] += tmp, s[j] -= tmp;
			ans.push_back({id[i], id[j], tmp});
		}
	}
	printf("YES\n%d\n", ans.size());
	for (auto x: ans) printf("%d %d %d\n", x.a, x.b, x.c); 
	return 0;
}