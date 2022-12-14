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
const int MAXN = 100007;
const int MAXK = 27;

int n, k;
int a[MAXN];
LL dp[MAXK][MAXN];
int cc[MAXN], cl, cr;
LL cv;

void init ();
void input ();
void work ();

void divi ( LL dp[], LL pre[], int l, int r, int nl, int nr );

void move ( int l, int r );
void flip ( int now, bool flag );



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

	scanf ( "%d%d", &n, &k );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	cl = 1, cr = 0, cv = 0;

	INIT ( dp[0], 0x3f3f3f3f );
	dp[0][0] = 0;
	lpi ( i, 1, k ) {
		dp[i][0] = 0;
		divi ( dp[i], dp[i-1], 1, n, 0, n );
	}

	printf ( "%I64d\n", dp[k][n] );
}



void divi ( LL dp[], LL pre[], int l, int r, int nl, int nr )
{
	if ( l > r ) return;

	int mid = ( l + r ) >> 1;
	LL mini = LINF;
	int mp = -1;
	move ( nl+1, mid );
	lpi ( i, nl, nr ) {
		if ( i >= mid ) break;
		move ( i+1, mid );
		if ( cv + pre[i] < mini ) mini = cv + pre[i], mp = i;
	}

	dp[mid] = mini;

	divi ( dp, pre, l, mid-1, nl, mp );
	divi ( dp, pre, mid+1, r, mp, nr );
}

void move ( int l, int r )
{
	while ( cr < r ) flip ( ++cr, true );
	while ( cl > l ) flip ( --cl, true );
	while ( cr > r ) flip ( cr--, false );
	while ( cl < l ) flip ( cl++, false );
}

void flip ( int now, bool flag )
{
	if ( flag ) cv += ( cc[a[now]]++ );
	else cv -= ( --cc[a[now]] );
}