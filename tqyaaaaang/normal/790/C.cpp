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
#define oabs(a) (((a)>=0)?(a):0)

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 81;
const int BASE = 257;

int n;
char s[MAXN];
int dp[MAXN][MAXN][MAXN][2];
int ip[3][MAXN];
int kc[3];
int cid[BASE];

void init ();
void input ();
void work ();

void upd ( int &var, int x )
{
	var = qmin ( var, x );
}

int getdist ( int pl, int to, int a, int b, int c )
{
//	if ( pl < to ) return 0;
	int tp = pl;
	lpi ( i, 1, a ) if ( ip[0][i] > pl ) ++tp;
	lpi ( i, 1, b ) if ( ip[1][i] > pl ) ++tp;
	lpi ( i, 1, c ) if ( ip[2][i] > pl ) ++tp;
	if ( tp < to ) return 0;
	return tp - to;
}



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

	lpi ( i, 'A', 'Z' ) cid[i] = 0;
	cid['V'] = 1, cid['K'] = 2;
}

void input ()
{
	// input method

	scanf ( "%d%s", &n, s+1 );
}

void work ()
{
	// main work

	lpi ( i, 1, n ){
		ip[cid[s[i]]][++kc[cid[s[i]]]] = i;
	}

	INIT ( dp, 0x3f3f3f3f );
	dp[0][0][0][0] = 0;
	int lr, np;
	lp ( i, 0, n ){
		np = i + 1;
		lpi ( j, 0, qmin(i,kc[1]) ){
			lpi ( k, 0, qmin(i,kc[2]) ){
				lr = i - j - k;
				if ( lr < 0 || lr > kc[0] ) continue;
				lp ( a, 0, 2 ){
					if ( lr < kc[0] ) upd ( dp[i+1][j][k][0], dp[i][j][k][a] + getdist ( ip[0][lr+1], np, lr, j, k ) );
					if ( j < kc[1] ) upd ( dp[i+1][j+1][k][1], dp[i][j][k][a] + getdist ( ip[1][j+1], np, lr, j, k ) );
					if ( k < kc[2] && !a ) upd ( dp[i+1][j][k+1][0], dp[i][j][k][a] + getdist ( ip[2][k+1], np, lr, j, k ) );
				}
			}
		}
	}

//	lpi ( i, 0, n ) lpi ( j, 0, qmin ( i, kc[1] ) ) lpi ( k, qmax(0,i-j-kc[0]), qmin ( kc[2], i ) ) lp ( a, 0, 2 ) printf ( "%d %d %d %d: %d\n", i, j, k, a, dp[i][j][k][a] );

	printf ( "%d\n", qmin ( dp[n][kc[1]][kc[2]][0], dp[n][kc[1]][kc[2]][1] ) );
}