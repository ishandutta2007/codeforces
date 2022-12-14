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
const int MAXN = 5000007;

int n, m;
int a[MAXN];
int fa[MAXN];
bool ia[MAXN], hv[MAXN], vis[MAXN], noe[MAXN];

void init ();
void input ();
void work ();

int getfa ( int now )
{
	return ( ~fa[now] ) ? ( fa[now] = getfa ( fa[now] ) ) : now;
}

void uni ( int u, int v )
{
	u = getfa ( u ), v = getfa ( v );
	if ( u ^ v ) fa[u] = v;
}

void dfs ( int now );



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
	lpi ( i, 1, m ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	INIT ( fa, -1 );

	int ms = ( 1 << n ) - 1;

	lpi ( i, 1, m ) ia[a[i]] = true;
	lpi ( i, 0, ms ) {
		if ( ia[i] ) {
			lp ( j, 0, n ) if ( ~i >> j & 1 ) ia[i | ( 1 << j )] = true;
		}
	}
	lpi ( i, 1, m ) if ( ia[a[i]] && ia[ms^a[i]] ) hv[a[i]] = hv[ms^a[i]] = true;

	lpi ( i, 0, ms ) if ( !ia[i] ) vis[i] = true;
	lpi ( i, 0, ms ) if ( hv[i] && !vis[i] ) dfs ( i );

	lpi ( i, 1, m ) if ( ia[a[i]] && ia[ms^a[i]] ) uni ( a[i], ms^a[i] );
	lpi ( i, 1, m ) noe[getfa ( a[i] )] = true;

	int ans = 0;
	lpi ( i, 0, ms ) if ( fa[i] == -1 && noe[i] ) ++ans;

	cout << ans << endl;
}



void dfs ( int now )
{
	vis[now] = true;
	int v;
	lp ( i, 0, n ) {
		if ( now >> i & 1 ) {
			v = now ^ ( 1 << i );
			if ( ia[v] ) uni ( now, v );
			if ( !vis[v] ) dfs ( v );
		}
	}
}