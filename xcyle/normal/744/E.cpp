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
#define maxn 35
#define maxs 100005
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
mt19937 Rand(time(NULL));
int v1[30], v2[30], bas1 = Rand() % mod1 + 1, bas2 = Rand() % mod2 + 1;
int n, len[maxn], pw1[maxs], pw2[maxs];
char s[maxn][maxs];
struct Hash
{
	int hash1[maxs], hash2[maxs], id;
	inline ll val(int l, int r)
	{
		return ((ll)((hash1[r] + mod1 - (ll)hash1[l - 1] * pw1[r - l + 1] % mod1) % mod1) << 30) 
				^ ((hash2[r] + mod2 - (ll)hash2[l - 1] * pw2[r - l + 1] % mod2) % mod2);
	}
}h[maxn];
vector<int> G[4000005];
int d[4000005];
queue<int> q;
inline int f(int x, int y)
{
	if(y > len[x]) return 0;
	return (x << 17) + y;
}
inline int check(int l, int r)
{
//	printf("!!! %d %d\n", l, r);
	ru(i, 0, 4000000) G[i].clear(), d[i] = 0;
	ru(x, l, r) G[0].push_back(f(x, 1)), d[f(x, 1)]++;
	ru(x, l, r) ru(y, 1, len[x])
	{
		ru(j, l, r)
		{
			if(y == 1 && len[j] == len[x]) continue;
			if(y + len[j] - 1 <= len[x])
			{
				if(h[j].val(1, len[j]) == h[x].val(y, y + len[j] - 1))
				{
					G[f(x, y)].push_back(f(x, y + len[j]));
					d[f(x, y + len[j])]++;
				}
			}
			else
			{
				if(h[j].val(1, len[x] - y + 1) == h[x].val(y, len[x]))
				{
					G[f(x, y)].push_back(f(j, len[x] - y + 2));
					d[f(j, len[x] - y + 2)]++;
				}
			}
		}
	}
	while(!q.empty()) q.pop();
	if(!d[0]) q.push(0);
	ru(x, l, r) ru(y, 1, len[x]) if(!d[f(x, y)]) q.push(f(x, y)); 
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for (auto V: G[x])
		{
			d[V]--;
			if(!d[V]) q.push(V);
		}
	}
	ru(i, 0, 4000000) if(d[i]) return 0;
	return 1;
}
int main()
{
	n = read();
	pw1[0] = pw2[0] = 1;
	ru(i, 1, maxs - 1) pw1[i] = (ll)pw1[i - 1] * bas1 % mod1, pw2[i] = (ll)pw2[i - 1] * bas2 % mod2;
	ru(i, 1, 26) v1[i] = Rand() % mod1 + 1, v2[i] = Rand() % mod2 + 1;
	ru(i, 1, n)
	{
		scanf("%s", s[i] + 1); len[i] = strlen(s[i] + 1);
		h[i].id = Rand() % (int)(1e9) + 1;
		ru(j, 1, len[i])
		{
			h[i].hash1[j] = ((ll)h[i].hash1[j - 1] * bas1 % mod1 + v1[s[i][j] - 'a' + 1]) % mod1;
			h[i].hash2[j] = ((ll)h[i].hash2[j - 1] * bas2 % mod2 + v2[s[i][j] - 'a' + 1]) % mod2;
		}
	}
	int ans = 0;
	for (int i = n, j = n; i >= 1; i--)
	{
		while(!check(i, j)) j--;
		ans += j - i + 1;
//		printf("??? %d %d\n", i, j);
	}
	printf("%d\n", ans);
	return 0;
}