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
#define no {printf("-1\n"); return;}
#define maxn 2005
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k; char s[maxn], t[maxn], tmpt[maxn];
vector<pii> ans;
inline int find(char *s, int rk)
{
	ru(i, 1, n) 
	{
		if(s[i] == '1') rk--;
		if(!rk) return i;
	}
	return n + 1;
}
inline void rev(char *s, int l, int r)
{
	ans.push_back(mp(l, r));
	ru(i, l, (l + r) / 2) swap(s[i], s[l + r - i]);
}
void work(char *s) 
{
	rd(i, n, 1) if(s[i] == '0')
	{
		int cnt = 0;
		rd(j, i - 1, 1)
		{
			cnt += s[j] == '1';
			if(cnt == k)
			{
				rev(s, j, i);
//				printf("work %d %d\n", j, i);
				break;
			}
		}
	}
	if(k & 1)
	{
		ru(i, 1, k)
		{
			rev(s, find(s, 1), find(s, k + 1) - 1);
			rev(s, find(s, 2), find(s, k + 2) - 1);
		}
	}
	else
	{
		ru(i, 1, k)
		{
			rev(s, find(s, 1), find(s, k + 1) - 1);
			rev(s, find(s, 1) + 1, find(s, k + 1));
		}
	}
}
char tmp[maxn];
void solve()
{
	ans.clear();
	scanf("%d%d%s%s", &n, &k, s + 1, t + 1); ru(i, 1, n) tmp[i] = s[i], tmpt[i] = t[i];
	int fl = 1; ru(i, 1, n) fl &= (s[i] == t[i]);
	if(fl) {printf("0\n"); return;}
	int cnts = 0, cntt = 0;
	ru(i, 1, n) cnts += s[i] == '1', cntt += s[i] == '1';
	if(cnts != cntt || k == 0 || k > cnts) no;
	if(k == cnts)
	{
		int l1 = 1, l2 = 1, r1 = n, r2 = n;
		rd(i, n, 1) if(s[i] == '1') l1 = i;
		rd(i, n, 1) if(t[i] == '1') l2 = i;
		ru(i, 1, n) if(s[i] == '1') r1 = i;
		ru(i, 1, n) if(t[i] == '1') r2 = i;
		if(r1 - l1 != r2 - l2) no;
		int fl = 1;
		ru(i, 0, r1 - l1) fl &= (s[l1 + i] == t[l2 + i]);
		if(fl) {printf("2\n%d %d\n%d %d\n", l1, r1, min(l1, l2), max(r1, r2)); return;}
		fl = 1;
		ru(i, 0, r1 - l1) fl &= (s[r1 - i] == t[l2 + i]);
		if(fl) {printf("1\n%d %d\n", min(l1, l2), max(r1, r2)); return;}
		no;
	}
	work(t);
	vector<pii> tmpans = ans; ans.clear();
	work(s);
	while(!tmpans.empty()) ans.push_back(tmpans.back()), tmpans.pop_back();
	ru(i, 1, n) if(s[i] != t[i]) no;
	printf("%d\n", ans.size());
	for (auto x: ans) 
	{
		printf("%d %d\n", x.fi, x.se);
		continue;
		int num = 0;
		ru(i, x.fi, x.se) num += tmp[i] == '1';
		assert(num == k);
		ru(i, x.fi, (x.fi + x.se) / 2) swap(tmp[i], tmp[x.fi + x.se - i]);
	}	
	return;
	ru(i, 1, n) assert(tmp[i] == tmpt[i]);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}