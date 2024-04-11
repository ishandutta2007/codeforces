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
const int MAXN = 500007;

int n;
int ia[MAXN];
int a[MAXN];
LL ps[MAXN];

void init ();
void input ();
void work ();

int check ( int tst )
{
	int n = ::n + 1;
	lp ( i, 1, n ) a[i] = ia[i];
	a[n] = tst;
	sort ( a + 1, a + 1 + n );
	reverse ( a + 1, a + 1 + n );

	ps[0] = 0;
	lpi ( i, 1, n ) ps[i] = ps[i - 1] + a[i];

	LL vl, vr;
	int pr = n;
	bool nl = false, nr = false;
	lpi ( i, 1, n ) {
		vl = ps[i];
		vr = SC ( LL, i ) * ( i - 1 );
		while ( pr >= i && a[pr] <= i ) --pr;
		if ( pr >= i ) {
			vr += ps[n] - ps[pr];
			vr += SC ( LL, i ) * ( pr - i );
		} else {
			vr += ps[n] - ps[i];
		}
		if ( vl > vr ) {
			if ( a[i] > tst ) nl = true;
			else nr = true;
		}
	}
	if ( nl && nr ) {
		printf ( "-1\n" );
		exit ( 0 );
	}
	if ( nl ) return -1;
	else if ( nr ) return 1;
	else return 0;
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
	lpi ( i, 1, n ) scanf ( "%d", &ia[i] );
}

void work ()
{
	// main work

	int od = 0; 
	lpi ( i, 1, n ) od ^= ia[i] & 1;

	int l = 0, r = n, mid;
	while ( l < r ) {
		mid = ( l + r ) >> 1;
		if ( check ( mid ) >= 0 ) r = mid;
		else l = mid + 1;
	}
	int cl = l;
	l = 0, r = n;
	while ( l < r ) {
		mid = ( l + r + 1 ) >> 1;
		if ( check ( mid ) <= 0 ) l = mid;
		else r = mid - 1;
	}
	int cr = l;
	bool haveans = false;
	if ( cr - cl >= 3 ) {
		lpi ( i, cl, cr ) if ( ( i & 1 ) == od ) printf ( "%d ", i ), haveans = true;
	} else {
		lpi ( i, cl, cr ) if ( ( i & 1 ) == od && !check ( i ) ) printf ( "%d ", i ), haveans = true;
	}
	if ( haveans ) putchar ( '\n' );
	else printf ( "-1\n" );
}