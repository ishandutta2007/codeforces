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
int n;
int b[105], a[105];
int e[105][105];
int ask1(int x, int y)
{
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	int z; scanf("%d", &z); return z;
}

int ask2(int idx, int id)
{
	printf("2 %d %d", a[idx], id + 1);
	for (int i = 0; i <= id; ++i) printf(" %d", a[i]);
	printf("\n");
	fflush(stdout);
	int z; scanf("%d", &z); return z;
}

void divi(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	divi(l, mid); divi(mid + 1, r);
	int p = l, q = mid + 1, t = l;
	while (p <= mid || q <= r)
	{
		if (p <= mid && (q > r || ask1(a[p], a[q])))
		{
			b[t++] = a[p++];
		}
		else
		{
			b[t++] = a[q++];
		}
	}
	for (int i = l; i <= r; ++i) a[i] = b[i];
}

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) a[i] = i;
	divi(0, n - 1);
}

void solve()
{
	int t = n - 1;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) e[i][j] = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		while (t && ask2(i, t - 1)) --t;
		out(i); outln(t);
		if (t == i)
		{
			for (int p = 0; p < i; ++p)
			{
				for (int q = i; q < n; ++q)
				{
					e[a[q]][a[p]] = 0;
				}
			}
			t = i - 1;
		}
	}
	printf("3\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) printf("%d", e[i][j]);
		printf("\n");
	}
	fflush(stdout);
	int z; scanf("%d", &z); 
	if (z == -1) abort();
}

int main()
{
	//setIO("");
	int t; scanf("%d", &t); while (t--)
	{
		init();
		solve();
	}
	return 0;
}