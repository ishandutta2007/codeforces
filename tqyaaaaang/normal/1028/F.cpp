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
const int MAXN = 200007;

int gcd ( int x, int y )
{
	return y ? gcd ( y, x%y ) : x;
}

struct pT
{
	pT ( int _x = 0, int _y = 0 ) : x ( _x ), y ( _y ) {}

	pT operator + ( const pT &a ) const
	{
		return pT ( x + a.x, y + a.y );
	}

	void operator += ( const pT &a )
	{
		x += a.x, y += a.y;
	}

	pT operator - ( const pT &a ) const
	{
		return pT ( x - a.x, y - a.y );
	}

	void operator -= ( const pT &a )
	{
		x -= a.x, y -= a.y;
	}

	LL len2 () const
	{
		return SC ( LL, x ) * x + SC ( LL, y ) * y;
	}

	pT adj () const
	{
		if ( !x && !y ) return pT ( 0, 0 );
		int nx = x, ny = y;
		if ( ny < 0 || ( ny == 0 && nx < 0 ) ) nx = -nx, ny = -ny;
		int g = gcd ( qabs ( x ), qabs ( y ) );
		return pT ( nx / g, ny / g );
	}

	bool operator < ( const pT &a ) const
	{
		return ( x ^ a.x ) ? ( x < a.x ) : ( y < a.y );
	}

	int x, y;
};

int m;
int ac;
map < pT, int > cc, pc;
map < LL, set < pT > > mp;
int qtp;
pT qp;

void init ();
void input ();
void inputq ();
void work ();

void ins ( pT &p );
void del ( pT &p );
int query ( pT &p );



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

	scanf ( "%d", &m );
}

void inputq ()
{
	// input query

	scanf ( "%d%d%d", &qtp, &qp.x, &qp.y );
}

void work ()
{
	// main work

	lp ( _q, 0, m ) {
		inputq ();

		if ( qtp == 1 ) ins ( qp );
		else if ( qtp == 2 ) del ( qp );
		else printf ( "%d\n", query ( qp ) );
	}
}



void ins ( pT &p )
{
	LL nl = p.len2 ();
	map < LL, set < pT > > ::iterator it = mp.find ( nl );
	if ( it == mp.end () ) {
		mp.insert ( MP ( nl, set < pT > () ) );
		it = mp.find ( nl );
	}
	for ( auto &x : it->second ) ++cc[( p + x ).adj ()];
	++pc[p.adj ()];
	it->second.insert ( p );
	++ac;
}

void del ( pT &p )
{
	LL nl = p.len2 ();
	map < LL, set < pT > > ::iterator it = mp.find ( nl );
	it->second.erase ( p );
	for ( auto &x : it->second ) --cc[( p + x ).adj ()];
	--pc[p.adj ()];
	--ac;
}

int query ( pT &p )
{
	pT tmp = p.adj ();
	return ac - pc[tmp] - ( cc[tmp] + cc[pT ( 0, 0 )] ) * 2;
}