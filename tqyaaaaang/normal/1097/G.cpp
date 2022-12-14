#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
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
const int MAXK = 207;
const int MOD = SC ( int, 1e9 + 7 );
const ULL MDIV = SC ( ULL, 1.7e19 );



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

int qpow ( int a, int b )
{
	LL base = a, ans = 1;
	while ( b ) {
		if ( b & 1 ) ( ans *= base ) %= MOD;
		( base *= base ) %= MOD;
		b >>= 1;
	}
	return SC ( int, ans );
}



struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN * 2];



int n, m;
int allans;
int ke, la[MAXN];
int dp[MAXN][MAXK];
int frac[MAXK], rf[MAXK], rev[MAXK];
int ta[MAXK], tb[MAXK], tans[MAXK];

void init ();
void input ();
void work ();

void dfs ( int now, int fa );

void mul ( int a[], int b[], int ans[], int n );



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

	frac[0] = 1;
	lp ( i, 1, MAXK ) frac[i] = SC ( LL, frac[i - 1] ) * i % MOD;
	rf[MAXK - 1] = qpow ( frac[MAXK - 1], MOD - 2 );
	lpdi ( i, MAXK - 2, 0 ) rf[i] = SC ( LL, rf[i + 1] ) * ( i + 1 ) % MOD;
	lp ( i, 1, MAXK ) rev[i] = SC ( LL, rf[i] ) * frac[i - 1] % MOD;
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &m );
	int u, v;
	INIT ( la, -1 );
	lp ( i, 1, n ) {
		scanf ( "%d%d", &u, &v );
		edge[ke].setd ( u, v, la[u] );
		la[u] = ke++;
		edge[ke].setd ( v, u, la[v] );
		la[v] = ke++;
	}
}

void work ()
{
	// main work

	dfs ( 1, -1 );
	cout << allans << endl;
}



void dfs ( int now, int fa )
{
	bool havechild = false;
	int v;
	for ( int i = la[now]; ~i; i = edge[i].last ) {
		if ( ( v = edge[i].v ) ^ fa ) {
			dfs ( v, now );
			if ( !havechild ) {
				lpi ( j, 0, m ) dp[now][j] = dp[v][j];
				havechild = true;
			} else {
				lpi ( j, 0, m ) {
					ta[j] = SC ( LL, dp[now][j] ) * rf[j] % MOD;
					tb[j] = SC ( LL, dp[v][j] ) * rf[j] % MOD;
				}
				mul ( ta, tb, tans, m );
				lpi ( j, 0, m ) dp[now][j] = SC ( LL, tans[j] ) * frac[j] % MOD;
			}
		}
	}

	if ( !havechild ) {
		lpi ( i, 0, m ) dp[now][i] = 1;
	} else {
		int tdm = 0;
		for ( int i = la[now]; ~i; i = edge[i].last ) if ( edge[i].v ^ fa ) addv ( tdm, dp[edge[i].v][m] );
/*		INIT ( td, 0 );
		for ( int i = la[now]; ~i; i = edge[i].last ) {
			if ( ( v = edge[i].v ) ^ fa ) {
				lpi ( j, 0, m ) addv ( td[j], dp[v][j] );
				subv ( td[0], 1 );
			}
		}
		addv ( td[0], 1 );*/
		lpi ( j, 0, m ) dp[now][j] = add ( dp[now][j], dp[now][j] );
		subv ( dp[now][0], 1 );   // erase empty set

		addv ( allans, sub ( dp[now][m], tdm ) );

		lpi ( j, 0, m ) {
			ta[j] = SC ( LL, dp[now][j] ) * rf[j] % MOD;
			tb[j] = rf[j];
		}
		mul ( ta, tb, tans, m );
		lpi ( j, 0, m ) dp[now][j] = SC ( LL, tans[j] ) * frac[j] % MOD;
	}

	addv ( dp[now][0], 1 );
}



void mul ( int a[], int b[], int ans[], int n )
{
	ULL tans;
	lpi ( i, 0, n ) {
		tans = 0;
		lpi ( j, 0, i ) {
			tans += SC ( LL, a[j] ) * b[i - j];
			if ( tans > MDIV ) tans %= MOD;
		}
		ans[i] = tans % MOD;
	}
}