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
const int MAXN = 53;
const int MAXL = 61;

int n, m;
LL a[MAXN], ps[MAXN];
bool dp[MAXN][MAXN];

void init ();
void input ();
void work ();

bool check ( LL tst )
{
	INIT ( dp, false );
	dp[0][0] = true;
	lpi ( i, 1, n ) {
		lpi ( j, 1, qmin ( i, m ) ) {
			lp ( k, 0, i ) {
				if ( ( ( ps[i] - ps[k] ) & tst ) == tst ) dp[i][j] |= dp[k][j - 1];
			}
		}
	}
	return dp[n][m];
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

	cin >> n >> m;
	lpi ( i, 1, n ) cin >> a[i];
}

void work ()
{
	// main work

	ps[0] = 0;
	lpi ( i, 1, n ) ps[i] = ps[i - 1] + a[i];

	LL ans = 0;
	lpdi ( i, MAXL - 1, 0 ) {
		if ( check ( ans | ( 1LL << i ) ) ) {
			ans |= 1LL << i;
		}
	}

	cout << ans << endl;
}