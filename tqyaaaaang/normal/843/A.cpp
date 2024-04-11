#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;

int n;
int a[MAXN];
bool vis[MAXN];

void init ();
void input ();
void work ();

AR(int) dfs (int now);



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio (false);
}

void input ()
{
	// input method

	scanf ("%d", &n);
	lpi (i, 1, n) scanf ("%d", &a[i]);
}

void work ()
{
	// main work

	map < int, int > mp;
	lpi (i, 1, n) mp[a[i]] = 0;
	int kc = 0;
	for (auto &x : mp) x.second = ++kc;

	lpi (i, 1, n) a[i] = mp[a[i]];

	AR(AR(int)) ans;
	lpi (i, 1, n) if (!vis[i]) {
		ans.push_back (dfs (i));
	}

	printf ("%d\n", ans.size ());
	int s1 = ans.size (), s2;
	lp (i, 0, s1) {
		s2 = ans[i].size ();
		printf ("%d ", s2);
		lp (j, 0, s2) printf ("%d ", ans[i][j]);
		putchar ('\n');
	}
}



AR(int) dfs (int now)
{
	AR(int) ans;
	while (!vis[now]) {
		vis[now] = true;
		ans.push_back (now);
		now = a[now];
	}
	return ans;
}