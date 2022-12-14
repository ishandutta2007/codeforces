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
const int MAXN = 1000007;

int n, m;
int a[MAXN];
int dp[MAXN][3][3];

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

	scanf ( "%d%d", &n, &m );
	int x;
	lpi ( i, 1, n ) scanf ( "%d", &x ), ++a[x];
}

void work ()
{
	// main work

	lpi ( i, 1, m ) {
		lp ( v1, 0, 3 ) {
			lp ( v2, 0, 3 ) {
				lp ( v3, 0, 3 ) {
					if ( v1 + v2 + v3 <= a[i] ) {
						dp[i][v2][v3] = max ( dp[i][v2][v3], dp[i - 1][v1][v2] + v3 + ( a[i] - v1 - v2 - v3 ) / 3 );
					}
				}
			}
		}
	}
	cout << dp[m][0][0] << endl;
}