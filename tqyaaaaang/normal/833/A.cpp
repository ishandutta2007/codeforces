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

#define YES printf ( "Yes\n" ); return;
#define NO printf ( "No\n" ); return;

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 350007;

int n;
int a, b;

void init ();
void input ();
void work ();

int gcd ( int x, int y )
{
	return ( y ? gcd ( y, x%y ) : x );
}



int main()
{
	init();

	int T;
	scanf ( "%d", &T );
	while ( T-- ){
		input();
		work();
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

	scanf ( "%d%d", &a, &b );
}

void work ()
{
	// main work

	int g = gcd ( a, b );

	int la = a / g, lb = b / g;
	if ( g % la || g % lb ) { NO; }

	g /= la;
	g /= lb;

	int g3 = SC ( int, floor ( pow ( g, 1/3.0 ) + 0.5 ) );

	if ( 1LL * g3 * g3 * g3 == g ) { YES; }
	else { NO; }
}