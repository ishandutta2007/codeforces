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
#define mp make_pair
#define fi first
#define se second
#define maxn 200005
using namespace std;
const double INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, s, q, p[maxn], l[maxn], now[maxn];
double ans;
multiset<pair<double, int> > L, R;
inline double calc(int x, int t) {return (double)p[x] * t / (t + l[x]);}
pair<double, int> workl(int x) {return mp(now[x] ? calc(x, now[x]) - calc(x, now[x] - 1) : INF, x);}
pair<double, int> workr(int x) {return mp(now[x] < l[x] ? calc(x, now[x]) - calc(x, now[x] + 1) : INF, x);}
void POP()
{
	int x = (*L.begin()).se;
	ans -= calc(x, now[x]);
	L.erase(workl(x)), R.erase(workr(x));
	now[x]--;
	L.insert(workl(x)), R.insert(workr(x));
	ans += calc(x, now[x]);
	s++;
}
int PUSH()
{
	int x = (*R.begin()).se;
	if(now[x] == l[x]) return 0;
	ans -= calc(x, now[x]);
	L.erase(workl(x)), R.erase(workr(x));
	now[x]++;
	L.insert(workl(x)), R.insert(workr(x));
	ans += calc(x, now[x]);
	s--;
	return 1;
}
int main()
{
	n = read(), s = read(), q = read();
	ru(i, 1, n) p[i] = read();
	ru(i, 1, n) l[i] = read();
	ru(i, 1, n) L.insert(workl(i)), R.insert(workr(i)); 
	while(s > 0 && PUSH());
	while(q--)
	{
		int tp = read(), x = read();
		ans -= calc(x, now[x]);
		L.erase(workl(x)), R.erase(workr(x));
		if(tp == 1)
		{
			l[x]++;
			if(now[x]) now[x]--, s++;
			ans += calc(x, now[x]);
			L.insert(workl(x)), R.insert(workr(x));
			POP();
			while(s > 0 && PUSH());
		}
		else
		{
			l[x]--;
			if(now[x] > l[x]) now[x]--, s++;
			if(now[x] < l[x]) now[x]++, s--;
			ans += calc(x, now[x]);
			L.insert(workl(x)), R.insert(workr(x));
			while(s < 0) POP();
			while(s > 0 && PUSH());
		}
		printf("%.9f\n", ans);
	}
	return 0;
}