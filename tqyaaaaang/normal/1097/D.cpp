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
const int MAXL = 63;
const int MAXK = 10007;
const int MOD = SC ( int, 1e9 + 7 );

LL n;
int K;
int frac[MAXL], cf[MAXL];
int dp[MAXL][MAXK];
int frc[MAXL], rf[MAXL], rev[MAXL];

void init ();
void input ();
void work ();



int add ( int x, int y )
{
	return ( ( x += y ) < MOD ) ? x : ( x - MOD );
}

void addv ( int &x, int y )
{
	( ( x += y ) < MOD ) ? x : ( x -= MOD );
}

int sub ( int x, int y )
{
	return ( ( x -= y ) >= 0 ) ? x : ( x + MOD );
}

void subv ( int &x, int y )
{
	( ( x -= y ) >= 0 ) ? x : ( x += MOD );
}

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



int getdp ( int n, int x )
{
	lpi ( i, 0, n ) INIT ( dp[i], 0 );
	dp[n][0] = 1;
	lpdi ( i, n, 0 ) {
		lp ( j, 0, K ) {
			lpi ( k, 0, i ) {
				addv ( dp[k][j + 1], SC ( LL, dp[i][j] ) * rev[i + 1] % MOD );
			}
		}
	}
	int cur = 1, ans = 0;
	lpi ( i, 0, n ) {
		addv ( ans, SC ( LL, cur ) * dp[i][K] % MOD );
		cur = SC ( LL, cur ) * x % MOD;
	}
	return ans;
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

	frc[0] = 1;
	lp ( i, 1, MAXL ) frc[i] = SC ( LL, frc[i - 1] ) * i % MOD;
	rf[MAXL - 1] = qpow ( frc[MAXL - 1], MOD - 2 );
	lpdi ( i, MAXL - 2, 0 ) rf[i] = SC ( LL, rf[i + 1] ) * ( i + 1 ) % MOD;
	lp ( i, 1, MAXL ) rev[i] = SC ( LL, rf[i] ) * frc[i - 1] % MOD;
}

void input ()
{
	// input method

	cin >> n >> K;
}

void work ()
{
	// main work

	LL t = n;
	int kf = 0;
	for ( int i = 2; SC ( LL, i ) * i <= n; ++i ) {
		if ( t % i == 0 ) {
			frac[++kf] = i;
			while ( t % i == 0 ) t /= i, ++cf[kf];
		}
	}
	if ( t > 1 ) frac[++kf] = t % MOD, cf[kf] = 1;

	int ans = 1;
	lpi ( i, 1, kf ) {
		ans = SC ( LL, ans ) * getdp ( cf[i], frac[i] ) % MOD;
	}

	cout << ans << endl;
}