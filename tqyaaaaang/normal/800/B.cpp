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
#define PDD pair < double, double >
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

int n;
int x[MAXN], y[MAXN];

void init ();
void input ();
void work ();

double getd ( double a, double b, double c, double x, double y );
void getlf ( double ax, double ay, double bx, double by, double &a, double &b, double &c );



int main()
{
	init();
	input();
	work();
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
	lpi ( i, 1, n ) scanf ( "%d%d", &x[i], &y[i] );
}

void work ()
{
	// main work

	x[0] = x[n], y[0] = y[n];
	x[n+1] = x[1], y[n+1] = y[1];

	double mini = LINF, a, b, c;
	lpi ( i, 1, n ){
		getlf ( x[i+1], y[i+1], x[i-1], y[i-1], a, b, c );
		mini = min ( mini, getd ( a, b, c, x[i], y[i] ) / 2 );
	}

	printf ( "%.9lf\n", mini );
}



void getlf ( double ax, double ay, double bx, double by, double &a, double &b, double &c )
{
	if ( ax == bx ){
		a = 1, b = 0, c = -ax;
	} else{
		a = ( by - ay ) / ( bx - ax ), b = -1, c = ( ay - a * ax );
	}
}

double getd ( double a, double b, double c, double x, double y )
{
	return ( abs ( a * x + b * y + c ) / sqrt ( a * a + b * b ) );
}