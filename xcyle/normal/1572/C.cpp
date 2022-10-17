#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1)
#define maxn 3005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int Tc;
int n, a[maxn], f[maxn][maxn][2], rk[maxn];
vector<int> pos[maxn];
void solve()
{
	n = read(); 
	for (int i = 1; i <= n; i++) pos[i].clear();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		rk[i] = pos[a[i]].size();
		pos[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		f[i][i][0] = f[i][i][1] = 0;
	}
	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			f[i][j][0] = f[i][j][1] = INF;
			for (register int k = rk[i]; k < pos[a[i]].size(); k++)
			{
				int loc = pos[a[i]][k];
				if(loc > j) break;
				f[i][j][1] = min(f[i][j][1], f[i + 1][loc][1] + f[loc + 1][j][1] + ((loc != j) ? 1 : 0));
//			printf("%d %d %d %d\n", i, j, f[i][j][0], f[i][j][1]);
			}
			for (register int k = rk[j]; k >= 0; k--)
			{
				int loc = pos[a[j]][k];
				if(loc < i) break;
				f[i][j][0] = min(f[i][j][0], f[i][loc - 1][0] + f[loc][j - 1][0] + ((loc != i) ? 1 : 0));
//			printf("%d %d %d %d\n", i, j, f[i][j][0], f[i][j][1]);
			}
//			printf("%d %d %d %d\n", i, j, f[i][j][0], f[i][j][1]);
		}
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, f[1][i][1] + f[i][n][0]);
	}
	printf("%d\n", ans);
}
int main()
{
	Tc = read();
	while(Tc--) solve();
	return 0;
}