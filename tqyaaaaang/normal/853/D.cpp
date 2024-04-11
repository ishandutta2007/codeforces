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
const int MINF = 0x3f3f3f3f;
const int MAXN = 300007;
const int MAX = 107;

int n;
int a[MAXN], b[MAXN];
int dp[MAXN][MAX];

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
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) a[i] /= 100, b[i] = a[i] / 10;

	INIT ( dp, MINF );
	dp[0][0] = 0;
	lpi ( i, 1, n ) {
		lp ( j, 0, MAX ) {
			if ( dp[i-1][j] ^ MINF ) {
				dp[i][j+b[i]] = qmin ( dp[i][j+b[i]], dp[i-1][j] + a[i] );
				if ( j >= a[i] ) dp[i][j-a[i]] = qmin ( dp[i][j-a[i]], dp[i-1][j] );
				else dp[i][0] = qmin ( dp[i][0], dp[i-1][j] + ( a[i] - j ) );
			}
		}
	}

	int ans = INF;
	lp ( j, 0, MAX ) ans = qmin ( ans, dp[n][j] );

	printf ( "%d\n", ans * 100 );
}