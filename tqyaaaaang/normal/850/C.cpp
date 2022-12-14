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
int a[MAXN];
AR ( PII ) divi[MAXN];
map < int, int > mp;
map < int, int > ::iterator it;
map < int, int > dp;

void init ();
void input ();
void work ();

AR ( PII ) getprm ( int x );
int getsg ( int x );
int dfs ( int now );



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

	lpi ( i, 1, n ) {
		divi[i] = getprm ( a[i] );
		for ( auto x : divi[i] ) mp[x.first] |= 1 << x.second;
	}

	dp[0] = 0;

	int ans = 0;
	for ( auto x : mp ) {
		ans ^= getsg ( x.second );
	}

	printf ( ans ? "Mojtaba\n" : "Arpa\n" );
}



AR ( PII ) getprm ( int x )
{
	int t = x;
	AR ( PII ) ans;
	int nv, nc;
	for ( int i = 2; i * i <= x; ++i ) {
		if ( t % i == 0 ) {
			nv = i, nc = 0;
			while ( t % i == 0 ) t /= i, ++nc;
			ans.push_back ( MP ( nv, nc ) );
		}
	}
	if ( t ^ 1 ) ans.push_back ( MP ( t, 1 ) );
	return ans;
}

int getsg ( int x )
{
	return dfs ( x );
}

int dfs ( int now )
{
	if ( ( it = dp.find ( now ) ) != dp.end () ) return it->second;

	int sta = 0;
	int vs, tl = 0;
	for ( int t = now; t; t >>= 1 ) ++tl;
	lp ( j, 1, tl ) {
		vs = now;
		lp ( k, 1, tl )
			if ( ( now >> k & 1 ) && k >= j )
				vs |= 1 << ( k - j ), vs &= ~( 1 << k );
		vs &= ~1;
		sta |= 1 << dfs ( vs );
	}

	int ans;
	lp ( i, 0, 43 ) {
		if ( !( sta >> i & 1 ) ) {
			ans = i;
			break;
		}
	}

	dp[now] = ans;

	return ans;
}