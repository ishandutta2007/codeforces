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
const int MAXN = 57;

int n;
int a[MAXN];
int dp[MAXN][2];

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

	dp[n+1][0] = dp[n+1][1] = 0;
	int ns;
	lpd ( i, n, 0 ) {
		lp ( d, 0, 2 ) {
			dp[i][d] = d ? INF : 0;
			ns = 0;
			lpi ( j, i, n ) {
				if ( d ) dp[i][d] = qmin ( dp[i][d], dp[j+1][d^1] + ns );
				else dp[i][d] = qmax ( dp[i][d], dp[j+1][d^1] + a[j] );
				ns += a[j];
			}
		}
	}

	ns = 0;
	lpi ( i, 1, n ) ns += a[i];

	cout << ( ns - dp[1][0] ) << " " << dp[1][0] << endl;
}