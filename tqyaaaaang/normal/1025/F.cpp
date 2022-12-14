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
const int MAXN = 2007;
const LD PI = acos ( -1.0 );
const LD EPS = 1e-11;

struct pT
{
	pT ( int _x = 0, int _y = 0 ) : x ( _x ), y ( _y ) {}

	pT operator + ( const pT &a ) const
	{
		return pT ( x + a.x, y + a.y );
	}

	void operator += ( const pT &a )
	{
		( *this ) = ( *this ) + a;
	}

	pT operator - ( const pT &a ) const
	{
		return ( pT ( x - a.x, y - a.y ) );
	}

	void operator -= ( const pT &a )
	{
		( *this ) = ( *this ) - a;
	}

	LL operator * ( const pT &a ) const
	{
		return SC ( LL, x ) * a.x + SC ( LL, y ) * a.y;
	}

	LL operator ^ ( const pT &a ) const
	{
		return SC ( LL, x ) * a.y - SC ( LL, y ) * a.x;
	}

	LL len2 () const
	{
		return SC ( LL, x ) * x + SC ( LL, y ) * y;
	}

	LD len () const
	{
		return sqrt ( SC ( LD, len2 () ) );
	}

	LD ang () const
	{
		LD ang = atan2 ( y, x );
		if ( ang > PI - EPS ) ang -= 2 * PI;
		return ang;
	}

	int x, y;
}pt[MAXN];

int n;
LD ang[MAXN], ap[MAXN], an[MAXN];
int kp, kn;
int ord[MAXN];

void init ();
void input ();
void work ();

int getc2 ( int n )
{
	return n * ( n - 1 ) >> 1;
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
	lpi ( i, 1, n ) scanf ( "%d%d", &pt[i].x, &pt[i].y );
}

void work ()
{
	// main work

	LL ans = 0;
	int kc, cp, cn, ip, in;
	lpi ( i, 1, n ) {
		kc = 0;
		lpi ( j, 1, n ) if ( i ^ j ) ang[++kc] = ( pt[j] - pt[i] ).ang ();
		sort ( ang + 1, ang + 1 + kc );
		kp = kn = 0;
		lpi ( j, 1, kc ) {
			if ( ang[j] > -EPS ) ap[++kp] = ang[j];
			else an[++kn] = ang[j] + PI;
		}
		cp = kp, cn = kn;
		ip = in = 1;
		while ( ip <= kp || in <= kn ) {
			if ( in > kn || ( ip <= kp && ap[ip] < an[in] ) ) {
				--cp;
				ans += SC ( LL, getc2 ( cp ) ) * getc2 ( cn );
				++cn;
				++ip;
			} else {
				--cn;
				ans += SC ( LL, getc2 ( cp ) ) * getc2 ( cn );
				++cp;
				++in;
			}
		}
	}

	cout << ( ans >> 1 ) << endl;
}