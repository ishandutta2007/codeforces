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
const int MAX = 1000000000;

int n;
char buf[13];

void init ();
bool input ();
void work ();

bool query ( int x, int y )
{
	printf ( "? %d %d\n", x, y );
	fflush ( stdout );
	scanf ( "%s", buf );
	if ( buf[0] != 'x' && buf[0] != 'y' ) exit ( 0 );
	return buf[0] == 'x';
}

void answer ( int x )
{
	printf ( "! %d\n", x );
	fflush ( stdout );
}



int main ()
{
	init ();

	while ( input () )
		work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );

	srand ( ( unsigned ) time ( NULL ) );
}

bool input ()
{
	// input method

	scanf ( "%s", buf );
	return buf[0] == 's';
}

void work ()
{
	// main work

	if ( query ( 0, 1 ) ) {
		answer ( 1 );
		return;
	}

	int nx = 1;
	while ( ( nx << 1 ) <= MAX && !query ( nx, nx << 1 ) ) nx <<= 1;

	int l = nx + 1, r = ( nx << 1 ), mid;
	nx <<= 1;
	while ( l < r ) {
		mid = ( l + r ) >> 1;
		if ( query ( mid, nx ) ) l = mid + 1;
		else r = mid;
	}
	answer ( l );
}