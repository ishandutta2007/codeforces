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
const int MAXN = 10007;

struct eT
{
	void setd ( int _t, int _tp, int _x )
	{
		t = _t, tp = _tp, x = _x;
	}

	bool operator < ( const eT &a ) const
	{
		return ( t ^ a.t ) ? ( t < a.t ) : ( tp > a.tp );
	}

	int t, tp, x;
}ev[MAXN * 2];

int n, q, MOD;
int l[MAXN], r[MAXN], a[MAXN];
int dp[MAXN];
bool ans[MAXN];

void init ();
void input ();
void work ();



int add ( int x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
	return x;
}

void addv ( int &x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
}

int dec ( int x, int y )
{
	x -= y;
	if ( x < 0 ) x += MOD;
	return x;
}

void decv ( int &x, int y )
{
	x -= y;
	if ( x < 0 ) x += MOD;
}

int rnd ()
{
	if ( RAND_MAX == 32767 ) {
		return rand () * RAND_MAX + rand ();
	} else {
		return rand ();
	}
}

int rnd ( int l, int r )
{
	return rnd () % ( r - l + 1 ) + l;
}



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

	MOD = rnd ( SC ( int, 1e9 ), SC ( int, 1e9 + 1e8 ) );
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &q );
	lpi ( i, 1, q ) scanf ( "%d%d%d", &l[i], &r[i], &a[i] );
}

void work ()
{
	// main work

	int ke = 0;
	lpi ( i, 1, q ) ev[ke++].setd ( l[i], 1, a[i] ), ev[ke++].setd ( r[i], 0, a[i] );
	sort ( ev, ev + ke );
	ev[ke].t = INF;

	dp[0] = 1;
	int nx, ub;
	lp ( i, 0, ke ) {
		nx = ev[i].x;
		ub = n - nx;
		if ( ev[i].tp ) {
			lpdi ( j, ub, 0 ) addv ( dp[j + nx], dp[j] );
		} else {
			lpi ( j, 0, ub ) decv ( dp[j + nx], dp[j] );
		}
		lpi ( j, 1, n ) if ( dp[j] ) ans[j] = true;
	}

	int ka = 0;
	lpi ( i, 1, n ) if ( ans[i] ) ++ka;
	printf ( "%d\n", ka );
	lpi ( i, 1, n ) if ( ans[i] ) printf ( "%d ", i );
	putchar ( '\n' );
}