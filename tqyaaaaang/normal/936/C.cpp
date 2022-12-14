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
const int BASE = 26;

int n, l, r;
char s[MAXN], os[MAXN], t[MAXN];
char cs[BASE], ct[BASE];
AR ( int ) ans;

void init ();
void input ();
void work ();

void shift ( int x );



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

	scanf ( "%d%s%s", &n, s+1, t+1 );
}

void work ()
{
	// main work

	n = strlen ( s + 1 );

	lpi ( i, 1, n ) ++cs[s[i] - 'a'], ++ct[t[i] - 'a'];
	lp ( i, 0, BASE ) {
		if ( cs[i] ^ ct[i] ) {
			printf ( "-1\n" );
			return;
		}
	}

	int ni = n;
	lpi ( i, 1, n ) {
		if ( s[i] == t[ni] ) {
			l = r = i;
			break;
		}
	}
	--ni;
	int np;
	for ( ; ni; --ni ) {
		lpi ( i, 1, n ) {
			if ( ( i < l || i > r ) && s[i] == t[ni] ) {
				np = i;
				break;
			}
		}
		if ( l > np ) {
			shift ( n - np );
			shift ( 1 );
		} else {
			shift ( n - np );
			shift ( n - l + 1 );
		}
		shift ( n - l + 1 );
		++r;
	}
	shift ( n );

//	lpi ( i, 1, n ) cerr << s[i];
//	cerr << endl;

	printf ( "%d\n", ans.size () );
	for ( auto x : ans ) printf ( "%d ", x );
	putchar ( '\n' );
}



void shift ( int x )
{
	if ( l >= n - x + 1 ) {
		int tl = l, tr = r;
		l = n - tr + 1, r = n - tl + 1;
	} else l += x, r += x;

	memcpy ( os, s, sizeof ( s ) );
	lpi ( i, 1, x ) s[i] = os[n - i + 1];
	lpi ( i, x + 1, n ) s[i] = os[i - x];

	ans.push_back ( x );
}