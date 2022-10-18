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
const int N = 150005;
int n, m, p, lim;
int a[N];
int tag[N << 2], len[N << 2];
struct myy
{
	int id, tim;
	myy(int i = 0, int t = 0):id(i), tim(t){}
	bool operator < (const myy &rhs) const
	{
		return tim > rhs.tim;
	}
};

struct node
{
	int l; myy a[12];
	node(){l = 0;}
	node(int k, int t)
	{
		a[l = 1] = myy(k, t);
	}
}t[N << 2];
node operator + (node a, node b)
{
	node c = a;
	for (int i = 1; i <= b.l; ++i)
	{
		int added = 0;
		for (int j = 1; j <= c.l; ++j)
		{
			if (b.a[i].id == c.a[j].id) added = 1, c.a[j].tim += b.a[i].tim;
		}
		if (!added) c.a[++c.l] = b.a[i];
	}
	if (c.l > lim)
	{
		sort(c.a + 1, c.a + c.l + 1);
		for (int i = c.l; i > lim; --i)
		{
			for (int j = 1; j <= i; ++j)
			{
				c.a[j].tim -= c.a[i].tim;
			}
		}
		while (c.l && c.a[c.l].tim <= 0) --c.l;
	}
	return c;
}

void push_up(int x)
{
	t[x] = t[x << 1] + t[x << 1 | 1];
}

void push_tag(int x, int num)
{
	tag[x] = num;
	t[x] = node(num, len[x]);
}

void push_down(int x)
{
	if (tag[x])
	{
		push_tag(x << 1, tag[x]);
		push_tag(x << 1 | 1, tag[x]);
		tag[x] = 0;
	}
}

void build(int x, int l, int r)
{
	len[x] = r - l + 1;
	if (l == r)
	{
		t[x] = node(a[l], 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	push_up(x);
}

void update(int x, int l, int r, int L, int R, int num)
{
	if (L <= l && r <= R)
	{
		push_tag(x, num);
		return;
	}
	push_down(x);
	int mid = (l + r) >> 1;
	if (L <= mid) update(x << 1, l, mid, L, R, num);
	if (R > mid) update(x << 1 | 1, mid + 1, r, L, R, num);
	push_up(x);
}

node query(int x, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return t[x];
	push_down(x);
	int mid = (l + r) >> 1;
	if (R <= mid) return query(x << 1, l, mid, L, R);
	if (L > mid) return query(x << 1 | 1, mid + 1, r, L, R);
	return query(x << 1, l, mid, L, R) + query(x << 1 | 1, mid + 1, r, L, R);
}

void init()
{
	read(n); read(m); read(p); lim = 100 / p;
	for (int i = 1; i <= n; ++i) read(a[i]);
	build(1, 1, n);
}

void solve()
{
	int opt, l, r, k;
	for (int rnd = 1; rnd <= m; ++rnd)
	{
		read(opt); read(l); read(r);
		if (opt == 1)
		{
			read(k);
			update(1, 1, n, l, r, k);
		}
		else
		{
			node T = query(1, 1, n, l, r);
			printf("%d", T.l);
			for(int i = 1; i <= T.l; ++i) printf(" %d", T.a[i].id);
			printf("\n");
		}
	}
}

int main()
{
	//setIO("");
	init();
	solve();
	return 0;
}