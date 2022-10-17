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
#define maxn 100005
#define int long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], b[maxn];
char A[maxn], B[maxn];
int need[maxn];
queue<int> q;
vector<pair<int, int> > opt;
inline void check(int i)
{
	if(i < 1 || i >= n) return;
	if(need[i] > 0 && a[i] < 9 && a[i + 1] < 9) q.push(i);
	if(need[i] < 0 && a[i] > 0 && a[i + 1] > 0) q.push(i);
} 
signed main()
{
	n = read();
	scanf("%s%s", A + 1, B + 1);
	ru(i, 1, n) a[i] = A[i] - '0', b[i] = B[i] - '0';
	int tmp = 0;
	ru(i, 1, n)
	{
		if(i & 1) tmp += A[i] - B[i];
		else tmp += B[i] - A[i];
	}
	if(tmp != 0) {printf("-1\n"); return 0;}
	int ans = 0;
	ru(i, 1, n - 1)
	{
		need[i] = - need[i - 1] - (A[i] - B[i]);
		ans += abs(need[i]);
	}
	ru(i, 1, n - 1) check(i);
	printf("%lld\n", ans);
	for (int j = 1; j <= (int)1e5 && !q.empty(); j++)
	{
		int i = 1;
		while(!q.empty())
		{
			i = q.front(); q.pop();
			if(need[i] > 0 && (a[i] == 9 || a[i + 1] == 9)) continue;
			if(need[i] < 0 && (a[i] == 0 || a[i + 1] == 0)) continue;
			if(need[i] == 0) continue;
			break;
		}
			if(need[i] > 0 && (a[i] == 9 || a[i + 1] == 9)) break;
			if(need[i] < 0 && (a[i] == 0 || a[i + 1] == 0)) break;
			if(need[i] == 0) break;
		if(need[i] > 0)
		{
			printf("%lld 1\n", i);
			a[i]++, a[i + 1]++, need[i]--;
		}
		else
		{
			printf("%lld -1\n", i);
			a[i]--, a[i + 1]--, need[i]++;
		}
		check(i - 1), check(i), check(i + 1);
	}
	return 0;
}