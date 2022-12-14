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
const int BASE = 127;

int n, k, bl, br;
int cord[BASE];
bool used[BASE], nhv[BASE];
char s[MAXN], l[MAXN], r[MAXN];

void init ();
void input ();
void work ();

int getst ( int c, int l, int r, int st )
{
	if ( ( st & 2 ) && c < l ) return -1;
	if ( ( st & 1 ) && c > r ) return -1;
	int ans = st;
	if ( c > l ) ans &= ~2;
	if ( c < r ) ans &= ~1;
	return ans;
}

bool srch ( int ni, int st )
{
	if ( ni == n || !st ) return true;

	if ( cord[s[ni]] ) {
		int ret = getst ( cord[s[ni]], l[ni], r[ni], st );
		if ( ( ~ret ) && srch ( ni + 1, ret ) ) return true;
		return false;
	}

	lpi ( i, bl, br ) {
		if ( !used[i] ) {
			int ret = getst ( i, l[ni], r[ni], st );
			if ( ~ret ) {
				cord[s[ni]] = i;
				used[i] = true;
				if ( srch ( ni + 1, ret ) ) return true;
				cord[s[ni]] = 0;
				used[i] = false;
			}
		}
	}

	return false;
}



int main ()
{
	init ();

	int T;
	scanf ( "%d", &T );
	while ( T-- ) {
		input ();
		work ();
	}
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%d%s%s%s", &k, s, l, r );
}

void work ()
{
	// main work

	n = strlen ( s );

	bl = 'a', br = bl + k - 1;

	INIT ( cord, 0 );
	INIT ( used, false );
	bool ans = srch ( 0, 3 );

	if ( ans ) {
		printf ( "YES\n" );

		INIT ( nhv, true );
		lpi ( i, bl, br ) if ( cord[i] ) nhv[cord[i]] = false;
		int ni = bl;
		lpi ( i, bl, br ) {
			if ( !cord[i] ) {
				while ( !nhv[ni] ) ++ni;
				cord[i] = ni;
				nhv[ni] = false;
			}
		}
		lpi ( i, bl, br ) putchar ( cord[i] );
		putchar ( '\n' );
	} else printf ( "NO\n" );
}