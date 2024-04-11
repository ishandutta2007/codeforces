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
const int MAXN = 53;
const int MAX1 = 103;
const int MAX = MAXN * MAX1 + 207;
const int MUL = 1000;

int n;
PII in[MAXN];
LL a[MAXN];
int b[MAXN];
LL dp[2][MAXN][MAX][2];

void init ();
void input ();
void work ();

void chkmin ( LL &x, LL y )
{
	x = qmin ( x, y );
}

LL getv ( LL x, int y )
{
	return ( x + y - 1 ) / y;
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

	cin >> n;
	lpi ( i, 1, n ) cin >> in[i].first;
	lpi ( i, 1, n ) cin >> in[i].second;
}

void work ()
{
	// main work

	sort ( in + 1, in + 1 + n, [] ( const PII x, const PII y ) { return ( x.first ^ y.first ) ? ( x.first > y.first ) : ( x.second < y.second ); } );
	lpi ( i, 1, n ) a[i] = SC ( LL, in[i].first ) * MUL, b[i] = in[i].second;
	a[0] = LINF;
	a[n + 1] = -LINF;

	lp ( t, 0, 2 ) lp ( j, 0, MAXN ) lp ( k, 0, MAX ) dp[t][j][k][0] = dp[t][j][k][1] = LINF;

	int ub;
	int t = 0;
	dp[t][0][0][0] = 0;
	lpi ( i, 1, n ) {
		t ^= 1;
		ub = i * MAX1;
		lpi ( j, 0, i ) lpi ( k, 0, ub ) dp[t][j][k][0] = dp[t][j][k][1] = LINF;
		lpi ( j, 0, i ) {
			lpi ( k, 0, ub ) {
				chkmin ( dp[t][j][k][0], dp[t ^ 1][j + 1][k][0] );
				if ( j && k >= b[i] ) {
					chkmin ( dp[t][j][k][1], qmin ( dp[t ^ 1][j - 1][k - b[i]][0], dp[t ^ 1][j - 1][k - b[i]][1] ) + a[i] );
				}
			}
		}
		if ( a[i] ^ a[i + 1] ) {
			lpi ( j, 0, i ) lpi ( k, 0, ub ) chkmin ( dp[t][j][k][0], dp[t][j][k][1] );
		}
	}

	LL ans = LINF;
	lpi ( i, 0, n ) {
		lp ( j, 1, MAX ) {
			chkmin ( ans, getv ( qmin ( dp[t][i][j][0], dp[t][i][j][1] ), j ) );
		}
	}

	cout << ans << endl;
}