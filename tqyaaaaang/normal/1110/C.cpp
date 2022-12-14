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
const int MAXN = ( 1 << 25 ) + 7;
const int MAXL = 27;
const int L = 25;

int q;
int tans[MAXL];
int tl[MAXN];
bool sp[MAXN];

void init ();
void input ();
void work ();

int gcd ( int x, int y )
{
	return ( y ? gcd ( y, x%y ) : x );
}

int getfrac ( int n )
{
	for ( int i = 2; i * i <= n; ++i ) if ( n % i == 0 ) return n / i;
	return 1;
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

	scanf ( "%d", &q );
}

void work ()
{
	// main work

	lpi ( i, 1, L ) {
		int v = ( 1 << i ) - 1;
//		cerr << v << endl;
		tl[v] = i;
		sp[v] = true;
		tans[i] = getfrac ( v );
	}
//	lpi ( i, 1, L ) cerr << i << " " << tans[i] << endl;
	lpdi ( i, MAXN - 2, 0 ) if ( !tl[i] ) tl[i] = tl[i + 1];

	int a;
	lp ( _q, 0, q ) {
		scanf ( "%d", &a );
		if ( sp[a] ) printf ( "%d\n", tans[tl[a]] );
		else printf ( "%d\n", ( 1 << tl[a] ) - 1 );
	}
}