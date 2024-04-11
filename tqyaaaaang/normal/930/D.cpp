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
const int MAX = 100007;

struct pT
{
	pT () : x ( 0 ), y ( 0 ) {}
	pT ( int _x, int _y ) : x ( _x ), y ( _y ) {}

	pT trans () const
	{
		return pT ( ( x - y ) >> 1, ( x + y ) >> 1 );
	}

	bool operator < ( const pT &a ) const
	{
		return x < a.x;
	}

	int x, y;
}pt[MAXN], opt[MAXN];

int n;
pT cl[MAXN], cr[MAXN], cu[MAXN], cd[MAXN];
pT al[MAXN], ar[MAXN], au[MAXN], ad[MAXN];

void init ();
void input ();
void work ();

LL getans ( int d );
int geta ( int dx, int dy, bool rx, bool ry, pT cp[], pT ar[] );



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

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d%d", &pt[i].x, &pt[i].y );
}

void work ()
{
	// main work

	LL ans = 0;
	int on = n;
	lpi ( i, 1, n ) opt[i] = pt[i];

	n = 0;
	lpi ( i, 1, on ) if ( ( opt[i].x ^ opt[i].y ) & 1 ) pt[++n] = opt[i];
	ans += getans ( 0 );

	n = 0;
	lpi ( i, 1, on ) if ( !( ( opt[i].x ^ opt[i].y ) & 1 ) ) pt[++n] = opt[i];
	ans += getans ( 1 );

	cout << ans << endl;
}



LL getans ( int d )
{
	int kl = geta ( -1, 0, false, false, cl, al );
	int kr = geta ( 1, 0, true, true, cr, ar );
	int ku = geta ( 0, 1, false, true, cu, au );
	int kd = geta ( 0, -1, true, false, cd, ad );

	lpi ( i, 0, kl ) ++al[i].x, al[i].y = al[i + 1].y;
	lpi ( i, 0, ku ) ++au[i].x, au[i].y = au[i + 1].y;
	ar[kr + 1] = pT ( INF, INF );
	ad[kd + 1] = pT ( INF, -INF );
	int il = 1, ir = 1, iu = 1, id = 1, pl, pr, pu, pd;
	int vl = al[0].y, vr = INF, vu = au[0].y, vd = -INF;
	int pre = -INF, nt;
	LL ans = 0;
	while ( il <= kl && iu <= ku ) {
		pl = al[il].x, pr = ar[ir].x, pu = au[iu].x, pd = ad[id].x;
		nt = qmin ( qmin ( pl, pr ), qmin ( pu, pd ) );
		ans += SC ( LL, nt - pre ) * max ( qmin ( vl, vd ) - qmax ( vr, vu ) + 1, 0 );
		if ( pl == nt ) {
			vl = al[il].y;
			++il;
		} else if ( pr == nt ) {
			vr = ar[ir].y;
			++ir;
		} else if ( pu == nt ) {
			vu = au[iu].y;
			++iu;
		} else {
			vd = ad[id].y;
			++id;
		}
		pre = nt;
	}
	return ans;
}

int geta ( int dx, int dy, bool rx, bool ry, pT cp[], pT ar[] )
{
	lpi ( i, 1, n ) cp[i] = pT ( pt[i].x + dx, pt[i].y + dy ).trans ();
	lpi ( i, 1, n ) {
		if ( rx ) cp[i].x = -cp[i].x;
		if ( ry ) cp[i].y = -cp[i].y;
	}

	sort ( cp + 1, cp + 1 + n );

	int ka = 0;
	lpi ( i, 1, n ) {
		while ( ka && cp[i].y >= ar[ka].y ) --ka;
		if ( !ka || cp[i].x > ar[ka].x ) ar[++ka] = cp[i];
	}

	lpi ( i, 1, n ) {
		if ( rx ) cp[i].x = -cp[i].x;
		if ( ry ) cp[i].y = -cp[i].y;
	}

	lpi ( i, 1, ka ) {
		if ( rx ) ar[i].x = -ar[i].x;
		if ( ry ) ar[i].y = -ar[i].y;
	}

	if ( rx ) reverse ( cp + 1, cp + 1 + n ), reverse ( ar + 1, ar + 1 + ka );

	return ka;
}