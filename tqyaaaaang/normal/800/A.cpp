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
const int TM = 157;

struct iT
{
	bool operator < ( const iT &x ) const
	{
		return ( 1LL * b * x.a < 1LL * x.b * a );
	}

	int a, b;
}it[MAXN];

int n, p;

void init ();
void input ();
void work ();

bool check ( double tst );



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

	scanf ( "%d%d", &n, &p );
	lp ( i, 0, n ) scanf ( "%d%d", &it[i].a, &it[i].b );
}

void work ()
{
	// main work

	LL cc = 0;
	lp ( i, 0, n ) cc += it[i].a;
	if ( p >= cc ){
		printf ( "-1\n" );
		return;
	}

	double l = 0, r = pow ( 2, 64 ), mid;
	lp ( i, 0, TM ){
		mid = ( l + r ) / 2;
		if ( check ( mid ) ) l = mid;
		else r = mid;
	}

	printf ( "%.9lf\n", l );
}



bool check ( double tst )
{
	double nd = 0;
	lp ( i, 0, n ){
		if ( it[i].a * tst > it[i].b ) nd += ( it[i].a * tst - it[i].b ) / p;
	}

	return nd <= tst;
}