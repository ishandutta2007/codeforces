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
const int MAXN = 100007;
const int MOD = SC ( int, 1e9 + 9 );

int n, a, b, k;
char s[MAXN];

void init ();
void input ();
void work ();

int add ( int x, int y )
{
	x += y;
	if ( x >= MOD ) x -= MOD;
	return x;
}

int dec ( int x, int y )
{
	x -= y;
	if ( x < 0 ) x += MOD;
	return x;
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

	cin >> n >> b >> a >> k;
	cin >> s;
}

void work ()
{
	// main work

	LL val = 0;
	lp ( i, 0, k ) val = ( val + ( ( s[i] == '+' ) ? 1 : -1 ) * SC ( LL, qpow ( a, i ) ) * qpow ( b, n - i ) % MOD + MOD ) % MOD;

	LL d = SC ( LL, qpow ( a, k ) ) * qpow ( qpow ( b, k ), MOD - 2 ) % MOD;
	int mul = ( n + 1 ) / k;

	if ( d ^ 1 ) d = SC ( LL, dec ( 1, qpow ( d, mul ) ) ) * qpow ( dec ( 1, d ), MOD - 2 ) % MOD;
	else d = mul;

	cout << val * d % MOD << endl;
}