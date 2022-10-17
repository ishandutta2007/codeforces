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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, m, s, a[maxn], cnt[maxn], sav[maxn];
priority_queue<int> las[maxn];
multiset<int> t; 
vector<int> del;
void work(int l, int r)
{
//	printf("! %d %d\n", l, r);
	ru(i, 1, (l - 1) % k) del.push_back(i);
	ru(i, r + 1, r + (m - r) % k) del.push_back(i);
	ru(i, l, r)
	{
		if(cnt[a[i]]) sav[i] = 1, cnt[a[i]]--;
	}
	int need = r - l + 1 - k;
	ru(i, l, r) if(!sav[i] && need)
	{
		need--;
		del.push_back(i);
	}
	printf("%d\n", (int)del.size());
	for (auto x: del) printf("%d ", x);
}
int main()
{
	m = read(), k = read(), n = read(), s = read();
	ru(i, 1, m) a[i] = read();
	ru(i, 1, s) 
	{
		int x = read();
		las[x].push(0);
		cnt[x]++;
	}
	ru(i, 1, maxn - 1) if(!las[i].empty()) t.insert(-las[i].top());
	ru(i, 1, m)
	{
		if(!las[a[i]].empty())
		{
			t.erase(t.find(-las[a[i]].top()));
			las[a[i]].push(-i);
			las[a[i]].pop();
			t.insert(-las[a[i]].top());
		}
//		printf("%d %d\n", (*t.begin()), i);
		if((*t.begin()) && i >= k)
		{
			int L = min(i - k + 1, (*t.begin())), R = i;
			if((L - 1) / k + 1 + (m - R) / k >= n) {work(L, R); return 0;}
		}
	}
	printf("-1\n");
	return 0;
}