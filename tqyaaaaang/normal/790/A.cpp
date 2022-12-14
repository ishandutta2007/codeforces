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
const int MAXN = 57;
const int MAXL = 13;
const int BASE = 26;

int n, k;
char s[MAXN][MAXL];
char name[MAXN][MAXL];
char sn[MAXN][MAXL];

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

	lp ( i, 0, MAXN ){
		name[i][0] = i / BASE + 'A';
		name[i][1] = i % BASE + 'a';
	}
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &k );
	lpi ( i, 1, n-k+1 ) scanf ( "%s", &s[i] );
}

void work ()
{
	// main work

	lpi ( i, 1, n ){
		if ( i < k || s[i-k+1][0] == 'Y' ) printf ( "%s ", name[i] ), strcpy ( sn[i], name[i] );
		else printf ( "%s ", sn[i-k+1] ), strcpy ( sn[i], sn[i-k+1] );
	}
	putchar ( '\n' );
}