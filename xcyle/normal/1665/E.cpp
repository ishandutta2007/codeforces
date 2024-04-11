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
#define mid ((l + r) >> 1)
#define maxn 100005
using namespace std;
const int INF = (1 << 30) - 1;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], q, ans[maxn];
vector<pair<int, int> > que[maxn];
int tot = 1, ch[maxn * 60][2];
struct node
{
	int val[2], pos[2];
	inline node operator + (const node &x) const
	{
		node tmp;
		tmp.val[0] = tmp.val[1] = tmp.pos[0] = tmp.pos[1] = 0;
		if(pos[0] > x.pos[0])
		{
			tmp.pos[0] = pos[0], tmp.val[0] = val[0];
			if(pos[1] > x.pos[0]) tmp.pos[1] = pos[1], tmp.val[1] = val[1];
			else tmp.pos[1] = x.pos[0], tmp.val[1] = x.val[0];
		}
		else
		{
			tmp.pos[0] = x.pos[0], tmp.val[0] = x.val[0];
			if(x.pos[1] > pos[0]) tmp.pos[1] = x.pos[1], tmp.val[1] = x.val[1];
			else tmp.pos[1] = pos[0], tmp.val[1] = val[0];
		}
		return tmp;
	}
}t[maxn * 60], epy;
vector<int> tmp;
inline void modify(int x, int l, int r, int aim, int v)
{
	if(l == r)
	{
		t[x].val[0] = t[x].val[1] = aim;
		t[x].pos[1] = t[x].pos[0];
		t[x].pos[0] = v;
		return; 
	}
	if(!ch[x][0]) ch[x][0] = ++tot;
	if(!ch[x][1]) ch[x][1] = ++tot;
	if(aim <= mid) modify(ch[x][0], l, mid, aim, v);
	else modify(ch[x][1], mid + 1, r, aim, v);
	t[x] = t[ch[x][0]] + t[ch[x][1]];
}
inline node query(int x, int l, int r, int a, int b)
{
	if(!x) return epy;
	if (a <= l && r <= b) return t[x];
	node res = epy;
	if(a <= mid) res = res + query(ch[x][0], l, mid, a, b);
	if(b > mid) res = res + query(ch[x][1], mid + 1, r, a, b);
	return res;
} 
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) que[i].clear();
	for (int i = 1; i <= n; i++) a[i] = read();
	q = read();
	for (int i = 1; i <= q; i++)
	{
		int l = read(), r = read();
		que[r].push_back(make_pair(l, i));
	}
	for (int i = 1; i <= n; i++)
	{
		modify(1, 0, INF, a[i], i);
		for (auto x: que[i])
		{
			tmp.clear();
			int pos = 0;
			for (int j = 30; j >= 0; j--)
			{
				node temp = query(1, 0, INF, pos, pos + (1 << j) - 1);
//				printf("%d %d %d %d\n", temp.pos[0], temp.pos[1], temp.val[0], temp.val[1]); 
				if(temp.pos[1] < x.first)
				{
					if(temp.pos[0] >= x.first) tmp.push_back(temp.val[0]);
					pos += (1 << j);
				}
			}
			node temp = query(1, 0, INF, pos, pos);
			if(temp.pos[0] >= x.first) tmp.push_back(temp.val[0]);
			if(temp.pos[1] >= x.first) tmp.push_back(temp.val[1]);
			ans[x.second] = INF; 
			for (int j = 0; j < tmp.size(); j++) for (int k = j + 1; k < tmp.size(); k++) ans[x.second] = min(ans[x.second], tmp[j] | tmp[k]);
		}
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	for (int i = 1; i <= tot; i++) ch[i][0] = ch[i][1] = 0, t[i] = epy;
	tot = 1;
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}