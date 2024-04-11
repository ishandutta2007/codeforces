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
const int MAXN = 65;
const int MAXB = 10;
const int MAXS = ( 1 << 10 ) + 7;

int q;
int b;
LL l, r;
int a[MAXN];
LL dp[MAXB+3][MAXN][MAXS];

void init ();
void input ();
void inputq ();
void work ();

LL getans ( LL x );



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

	lpi ( i, 2, MAXB ) {
		int ms = ( 1 << i );
		dp[i][0][0] = 1;
		lp ( j, 1, MAXN ) {
			lp ( k, 0, ms ) {
				lp ( x, 0, i ) {
					dp[i][j][k^( 1<<x )] += dp[i][j-1][k];
				}
			}
		}
	}
}

void input ()
{
	// input method

	scanf ( "%d", &q );
}

void inputq ()
{
	// input query

	scanf ( "%d%I64d%I64d", &b, &l, &r );
}

void work ()
{
	// main work

	lp ( i, 0, q ) {
		inputq ();
		printf ( "%I64d\n", getans ( r ) - getans ( l - 1 ) );
	}
}



LL getans ( LL x )
{
	if ( !x ) return 0;

	int n = 0;
	for ( LL t = x; t; t /= b ) {
		a[n++] = t % b;
	}

	LL ans = 0;
	int beg, ns = 0;
	lpdi ( i, n-1, 0 ) {
		beg = ( i == n - 1 ) ? 1 : 0;
		lp ( j, beg, a[i] ) {
			ans += dp[b][i][ns^( 1<<j )];
		}
		ns ^= ( 1 << a[i] );
	}
	if ( !ns ) ++ans;

	lpdi ( i, n-2, 0 ) {
		lp ( j, 1, b ) ans += dp[b][i][1<<j];
	}

	return ans;
}