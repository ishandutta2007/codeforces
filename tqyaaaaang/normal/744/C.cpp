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
const int MAXN = 17;
const int MAXS = ( 1 << MAXN ) + 7;
const int MAXD = MAXN * MAXN;

int n;
int type[MAXN], va[MAXN], vb[MAXN];
int dp[MAXS][MAXD];
bool used[MAXN];

void init ();
void input ();
void work ();



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

	char ch[10];
	lp ( i, 0, n ){
		scanf ( "%s%d%d", ch, &va[i], &vb[i] );
		if ( ch[0] == 'R' ) type[i] = 0;
		else type[i] = 1;
	}
}

void work ()
{
	// main work

	int cc[2] = { 0 };
/*	lp ( i, 0, n ) ++cc[type[i]];
	if ( cc[0] > cc[1] ){
		lp ( i, 0, n ) type[i] ^= 1, va[i] ^= vb[i], vb[i] ^= va[i], va[i] ^= vb[i];
	}*/

	int ca = 0, cb = 0;
	lp ( i, 0, n ) ca += va[i], cb += vb[i];

	INIT ( dp, -1 );
	dp[0][0] = 0;

	int ms = 1 << n, md = n * n, vs, nd, nxt;
	lp ( sta, 0, ms ){
		lp ( i, 0, n ) used[i] = ( ( sta & ( 1 << i ) ) > 0 );
		cc[0] = cc[1] = 0;
		lp ( i, 0, n ) if ( used[i] ) ++cc[type[i]];
		lpi ( dec, 0, md ){
			if ( dp[sta][dec] ^ -1 ){
				lp ( i, 0, n ){
					if ( !used[i] ){
						vs = sta | ( 1 << i );
						nd = dec + qmin ( cc[0], va[i] );
						nxt = dp[sta][dec] + qmin ( cc[1], vb[i] );
						dp[vs][nd] = qmax ( dp[vs][nd], nxt );
					}
				}
			}
		}
	}

	int ans = INF, now;
	lp ( i, 0, md ){
		if ( dp[ms-1][i] ^ -1 ){
			now = qmax ( ca - i, cb - dp[ms-1][i] );
			ans = qmin ( ans, now );
		}
	}

	printf ( "%d\n", ans + n );
}