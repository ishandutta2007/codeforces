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
const int MAXN = 0;

LL a, b, p;

void init ();
void input ();
void work ();

LL gcd ( LL x, LL y )
{
	return ( y ? gcd ( y, x%y ) : x );
}



int main ()
{
	init ();

	int T;
	scanf ( "%d", &T );
	while ( T-- ) {
		input ();
		work ();
	}
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%I64d%I64d%I64d", &a, &b, &p );
}

void work ()
{
	// main work

	LL g = gcd ( a, b );
	a /= g, b /= g;

	g = gcd ( b, p );
	do {
		b /= g;
		g = gcd ( b, g );
	} while ( g ^ 1 );

	printf ( b == 1 ? "Finite\n" : "Infinite\n" );
}