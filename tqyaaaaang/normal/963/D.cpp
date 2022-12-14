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
const int MAXN = 210007;
const int BASE = 26;

int tmp[MAXN], kt;

class samT
{
public:
	samT ()
	{
		kp = last = 1;
		INIT ( fa, 0 );
		INIT ( ch, 0 );
		INIT ( ml, 0 );
		INIT ( cr, -1 );
	}

	void extend ( int x, int nr )
	{
		int p = last;
		int np = ++kp;
		ml[np] = ml[p] + 1;
		cr[np] = nr;
		while ( p && !ch[p][x] ) ch[p][x] = np, p = fa[p];

		if ( p ) {
			int q = ch[p][x];
			if ( ml[q] == ml[p] + 1 ) fa[np] = q;
			else {
				int nq = ++kp;
				ml[nq] = ml[p] + 1;
				memcpy ( ch[nq], ch[q], sizeof ( ch[q] ) );
				fa[nq] = fa[q];
				fa[q] = fa[np] = nq;
				while ( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
			}
		} else fa[np] = 1;

		last = np;
	}

	void build ()
	{
		INIT ( la, -1 );
		lpi ( i, 2, kp ) edge[ke].setd ( fa[i], i, la[fa[i]] ), la[fa[i]] = ke++;
	}

	int srch ( char s[], int nk )
	{
		int len = strlen ( s ), now = 1;
		lp ( i, 0, len ) {
			now = ch[now][s[i] - 'a'];
		}
		if ( !now ) return -1;
		if ( nk == 1 ) return 0;
		kt = 0;
		dfs ( now );
		sort ( tmp + 1, tmp + 1 + kt );
		int mini = INF;
		lpi ( i, nk, kt ) {
			mini = qmin ( mini, tmp[i] - tmp[i - nk + 1] );
		}
		return mini == INF ? -1 : mini;
	}

	void dfs ( int now )
	{
		if ( ~cr[now] ) tmp[++kt] = cr[now];
		for ( int i = la[now]; ~i; i = edge[i].last ) dfs ( edge[i].v );
	}

private:
	struct eT
	{
		void setd ( int _u, int _v, int _l )
		{
			u = _u, v = _v, last = _l;
		}

		int u, v, last;
	}edge[MAXN];
	int ke, la[MAXN];

	int kp, last;
	int fa[MAXN], ch[MAXN][BASE], ml[MAXN], cr[MAXN];
}sam;

int n, q;
char s[MAXN];
char t[MAXN];
int qk;

void init ();
void input ();
void inputq ();
void work ();



int main ()
{
	init ();
	input ();
	work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%s", s );
	scanf ( "%d", &q );
}

void inputq ()
{
	// input query

	scanf ( "%d%s", &qk, t );
}

void work ()
{
	// main work

	n = strlen ( s );
	lp ( i, 0, n ) sam.extend ( s[i] - 'a', i );
	sam.build ();

	int ret;
	lp ( _q, 0, q ) {
		inputq ();

		ret = sam.srch ( t, qk );
		if ( ret == -1 ) printf ( "%d\n", -1 );
		else printf ( "%d\n", ret + strlen ( t ) );
	}
}