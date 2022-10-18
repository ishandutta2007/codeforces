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
int n, a[N];
int top = 0, sta[N];
int pre[N], suf[N], now[N];
void init()
{
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	sta[++top] = 1;
	for (int i = 2; i < n; ++i)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) sta[++top] = i;
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) sta[++top] = i;
	}
	sta[++top] = n;
}

void solve()
{
	//outarr(sta, 1, top);
	int ans = 0;
	for (int i = 2; i <= top; ++i)
	{
		pre[i] = pre[i - 1];
		now[i] = abs(sta[i] - sta[i - 1]);
		checkmax(pre[i], sta[i] - sta[i - 1]);
	}
	for (int i = top - 1; i >= 1; --i)
	{
		suf[i] = suf[i + 1];
		checkmax(suf[i], abs(sta[i] - sta[i + 1]));
	}
	/*outarr(sta, 1, top);
	outarr(now, 1, top);
	outarr(pre, 1, top);
	outarr(suf, 1, top);*/
	for (int i = 2; i < top; ++i)
	{
		if (a[sta[i]] < a[sta[i - 1]]) continue;
		int l = sta[i] - sta[i - 1];
		int r = sta[i + 1] - sta[i];
		int lx = pre[i - 2];
		int rx = suf[i + 2];
		if (_max(l, r) > lx && _max(l, r) > rx)
		{
			if (l == r)
			{
				if ((r > now[i - 1] && r > now[i]) || (l % 2 == 0 && l > now[i - 1]))
				{
					if ((l > now[i + 1] && l > now[i + 2]) || (r % 2 == 0 && r > now[i + 2]))
					{
						++ans;
					}
				}
			}
		}
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