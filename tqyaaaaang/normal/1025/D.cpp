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
const int MAXN = 707;

int n;
int a[MAXN];
bool g[MAXN][MAXN];
bool dp[MAXN][MAXN][2];

void init ();
void input ();
void work ();

int gcd ( int x, int y )
{
	return y ? gcd ( y, x%y ) : x;
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

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) g[0][i] = g[i][0] = g[i][n + 1] = g[n + 1][i] = true;
	lpi ( i, 1, n ) lpi ( j, 1, n ) g[i][j] = gcd ( a[i], a[j] ) > 1;

	lpi ( i, 1, n+1 ) dp[i][i - 1][0] = dp[i][i - 1][1] = true;

	lpi ( d, 1, n ) {
		lpi ( l, 1, n-d+1 ) {
			int r = l + d - 1;
			lp ( dir, 0, 2 ) {
				int x = dir ? ( r + 1 ) : ( l - 1 );
				lpi ( i, l, r ) {
					if ( g[x][i] && dp[l][i - 1][1] && dp[i + 1][r][0] ) {
						dp[l][r][dir] = true;
						break;
					}
				}
			}
		}
	}

	cout << ( dp[1][n][0] ? "Yes" : "No" ) << endl;
}