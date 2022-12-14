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
const int MAXN = 107;

int n;
int c[MAXN];
bool vis[MAXN];

void init ();
void input ();
void work ();

int dfs ( int now, int tar );

LL gcd ( LL x, LL y )
{
	return ( y ? gcd ( y, x%y ) : x );
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

	scanf ( "%d", &n );

	lpi ( i, 1, n ) scanf ( "%d", &c[i] );
}

void work ()
{
	// main work

	LL ans = 1;
	int now;
	lpi ( i, 1, n ){
		INIT ( vis, false );
		now = dfs ( i, i );
		if ( now < 0 ){
			printf ( "-1\n" );
			return;
		}

		if ( ! ( now & 1 ) ) now >>= 1;
		
		ans = ans / gcd ( ans, now ) * now;
	}

	printf ( "%I64d\n", ans );
}



int dfs ( int now, int tar )
{
	if ( vis[now] ){
		if ( now == tar ) return 0;
		else return -INF;
	}
	
	vis[now] = true;

	return ( dfs ( c[now], tar ) + 1 );
}