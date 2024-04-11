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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 400005
using namespace std;
const int mo = 1e9 + 7;
const int INF = 1e9 + 1;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, tp[maxn], val[maxn];
set<int> now, A, B;
char s[15];
int main()
{
	n = read(); int ans = 1;
	A.insert(0), B.insert(INF);
	ru(i, 1, n)
	{
		scanf("%s%d", s + 1, &val[i]);
		tp[i] = s[2] == 'D';
		if(tp[i]) 
		{
			if(val[i] < (*--A.end())) A.insert(val[i]);
			else if(val[i] > (*B.begin())) B.insert(val[i]);
			else now.insert(val[i]);
		}
		else
		{
			if(now.find(val[i]) != now.end()) ans = (ll)ans * 2 % mo;
			else if(val[i] == (*--A.end())) A.erase(val[i]);
			else if(val[i] == (*B.begin())) B.erase(val[i]);
			else {printf("0\n"); return 0;}
			for (auto x: now) 
			{
				if(x < val[i]) A.insert(x);
				if(x > val[i]) B.insert(x);
			}
			now.clear();
		}
	}
	ans = (ll)ans * ((int)now.size() + 1) % mo;
	printf("%d\n", ans);
	return 0;
}