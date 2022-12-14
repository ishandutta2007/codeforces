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
const int MAXN = 1007;

int ax, ay, bx, by, cx, cy;

void init ();
void input ();
void work ();

void gen ( int sx, int sy, int tx, int ty, AR(PII) &ans )
{
	while ( sx < tx ) ans.push_back ( MP ( sx++, sy ) );
	while ( sx > tx ) ans.push_back ( MP ( sx--, sy ) );
	while ( sy < ty ) ans.push_back ( MP ( sx, sy++ ) );
	while ( sy > ty ) ans.push_back ( MP ( sx, sy-- ) );
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
}

void input ()
{
	// input method

	cin >> ax >> ay >> bx >> by >> cx >> cy;
}

void work ()
{
	// main work

	int ans = qabs ( bx - ax ) + qabs ( by - ay );
	int xl = qmin ( ax, bx ), xr = qmax ( ax, bx );
	int yl = qmin ( ay, by ), yr = qmax ( ay, by );
	
	int mini = INF, cv, mx = -1, my = -1;
	lpi ( i, xl, xr ) {
		lpi ( j, yl, yr ) {
			if ( ( cv = qabs ( cx - i ) + qabs ( cy - j ) ) < mini ) {
				mini = cv;
				mx = i, my = j;
			}
		}
	}

	cerr << mini << " " << mx << " " << my << endl;

	AR ( PII ) md;
	gen ( ax, ay, mx, my, md );
	gen ( bx, by, mx, my, md );
	gen ( cx, cy, mx, my, md );
	md.push_back ( MP ( mx, my ) );

	printf ( "%d\n", SC ( int, md.size () ) );
	for ( auto x : md ) printf ( "%d %d\n", x.first, x.second );
}