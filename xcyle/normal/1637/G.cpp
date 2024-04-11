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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n;
vector<pair<int, int> > ans;
int num[100005];
inline int calc(int x)
{
	int res = 1;
	for (; x; x >>= 1) res <<= 1;
	return res;
}
void work(int n, int dep)
{
	if(!n) return;
	if(n == 1)
	{
		num[dep]++;
		return;
	}
	if(n == 2)
	{
		num[dep]++;
		num[dep * 2]++;
		return;
	}
	int p = calc(n - 1);
	if(p == n)
	{
		num[dep * n]++;
		n--;
	}
	num[dep * p / 2]++;
	//2...2 * n - p;
	for (int i = p / 2 + 1; i <= n; i++)
	{
		ans.push_back(make_pair((p - i) * dep, i * dep));
		num[dep * p]++;
	}
	work(n - p / 2, dep * 2);
	work(p - n - 1, dep);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if(n == 2)
		{
			printf("-1\n");
			continue;
		}
		int p = calc(n - 1);
		ans.clear();
		work(n, 1);
		for (int i = 1; i < p; i <<= 1)
		{
			while(num[i] >= 2)
			{
				ans.push_back(make_pair(i, i));
				num[2 * i]++;
				num[i] -= 2;
				num[0]++;
			}
		}
		for (int i = 1; i < p; i <<= 1)
		{
//			printf("??? %d %d\n", i, num[i]);
			while(num[i] >= 2)
			{
				ans.push_back(make_pair(i, i));
				num[2 * i]++;
				num[i] -= 2;
				num[0]++;
			}
			if(num[i] == 1)
			{
				ans.push_back(make_pair(0, i));
				ans.push_back(make_pair(i, i));
				num[2 * i]++;
				num[i]--;
			}
		}
		for (; num[0]; num[0]--) ans.push_back(make_pair(0, p));
		num[p] = 0;
		printf("%d\n", ans.size());
		for (auto x: ans) printf("%d %d\n", x.first, x.second);
	}
	return 0;
}