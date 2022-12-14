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
const int MAXN = 50007;
const int T1 = 999;
const int T2 = 999;

int n, st, tar;

void init ();
void input ();
void work ();

PII query ( int x );
void ok ( int x );

int rnd ();
int rnd ( int l, int r );





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

	srand ( ( unsigned ) time ( NULL ) );
}

void input ()
{
	// input method

	scanf ( "%d%d%d", &n, &st, &tar );
}

void work ()
{
	// main work

	AR( PII ) ar;
	ar.push_back ( MP ( query ( st ).first, st ) );
	lp ( i, 0, T1 ) {
		int x = rnd ( 1, n );
		ar.push_back ( MP ( query ( x ).first, x ) );
	}

	sort ( ar.begin (), ar.end () );
	int cs = 0, size = ar.size ();
	lp ( i, 0, size ) {
		if ( i == ( size - 1 ) || ( ar[i+1].first > tar ) ) {
			cs = ar[i].second;
			break;
		}
	}

	int now = cs;
	PII nxt;
	lp ( i, 0, T2 ) {
		nxt = query ( now );
		if ( nxt.first >= tar ) {
			ok ( nxt.first );
			break;
		} else if ( nxt.second == -1 ) {
			ok ( -1 );
			break;
		}
		now = nxt.second;
	}
}



PII query ( int x )
{
	printf ( "? %d\n", x );
	fflush ( stdout );
	PII ret;
	scanf ( "%d%d", &ret.first, &ret.second );
	if ( ret.first == -1 && ret.second == -1 ) exit ( 0 );
	return ret;
}

void ok ( int x )
{
	printf ( "! %d\n", x );
}

int rnd ()
{
	return rand () * 32768 + rand ();
}

int rnd ( int l, int r )
{
	return ( rnd () % ( r - l + 1 ) + l );
}