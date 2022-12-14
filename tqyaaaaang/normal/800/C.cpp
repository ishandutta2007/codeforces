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

int n, kk;
bool cg[MAXN];
int dp[MAXN], nxt[MAXN];
AR( int ) ns[MAXN];
int ms[MAXN];
int ans[MAXN];

void init ();
void input ();
void work ();

int gcd ( int x, int y )
{
	return ( y ? gcd ( y, x%y ) : x );
}

int getnum ( int x, int y );

int exgcd ( int x, int y, int &a, int &b )
{
	if ( !y ){
		a = 1, b = 0;
		return x;
	}

	int aa, bb;
	int g = exgcd ( y, x%y, aa, bb );
	a = bb, b = aa - bb * ( x / y );
	return g;
}

int getrev ( int x, int y )
{
	int a, b;
	exgcd ( x, y, a, b );
	if ( a < 0 ) a += y;
	if ( a >= y ) a -= y;
	return a;
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
}

void input ()
{
	// input method

	scanf ( "%d%d", &kk, &n );
	int x;
	INIT ( cg, true );
	lp ( i, 0, kk ){
		scanf ( "%d", &x );
		cg[x] = false;
	}
}

void work ()
{
	// main work

	lp ( i, 1, n ) if ( cg[i] ) ns[gcd( i, n )].push_back ( i );

	lpd ( i, n-1, 0 ){
		nxt[i] = dp[i] = 0;
		for ( int j = i + i; j < n; j += i ){
			if ( dp[j] > dp[i] ) dp[i] = dp[j], nxt[i] = j;
		}
		dp[i] += ns[i].size ();
	}

	int now = 1;
	int km = 0;
	while ( now ){
		for ( auto x : ns[now] ) ms[++km] = x;
		now = nxt[now];
	}

	ms[0] = 1;
	lpi ( i, 1, km ){
		ans[i] = getnum ( ms[i-1], ms[i] );
	}

	if ( cg[0] ) ans[++km] = 0;

	printf ( "%d\n", km );
	lpi ( i, 1, km ) printf ( "%d ", ans[i] );
	putchar ( '\n' );
}



int getnum ( int x, int y )
{
	int gx = gcd ( x, n ), gy = gcd ( y, n );

	if ( gx == gy ){
		int xx = x / gx, yy = y / gy, nn = n / gx;
		return ( 1LL * yy * getrev ( xx, nn ) ) % nn;
	} else{
		lp ( i, 1, n ){
			if ( ( 1LL * x * i ) % n == y ) return i;
		}
	}

	return -1;
}