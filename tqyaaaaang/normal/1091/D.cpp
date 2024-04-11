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
const int MOD = 998244353;

int n;

void init ();
void input ();
void work ();



int add ( int x, int y )
{
	return ( ( x += y ) < MOD ) ? x : ( x - MOD );
}

void addv ( int &x, int y )
{
	( ( x += y ) < MOD ) ? x : ( x -= MOD );
}

int sub ( int x, int y )
{
	return ( ( x -= y ) >= 0 ) ? x : ( x + MOD );
}

void subv ( int &x, int y )
{
	( ( x -= y ) >= 0 ) ? x : ( x += MOD );
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
}

void work ()
{
	// main work

	int ans = 1;
	lpi ( i, 1, n ) ans = SC ( LL, ans ) * i % MOD;
	int cur = 1;
	lpi ( i, 1, n ) {
		addv ( ans, SC ( LL, cur ) * ( n - i ) % MOD * ( i - 1 ) % MOD );
		cur = SC ( LL, cur ) * ( n - i + 1 ) % MOD;
	}

	cout << ans << endl;
}