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

const int N = 100005;
int n;
int e = 0, first[N], nxt[N<< 1], point[N << 1];
int dep[N];
void add_edge(int x, int y)
{
	nxt[++e] = first[x];
	first[x] = e;
	point[e] = y;
}

void dfs(int x, int f)
{
	dep[x] = dep[f] + 1;
	for (int i = first[x]; ~i; i = nxt[i])
	{
		int to = point[i];
		if (to == f) continue;
		dfs(to, x);
	}
}

void init()
{
	read(n);
	memset(first, -1, sizeof first);
	for (int i = 1, u, v; i < n; ++i)
	{
		read(u); read(v);
		add_edge(u, v);
		add_edge(v, u);
	}
}

void solve()
{
	dfs(1, 0);
	double ans = 0;
	for (int i = 1; i <= n; ++i) ans += 1.0 / dep[i];
	printf("%.12lf\n", ans);
}

int main()
{
	//setIO("");
	init();
	solve();
	return 0;
}