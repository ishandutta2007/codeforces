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
const int MOD = 1e9 + 7;

int n;
int ipa, ipb;
LL pa, pb;
int dp[MAXN][MAXN];

void init ();
void input ();
void work ();

int qpow ( int a, int b )
{
	LL base = a, ans = 1;
	while ( b ) {
		if ( b & 1 ) ( ans *= base ) %= MOD;
		( base *= base ) %= MOD;
		b >>= 1;
	}
	return SC ( int, ans );
}

int add ( int x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
	return x;
}

void addv ( int &x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
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

	scanf ( "%d%d%d", &n, &ipa, &ipb );
}

void work ()
{
	// main work

	int rip = qpow ( ipa + ipb, MOD - 2 );
	pa = ( SC ( LL, ipa ) * rip ) % MOD;
	pb = ( SC ( LL, ipb ) * rip ) % MOD;

	dp[1][0] = 1;
	lpi ( i, 1, n ) {
		lp ( j, 0, n ) {
			addv ( dp[i + 1][j], ( dp[i][j] * pa ) % MOD );
			addv ( dp[i][j + i], ( dp[i][j] * pb ) % MOD );
		}
	}

	LL ans = 0;
	int n2 = n << 1;
	lp ( i, 1, n ) {
		lpi ( j, n, n2 ) {
			( ans += SC ( LL, dp[i][j] ) * j ) %= MOD;
		}
	}

	lp ( i, 0, n ) {
		( ans += dp[n][i] * ( i + n + SC ( LL, pa ) * qpow ( pb, MOD - 2 ) % MOD ) % MOD ) %= MOD;
	}

//	ans += qpow ( pa, MOD - 2 ) % MOD;

	cout << ans << endl;
}