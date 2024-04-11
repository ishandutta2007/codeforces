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
#include <unordered_map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
#define B 10005
using namespace std;
const int mod1 = 1e9 + 7;
const int bas1 = 998244353;
const int mod2 = 998244353;
const int bas2 = 48903137;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, len, poww1[maxn], poww2[maxn], id[maxn];
ll tp[maxn];
char t[maxn];
vector<char> s[maxn];
vector<int> Hash1[maxn], Hash2[maxn];
unordered_map<ll, int> buc[2];
int f[maxn], mn[maxn], mx[maxn];
ll ans = 0;
inline bool cmp(int x, int y)
{
	return tp[x] < tp[y];
}
void init()
{
	scanf("%d", &n);
	poww1[0] = 1;
	for (int i = 1; i < maxn; i++) poww1[i] = (ll)poww1[i - 1] * bas1 % mod1;
	poww2[0] = 1;
	for (int i = 1; i < maxn; i++) poww2[i] = (ll)poww2[i - 1] * bas2 % mod2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", t + 1);
		len = strlen(t + 1);
		s[i].push_back('0');
		Hash1[i].push_back(0);
		Hash2[i].push_back(0);
		int now1 = 0, now2 = 0, c = 0;
		for (int j = 1; j <= len; j++)
		{
			s[i].push_back(t[j]);
			now1 = ((ll)now1 * bas1 % mod1 + t[j] - 'a') % mod1;
			now2 = ((ll)now2 * bas2 % mod2 + t[j] - 'a') % mod2;
			Hash1[i].push_back(now1);
			Hash2[i].push_back(now2);
			tp[i] = (tp[i] + poww1[(t[j] - 'a') * 1234]) % mod1;
			c = (c + poww2[(t[j] - 'a') * 4321]) % mod2;
		}
		tp[i] *= c;
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
}
inline ll calc(int t, int l, int r)
{
	int a = (Hash1[t][l - 1] + (ll)poww1[l] * (Hash1[t][len] - (ll)Hash1[t][r] * poww1[len - r] % mod1 + mod1) % mod1) % mod1;
	int b = (Hash2[t][l - 1] + (ll)poww2[l] * (Hash2[t][len] - (ll)Hash2[t][r] * poww2[len - r] % mod2 + mod2) % mod2) % mod2;
	return (ll)a * b;
}
void solve1()
{
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= n; j++) f[j] = 1, mn[id[j]] = mx[id[j]] = s[id[j]][i] - 'a';
		for (int j = i + 1; j <= len; j++)
		{
			int las = 1;
			for (int k = 1; k <= n; k++)
			{
				int nowc = s[id[k]][j] - 'a';
				if(nowc < mn[id[k]]) mn[id[k]] = nowc;
				if(nowc > mx[id[k]]) mx[id[k]] = nowc;
				if(nowc < s[id[k]][j - 1] - 'a') f[id[k]] = 0;
				if(tp[id[k]] != tp[id[k - 1]])
				{
					for (int l = las; l < k; l++) 
					{
						if(!f[id[l]] && (s[id[l]][i] - 'a' == mn[id[l]] || s[id[l]][j] - 'a' == mx[id[l]])) continue;
						buc[f[id[l]]][calc(id[l], i, j)]--;
					}
					las = k;
				}
				if(!f[id[k]] && (s[id[k]][i] - 'a' == mn[id[k]] || nowc == mx[id[k]])) continue;
				buc[f[id[k]]][calc(id[k], i, j)]++;
				ans += buc[f[id[k]] ^ 1][calc(id[k], i, j)];
//				printf("%d %d %d %d\n", i, j, k,  buc[calc(id[k], i, j)][f[id[k]] ^ 1]);
			}
			for (int l = las; l <= n; l++)
			{
				if(!f[id[l]] && (s[id[l]][i] - 'a' == mn[id[l]] || s[id[l]][j] - 'a' == mx[id[l]])) continue;
				buc[f[id[l]]][calc(id[l], i, j)]--;
			}
		}
	}
}
void solve2()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if(tp[i] != tp[j]) continue;
			int pre = 1, suf = len;
			while(pre <= len && s[i][pre] == s[j][pre]) pre++;
			while(suf >= 1 && s[i][suf] == s[j][suf]) suf--;
			int fl = 1;
			for (int k = pre + 1; k <= suf; k++) fl &= (s[i][k] - 'a' > s[i][k - 1] - 'a');
			int fl2 = 1;
			for (int k = pre + 1; k <= suf; k++) fl2 &= (s[j][k] - 'a' > s[j][k - 1] - 'a');
			if(fl ^ fl2 == 1) ans++;
		}
	}
}
void work()
{
//	printf("!!!%lld\n", ans);
	ll tot = 0;
	int las = 1;
	for (int i = 1; i <= n; i++)
	{
		if(tp[id[i]] != tp[id[i - 1]])
		{
			tot += (ll)(i - las) * (i - las - 1) / 2;
			las = i;
		}
	}
	tot += (ll)(n - las) * (n + 1 - las) / 2;
	ll tmp = 1337ll * ((ll)n * (n - 1) / 2 - tot);
	for(int i = 1; i <= n; i++)
	{
		tot -= buc[0][(ll)Hash1[id[i]][len] * Hash2[id[i]][len]];
		buc[0][(ll)Hash1[id[i]][len] * Hash2[id[i]][len]]++;
	}
	ans += 2ll * (tot - ans);
	printf("%lld", ans + tmp);
}
int main()
{
	init();
	if(n >= B) solve1();
	else solve2(); 
	work();
	return 0;
}