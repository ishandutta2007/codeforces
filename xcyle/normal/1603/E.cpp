#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#define maxn 205
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, mo, fac[maxn], ifac[maxn], inv[maxn];
int f[2][maxn * maxn][maxn], g[2][maxn * maxn];
int cnt1, cnt2;
int main()
{
	scanf("%d%d", &n, &mo);
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	 } 
	ll ans = 0;
	for (int x = max(1, n - 17); x <= n + 1; x++)
	{
		int las = 0, now = 1;
		for (int j = 0; j <= x * (n + 1); j++)
		{
			for (int k = 0; k <= n; k++)
			{
				f[las][j][k] = f[now][j][k] = 0;
			}
			g[las][j] = g[now][j] = 0;
		}
		f[las][x * (x - 1)][0] = 1;
		g[las][x * (x - 1)] = 1;
		for (int i = x; i <= n + 1; i++)
		{
			for (int sum = 0; sum <= x * (i - 1); sum++)
			{
				if(!g[las][sum]) continue;
				int beg = 0;
				if(i != x) beg = max(beg, n - x / (i - x) - 1);
				for (int cnt = beg; cnt <= n; cnt++)
				{
					if(!f[las][sum][cnt]) continue;
//					printf("%d %d %d %d\n", i - 1, sum, cnt, f[las][sum][cnt]);
					for (int nxt = 0; nxt + cnt <= n; nxt++)
					{
						if(i == x && nxt == 0) continue;
						int tmp = sum + x - nxt * i;
						if(tmp < 0) break;
						int val = (ll)f[las][sum][cnt] * ifac[nxt] % mo;
						f[now][tmp][cnt + nxt] = (f[now][tmp][cnt + nxt] + val) % mo;
						g[now][tmp] = 1;
						if(i == n + 1 && nxt + cnt == n) ans += val;
					}
				}
			}
			for (int sum = 0; sum <= x * (n + 1); sum++)
			{
				int beg = 0;
				if(i != x) beg = max(beg, n - x / (i + 1 - x) - 1);
				for (int cnt = beg; cnt <= n; cnt++)
				{
					f[las][sum][cnt] = 0;
				}
				g[las][sum] = 0;
			}
			swap(now, las);
		}
//		printf("%d\n", (ll)ans * fac[n] % mo); 
	}
	ans %= mo;
	printf("%d\n", (ll)ans * fac[n] % mo);
	return 0;
}