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
const int MAXN = 400007;
const int MOD = 1e9 + 7;

int n;
int x[MAXN];
int a[MAXN], ta[MAXN], tb[MAXN];
int tc[MAXN];

void init ();
void input ();
void work ();

LL qpow ( LL a, LL b )
{
	LL base = a, ans = 1;
	while ( b ){
		if ( b & 1 ) ( ans *= base ) %= MOD;
		( base *= base ) %= MOD;
		b >>= 1;
	}
	return ans;
}

void getC ( int n, int c[] );



int main()
{
	init();
	input();
	work();
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
	lpi ( i, 1, n ) scanf ( "%d", &x[i] );
}

void work ()
{
	// main work

	if ( n % 4 >= 1 ){
		getC ( (n/4*4)/2, tc );
		lp ( i, 0, n ) a[( i<<1 )+1] = tc[i], a[( i<<1 )+2] = 0;

		if ( n % 4 >= 2 ){
			for ( int i = 2; i <= n; i += 2 ) a[i] = a[i-1];

			if ( n % 4 == 3 ){
				memcpy ( ta, a, sizeof ( a ) );
				lpi ( i, 1, n ) tb[i+1] = ta[i];

				int t = -1;
				lpi ( i, 1, n ){
					a[i] = ( ( ta[i] + t * tb[i] ) % MOD + MOD ) % MOD;
					t *= -1;
				}
			}
		}
	} else{
		getC ( n/2-1, tc );
		lp ( i, 0, n ) a[( i<<1 )+1] = tc[i], a[( i<<1 )+2] = ( -tc[i] + MOD ) % MOD;
	}

	int ans = 0;
	lpi ( i, 1, n ) ans = ( ans + 1LL * a[i] * x[i] ) % MOD;

	printf ( "%d\n", ans );
}



void getC ( int n, int c[] )
{
	c[0] = 1;
	lpi ( i, 1, n ){
		c[i] = ( ( 1LL * c[i-1] * ( n - i + 1 ) ) % MOD * qpow ( i, MOD-2 ) ) % MOD;
	}
}