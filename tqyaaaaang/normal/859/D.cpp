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
const int MAXN = 7;
const int MAXS = ( 1 << 6 ) + 7;

bool NP[MAXS][MAXS][MAXN];

int n, ms;
int ip[MAXS][MAXS];
LD p[MAXS][MAXS];
LD pd[MAXS][MAXN];
LD dp[MAXS][MAXN];

void init ();
void input ();
void work ();



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
	ms = 1 << n;
	lp ( i, 0, ms ) lp ( j, 0, ms ) scanf ( "%d", &ip[i][j] );
}

void work ()
{
	// main work

	lp ( i, 0, ms ) lp ( v, 0, ms ) lpi ( j, 1, n ) NP[i][v][j] = ( ( i ^ v ) && ( i >> j ) == ( v >> j ) && ( ( i >> ( j - 1 ) & 1 ) ^ ( v >> ( j - 1 ) & 1 ) ) );

	lp ( i, 0, ms ) lp ( j, 0, ms ) p[i][j] = SC ( LD, ip[i][j] ) / 100;

	lp ( i, 0, ms ) pd[i][0] = 1;
	lpi ( j, 1, n ) {
		lp ( i, 0, ms ) {
			lp ( v, 0, ms ) {
				if ( NP[i][v][j] ) {
					pd[i][j] += pd[v][j-1] * p[i][v];
				}
			}
			pd[i][j] *= pd[i][j-1];
		}
	}

	lp ( i, 0, ms ) dp[i][0] = 0;
	LD maxi;
	lpi ( j, 1, n ) {
		lp ( i, 0, ms ) {
			maxi = 0;
			lp ( v, 0, ms ) {
				if ( NP[i][v][j] ) maxi = qmax ( maxi, dp[v][j-1] );
			}
			dp[i][j] = maxi + dp[i][j-1] + ( 1 << ( j - 1 ) ) * pd[i][j];
		}
	}

	maxi = 0;
	lp ( i, 0, ms ) maxi = qmax ( maxi, dp[i][n] );
	printf ( "%.13lf\n", SC ( double, maxi ) );
}