#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr<< #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x)
{
    x = 0; int c = gc(); int flag = 0;
    while (c < '0' || c > '9') flag |= (c == '-'), c = gc();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) +(c ^ 48), c = gc();
    if (flag) x = -x;
}
template <class T> T _max(T a, T b){return b < a ? a : b;}
template <class T> T _min(T a, T b){return a < b ? a : b;}
template <class T> bool checkmax(T &a, T b){return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b){return b < a ? a = b, 1 : 0;}
const int N = 606;
int n, m, q;
ll g[606][606];
int U[N * N], V[N * N], L[N * N];
pair<pair<int, int>, int> E[N * N];
vector<int> A[606];
ll B[606][606];
void init()
{
	read(n); read(m);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) g[i][j] = (i == j ? 0 : 1000000000000ll);
	for (int i = 1, u, v, w; i <= m; ++i)
	{
		read(u); read(v); read(w);
		g[u][v] = g[v][u] = w;
		E[i] = m_p(m_p(u, v), w);
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				checkmin(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	read(q);
	memset(B, 0xc0, sizeof B);
	for (int i = 1; i <= q; ++i)
	{
		read(U[i]); read(V[i]); read(L[i]);
		A[U[i]].push_back(i);
		for (int j = 1; j <= n; ++j)
		{
			checkmax(B[j][U[i]], L[i] - g[j][V[i]]);
			checkmax(B[j][V[i]], L[i] - g[j][U[i]]);
		}
	}
}

void solve()
{
	int ans = 0;
	for (int id = 1; id <= m; ++id)
	{
		int x = E[id].first.first, y = E[id].first.second, z = E[id].second, flag = 0;
		for (int i = 1; i <= n; ++i)
		{
			ll now = g[i][x] + z;
			if (B[y][i] < now) continue;
			flag = 1;
		}
		if (flag) ++ans;
	}
	printf("%d\n", ans);
}

int main()
{
	//setIO("");
	init();
	solve();
	return 0;
}