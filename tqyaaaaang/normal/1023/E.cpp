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
const int MAXN = 2007;

int n;
int s1[MAXN], s2[MAXN], k1, k2;

void init ();
void input ();
void work ();

bool query ( int xl, int xr, int yl, int yr )
{
	printf ( "? %d %d %d %d\n", xl, yl, xr, yr );
	fflush ( stdout );
	char s[5];
	scanf ( "%s", s );
	if ( s[0] == 'B' ) exit ( 0 );
	return ( s[0] == 'Y' );
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

	scanf ( "%d", &n );
}

void work ()
{
	// main work

	int nx = 1, ny = 1;
	while ( nx + ny - 2 < n - 1 ) {
		if ( nx < n && query ( nx + 1, n, ny, n ) ) s1[++k1] = 1, ++nx;
		else s1[++k1] = 0, ++ny;
	}

	nx = ny = n;
	while ( nx + ny - 2 > n - 1 ) {
		if ( ny > 1 && query ( 1, nx, 1, ny - 1 ) ) s2[++k2] = 0, --ny;
		else s2[++k2] = 1, --nx;
	}

	printf ( "! " );
	lpi ( i, 1, k1 ) putchar ( s1[i] ? 'D' : 'R' );
	lpd ( i, k2, 0 ) putchar ( s2[i] ? 'D' : 'R' );
	putchar ( '\n' );
}