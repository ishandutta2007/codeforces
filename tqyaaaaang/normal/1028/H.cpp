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
const int MAXN = 200007;
const int MAXL = 19;
const int MAX = 5100007;

int n, q;
int a[MAXN];
int frac[MAXN], kf;
int qlg[MAXN], rmq[MAXL][MAXN][MAXL], nxt[MAXN][MAXL], pc[MAX][MAXL];
bool isp[MAXN];
int prm[MAXN], kp;
int ql, qr;

void init ();
void input ();
void inputq ();
void work ();

void getfrac ( int x );
int rmqreq ( int k, int l, int r );



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

	INIT ( isp, true );
	isp[0] = isp[1] = false;
	lp ( i, 2, MAXN ) {
		if ( isp[i] ) prm[++kp] = i;
		for ( int j = 1; j <= kp && prm[j] * i < MAXN; ++j ) {
			isp[prm[j] * i] = false;
			if ( i % prm[j] == 0 ) break;
		}
	}

	qlg[0] = qlg[1] = 0;
	lp ( i, 2, MAXN ) qlg[i] = qlg[i >> 1] + 1;
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &q );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void inputq ()
{
	// input query

	scanf ( "%d%d", &ql, &qr );
}

void work ()
{
	// main work

	int ms, nc, na;
	lpi ( i, 1, n ) {
		getfrac ( a[i] );
		ms = 1 << kf;
		lp ( st, 0, ms ) {
			nc = 1, na = 0;
			lp ( j, 0, kf ) {
				if ( st >> j & 1 ) nc *= frac[j + 1];
				else ++na;
			}
			lp ( j, 0, MAXL - na ) nxt[i][j + na] = qmax ( nxt[i][j + na], pc[nc][j] );
		}
		lp ( st, 0, ms ) {
			nc = 1, na = 0;
			lp ( j, 0, kf ) {
				if ( st >> j & 1 ) nc *= frac[j + 1];
				else ++na;
			}
			pc[nc][na] = i;
		}
	}

	lpi ( i, 1, n ) lp ( j, 0, MAXL ) rmq[j][i][0] = nxt[i][j];
	lp ( k, 0, MAXL ) {
		lp ( j, 1, MAXL ) {
			lpi ( i, 1, n - ( 1 << ( j - 1 ) ) ) {
				rmq[k][i][j] = qmax ( rmq[k][i][j - 1], rmq[k][i + ( 1 << ( j - 1 ) )][j - 1] );
			}
		}
	}

	lp ( _q, 0, q ) {
		inputq ();

		lp ( i, 0, MAXL ) {
			if ( rmqreq ( i, ql, qr ) >= ql ) {
				printf ( "%d\n", i );
				break;
			}
		}
	}
}



void getfrac ( int x )
{
	int t = x, tc;
	kf = 0;
	for ( int i = 1; i <= kp && prm[i] * prm[i] <= x; ++i ) {
		if ( t % prm[i] == 0 ) {
			tc = 0;
			while ( t % prm[i] == 0 ) t /= prm[i], ++tc;
			if ( tc & 1 ) frac[++kf] = prm[i];
		}
	}
	if ( t ^ 1 ) frac[++kf] = t;
}

int rmqreq ( int k, int l, int r )
{
	int g = qlg[r - l + 1];
	return qmax ( rmq[k][l][g], rmq[k][r - ( 1 << g ) + 1][g] );
}