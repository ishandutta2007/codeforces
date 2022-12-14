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
const int MAXN = 150007;

int n;
LL a[MAXN];
int b[MAXN];

void init ();
void input ();
void work ();

int nxt ( int i )
{
	return ( i + 1 <= n ) ? ( i + 1 ) : 1;
}

int prv ( int i )
{
	return ( i - 1 > 0 ) ? ( i - 1 ) : n;
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
	lpi ( i, 1, n ) scanf ( "%d", &b[i] );
}

void work ()
{
	// main work

	int mx = *max_element ( b + 1, b + 1 + n );
	if ( !mx ) {
		printf ( "YES\n" );
		lpi ( i, 1, n ) printf ( "1 " );
		putchar ( '\n' );
		return;
	}

	int np = -1;
	lpi ( i, 1, n ) {
		if ( b[i] ^ mx ) {
			np = i;
			break;
		}
	}
	if ( np == -1 ) {
		printf ( "NO\n" );
		return;
	}
	for ( ; b[np] ^ mx; np = nxt ( np ) );
	a[np] = b[np];
	for ( int i = prv ( np ); i ^ np; i = prv ( i ) ) {
		while ( b[i] >= a[nxt ( i )] ) a[nxt ( i )] += a[nxt ( nxt ( i ) )];
		a[i] = a[nxt ( i )] + b[i];
	}
	while ( b[np] >= a[nxt ( np )] ) a[nxt ( np )] += a[nxt ( nxt ( np ) )];
	printf ( "YES\n" );
	lpi ( i, 1, n ) printf ( "%I64d ", a[i] );
	putchar ( '\n' );
}