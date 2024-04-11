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
int n;
int a[105];
int run(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
		{
			while (x % (i * i) == 0) x /= i * i;
		}
	}
	return x;
}

void init()
{
	read(n);
	int f = 0;
	for (int i = 1, x; i <= n; ++i)
	{
		read(x);
		x = run(x);
		if (x > 1) f = 1;
	}
	if (f) printf("YES\n");
	else printf("NO\n");
}

void solve()
{
}

int main()
{
	//setIO("");
	int t; read(t); while (t--)
	{
		init();
		solve();
	}
	return 0;
}