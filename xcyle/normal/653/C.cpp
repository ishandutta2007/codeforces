/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <set>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 150005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
vector<int> mis;
int check(int i)
{
	if(i == n || i == n + 1 || i == 0) return 1;
	if((i & 1) && a[i] >= a[i + 1]) return 0;
	if((i % 2 == 0) && a[i] <= a[i + 1]) return 0;
	return 1;
}
int haha[maxn], cnt;
set<pair<int, int> > p;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) 
	{
		if((i & 1) && a[i] >= a[i + 1]) mis.push_back(i);
		if((i % 2 == 0) && a[i] <= a[i + 1]) mis.push_back(i);
	}
	if(mis.size() > 5) 
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < mis.size(); i++) haha[++cnt] = mis[i], haha[++cnt] = mis[i] + 1;
	sort(haha + 1, haha + cnt + 1);
	int len = unique(haha + 1, haha + cnt + 1) - haha - 1;
	int ans = 0;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= len; j++)
		{
			if(i == haha[j]) continue;
			swap(a[i], a[haha[j]]);
			int flag = 1;
			if(!check(haha[j] - 1)) flag = 0;
			if(!check(haha[j])) flag = 0;
			if(!check(haha[j] + 1)) flag = 0;
			if(!check(i)) flag = 0;
			if(!check(i + 1)) flag = 0;
			if(!check(i - 1)) flag = 0;
			for (int k = 0; k < mis.size(); k++)
			{
				if(!check(mis[k])) flag = 0;
			}
			int x = i, y = haha[j];
			if(x > y) swap(x, y);
			if(flag)
			{
				 p.insert(make_pair(x, y));
//				 printf("%d %d\n", x, y);
			}
			swap(a[i], a[haha[j]]);
		}
	}
	printf("%d", p.size());
	return 0;
}