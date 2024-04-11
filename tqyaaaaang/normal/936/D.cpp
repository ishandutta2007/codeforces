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
const int MAXN = 2000007;

int N, n, m1, m2, T;
int a1[MAXN], a2[MAXN];
int px[MAXN];
int dp[MAXN][2];
bool af[MAXN][2];
PII pre[MAXN][2];

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

	scanf ( "%d%d%d%d", &N, &m1, &m2, &T );
	lpi ( i, 1, m1 ) scanf ( "%d", &a1[i] );
	lpi ( i, 1, m2 ) scanf ( "%d", &a2[i] );
}

void work ()
{
	// main work

	a1[m1 + 1] = a2[m2 + 1] = INF;

	n = 0;
	int ni1 = 1, ni2 = 1;
	while ( ni1 <= m1 || ni2 <= m2 ) {
		if ( a1[ni1] < a2[ni2] ) {
			if ( a1[ni1] > px[n] ) px[++n] = a1[ni1];
			if ( a1[ni1] + 1 > px[n] ) px[++n] = a1[ni1] + 1;
			++ni1;
		} else {
			if ( a2[ni2] > px[n] ) px[++n] = a2[ni2];
			if ( a2[ni2] + 1 > px[n] ) px[++n] = a2[ni2] + 1;
			++ni2;
		}
	}
	while ( px[n] > N ) --n;
	if ( px[n] ^ N ) px[++n] = N;

	bool f1, f2;
	ni1 = 1, ni2 = 1;
	INIT ( dp, 0x3f3f3f3f );
	dp[0][0] = dp[0][1] = 0;
	pre[0][0] = MP ( -1, -1 );
	pre[0][1] = MP ( 0, 0 );
	lpi ( i, 1, n ) {
		if ( a1[ni1 + 1] == px[i] ) ++ni1;
		if ( a2[ni2 + 1] == px[i] ) ++ni2;

		f1 = ( a1[ni1] == px[i] );
		f2 = ( a2[ni2] == px[i] );

		af[i][0] = f1, af[i][1] = f2;

		if ( ( !( i - 1 ) || dp[i - 1][0] < px[i - 1] ) && dp[i - 1][0] + ( f1 ? T : 0 ) < dp[i][0] ) dp[i][0] = dp[i - 1][0] + ( f1 ? T : 0 ), pre[i][0] = MP ( i - 1, 0 );
		if ( ( !( i - 1 ) || dp[i - 1][1] < px[i - 1] ) && dp[i - 1][1] + ( f2 ? T : 0 ) < dp[i][1] ) dp[i][1] = dp[i - 1][1] + ( f2 ? T : 0 ), pre[i][1] = MP ( i - 1, 1 );
		if ( !f1 && qmax ( dp[i][1], px[i] - T ) < dp[i][0] ) dp[i][0] = qmax ( dp[i][1], px[i] - T ), pre[i][0] = MP ( i, 1 );
		if ( !f2 && qmax ( dp[i][0], px[i] - T ) < dp[i][1] ) dp[i][1] = qmax ( dp[i][0], px[i] - T ), pre[i][1] = MP ( i, 0 );
//		dp[i][0] = qmin ( dp[i][0], dp[i - 1][0] + ( f1 ? T : 0 ) );
//		dp[i][1] = qmin ( dp[i][1], dp[i - 1][1] + ( f2 ? T : 0 ) );
//		dp[i][0] = qmin ( dp[i][0], qmax ( dp[i][1], i - T ) );
//		dp[i][1] = qmin ( dp[i][1], qmax ( dp[i][0], i - T ) );
	}

	int nt = ( dp[n][0] < N ) ? 0 : 1;
	if ( dp[n][nt] < N ) {
		printf ( "Yes\n" );
		AR ( PII ) shoot;
		AR ( int ) flip;
		int cur = n, pc, pt;
		while ( ~cur ) {
			if ( af[cur][nt] ) shoot.push_back ( MP ( dp[cur][nt], nt ) );
			pc = cur, pt = nt, cur = pre[pc][pt].first, nt = pre[pc][pt].second;
			if ( cur == pc ) flip.push_back ( px[cur] );
		}
		reverse ( shoot.begin (), shoot.end () );
		reverse ( flip.begin (), flip.end () );
		printf ( "%d\n", flip.size () );
		for ( auto x : flip ) printf ( "%d ", x );
		putchar ( '\n' );
		printf ( "%d\n", shoot.size () );
		for ( auto x : shoot ) printf ( "%d %d\n", x.first, x.second + 1 );
	} else printf ( "No\n" );
}