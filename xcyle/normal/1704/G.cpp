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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m;
ll a[maxn], b[maxn], ta[maxn], tb[maxn];
map<ll, pair<vector<int>, vector<int> > > pos;
bitset<maxn> st, tmp;
inline ll calc2(int x, int y, int tp)
{
	if((x & 1) != (tp & 1)) x++;
	if((y & 1) != (tp & 1)) y--;
	return x > y ? 0ll : (ll)(x + y) * ((y - x) / 2 + 1) / 2;
}
inline int calc(int x, int y, int tp)
{
	if((x & 1) != (tp & 1)) x++;
	if((y & 1) != (tp & 1)) y--;
	return x > y ? 0 : (y - x) / 2 + 1;
}
int check(int i, ll cnt, ll sum, int tp)
{
	if(i < 0) return !cnt && !sum;
//	printf("!check %d %d %d %d\n", i, cnt, sum, tp);
	if(cnt > calc(0, i, tp) || cnt < -calc(0, i, tp ^ 1)) return 0;
//	printf("!check %d %d %d %d\n", i, cnt, sum, tp);
	int a = tp ^ 1, b = tp;
	ru(j, 0, 1)
	{
		int pos = i / 2 + cnt;
		int tot = 0;
		while(calc(0, pos - 1, b) - calc(pos, i, a) > cnt) tot++, pos--;
		while(calc(0, pos - 1, b) - calc(pos, i, a) < cnt) tot++, pos++;
		assert(tot <= 10);
//		printf("checkcheckcheck%d %d %d %d\n", a, calc(pos, i, a), pos, calc2(0, pos - 1, b) - calc2(pos, i, a));
		if(sum < calc2(0, pos - 1, b) - calc2(pos, i, a)) return 0;
		swap(a, b), cnt = -cnt, sum = -sum;
	}
//	printf("!!!!!!%d %d %d\n", i, cnt, sum);
	return 1;
}
int work(int tp)
{
	ru(i, 1, n) ta[i] = a[i]; ru(i, 1, m) tb[i] = b[i];
	rd(i, n, 1) ta[i] -= ta[i - 1];
	rd(i, n, 1) ta[i] -= ta[i - 1];
	rd(i, m, 1) tb[i] -= tb[i - 1];
	rd(i, m, 1) tb[i] -= tb[i - 1];
//	printf("a: "); ru(i, 1, n) printf("%d ", ta[i]); printf("\n");
//	printf("b: "); ru(i, 1, m) printf("%d ", tb[i]); printf("\n");
	pos.clear();
	ru(i, 1, n) pos[ta[i]].first.push_back(i), pos[ta[i] + 2 * (i & 1) - 1].first.push_back(i);
	ru(i, 3, m) pos[tb[i]].second.push_back(i);
	ru(i, 1, n) st[i] = 1;
	for (auto c: pos)
	{
		for (auto x: c.second.first) tmp[x] = 1;
		for (auto x: c.second.second) st &= (tmp >> (x - 1));
		for (auto x: c.second.first) tmp[x] = 0;
	}
//	printf("! "); ru(i, 1, n - m + 1) printf("%d ", (int)st[i]); printf("\n");
	ru(i, 1, n - m + 1) if((i & 1) == tp && st[i] && check(i, (b[2] - b[1]) - (a[i + 1] - a[i]), b[1] - a[i], i & 1))
	{
		ll cnt = (b[2] - b[1]) - (a[i + 1] - a[i]), sum = b[1] - a[i];
		vector<int> ans;
		ru(j, 1, i + 1)
		{
			if(j & 1) 
			{
				if(check(i - j, cnt - 1, sum - (i + 1 - j), i & 1)) ans.push_back(j), cnt--, sum -= i + 1 - j;
			}
			else if(check(i - j, cnt + 1, sum + (i + 1 - j), i & 1)) ans.push_back(j), cnt++, sum += i + 1 - j;
		}
//		printf("end: %d %d\n", cnt, sum);
		ru(j, 3, m) if(ta[i + j - 1] != tb[j]) ans.push_back(i + j - 1);
		printf("%d\n", ans.size());
		for (auto x: ans) printf("%d ", x); printf("\n");
		return 1;
	}
	return 0;
}
void solve()
{
	n = read(); 
	ru(i, 1, n)
	{
		scanf("%lld", &a[i]);
		if(i % 2 == 0) a[i] = -a[i];
	}
	m = read(); 
	ru(i, 1, m)
	{
		scanf("%lld", &b[i]);
		if(i % 2 == 0) b[i] = -b[i];
	}
	if(work(1)) return;
	ru(i, 1, m) b[i] = -b[i];
	if(!work(0)) printf("-1\n");
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}