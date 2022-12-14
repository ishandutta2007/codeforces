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
const int MAXN = 13;
const int MAX = 207;
const int CMAX = 203;

struct pT
{
	pT ( int _x = 0, int _y = 0 ) : x ( _x ), y ( _y ) {}

	int x, y;
}pt1[MAXN], pt2[MAXN];

int n;
int _cl1[MAX*2], *cl1 = _cl1 + MAX, _cr1[MAX*2], *cr1 = _cr1 + MAX, _cl2[MAX*2], *cl2 = _cl2 + MAX, _cr2[MAX*2], *cr2 = _cr2 + MAX;

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

	lpi ( i, 1, 4 ) cin >> pt1[i].x >> pt1[i].y, pt1[i].x *= 2, pt1[i].y *= 2;
	lpi ( i, 1, 4 ) cin >> pt2[i].x >> pt2[i].y, pt2[i].x *= 2, pt2[i].y *= 2;
}

void work ()
{
	// main work

	INIT ( _cl1, 0x3f3f3f3f );
	INIT ( _cr1, -0x3f3f3f3f );
	INIT ( _cl2, 0x3f3f3f3f );
	INIT ( _cr2, -0x3f3f3f3f );

	int xl = INF, xr = -INF, yl = INF, yr = -INF, xm = 0, ym = 0;
	lpi ( i, 1, 4 ) {
		xl = qmin ( xl, pt1[i].x );
		xr = qmax ( xr, pt1[i].x );
		yl = qmin ( yl, pt1[i].y );
		yr = qmax ( yr, pt1[i].y );
	}
	lpi ( i, xl, xr ) cl1[i] = yl, cr1[i] = yr;

	xl = INF, xr = -INF, yl = INF, yr = -INF, xm = 0, ym = 0;
	lpi ( i, 1, 4 ) {
		xl = qmin ( xl, pt2[i].x );
		xr = qmax ( xr, pt2[i].x );
		yl = qmin ( yl, pt2[i].y );
		yr = qmax ( yr, pt2[i].y );
		xm += pt2[i].x, ym += pt2[i].y;
	}
	xm = ( xm - xl - xr ) >> 1, ym = ( ym - yl - yr ) >> 1;
	lpi ( i, xl, xm ) cl2[i] = ym - ( i - xl ), cr2[i] = ym + ( i - xl );
	lpi ( i, xm + 1, xr ) cl2[i] = ym - ( xr - i ), cr2[i] = ym + ( xr - i );

	lpi ( i, -CMAX, CMAX ) {
		lpi ( j, -CMAX, CMAX ) {
			if ( j >= cl1[i] && j <= cr1[i] && j >= cl2[i] && j <= cr2[i] ) {
				cout << "YES" << endl;
				return;
			}
		}
	}

	cout << "NO" << endl;
}