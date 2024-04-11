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

struct iT
{
	void setd ( int _p, int _t, int _i )
	{
		p = _p, t = _t, id = _i;
	}

	bool operator < ( const iT &a ) const
	{
		return p < a.p;
	}

	int p, t, id;
}ix[MAXN], iy[MAXN];

struct cT
{
	void setd ( int _x, int _y )
	{
		x = _x, y = _y;
	}

	int x, y;
}ans[MAXN];

int n, w, h, cx, cy;
AR ( int ) _ay[MAXN*2+7], *ay = _ay+MAXN;
AR ( int ) _nq[MAXN*2+7], *nq = _nq+MAXN;
int _ni[MAXN*2+7], *ni = _ni+MAXN;



void init ();
void input ();
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

	scanf ( "%d%d%d", &n, &w, &h );

	int g, p, t;
	cx = cy = 0;
	lpi ( i, 1, n ) {
		scanf ( "%d%d%d", &g, &p, &t );

		if ( g == 1 ) ix[++cx].setd ( p, t, i );
		else iy[++cy].setd ( p, t, i );
	}
}

void work ()
{
	// main work

	sort ( ix+1, ix+cx+1 );
	sort ( iy+1, iy+cy+1 );

	lpi ( i, 1, cy ) {
		ay[iy[i].t-iy[i].p].push_back ( i );
	}
	int size;
	lp ( i, -MAXN+1, MAXN ) {
		size = ay[i].size ();
		lpdi ( j, size-1, 0 ) {
			nq[i].push_back ( iy[ay[i][j]].id );
		}
		ni[i] = 0;
	}

	int nt;
	lpi ( i, 1, cx ) {
		nt = ix[i].t - ix[i].p;
		if ( ay[nt].size () ) {
			nq[nt].push_back ( ix[i].id );
			ix[i].id = nq[nt][ni[nt]++];
		}
	}

	int last;
	lp ( i, -MAXN+1, MAXN ) {
		size = ay[i].size ();
		last = nq[i].size ();
		lp ( j, 0, size ) {
			iy[ay[i][j]].id = nq[i][last-j-1];
		}
	}

	lpi ( i, 1, cx ) {
		ans[ix[i].id].setd ( ix[i].p, h );
	}
	lpi ( i, 1, cy ) {
		ans[iy[i].id].setd ( w, iy[i].p );
	}

	lpi ( i, 1, n ) {
		printf ( "%d %d\n", ans[i].x, ans[i].y );
	}
}