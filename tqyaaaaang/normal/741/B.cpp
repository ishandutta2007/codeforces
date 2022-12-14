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
const int MAXN = 1007;
const int MAXM = 200007;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXM];

struct gT
{
	void setd ( int _i, int _l )
	{
		id = _i, last = _l;
	}

	int id, last;
}g[MAXN];

int n, m, W, ke, kg;
int w[MAXN], b[MAXN];
int la[MAXN], lg[MAXN];
int gw[MAXN], gb[MAXN];
bool vis[MAXN];
int dp[MAXN][MAXN];

void init ();
void input ();
void work ();

void dfs ( int now, int gc );



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

	scanf ( "%d%d%d", &n, &m, &W );

	lpi ( i, 1, n ) scanf ( "%d", &w[i] );
	lpi ( i, 1, n ) scanf ( "%d", &b[i] );

	int u, v;
	ke = 0;
	INIT ( la, -1 );
	lp ( i, 0, m ){
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

	kg = 0;
	INIT ( vis, false );
	INIT ( lg, -1 );
	INIT ( gw, 0 );
	INIT ( gb, 0 );
	int gc = 1;
	lpi ( i, 1, n ){
		if ( !vis[i] ){
			dfs ( i, gc++ );
		}
	}

	int v;
	INIT ( dp, 0 );
	lp ( i, 1, gc ){
		lpi ( j, 0, W ) dp[i][j] = dp[i-1][j];
		lpi ( j, gw[i], W ) dp[i][j] = qmax ( dp[i][j], dp[i-1][j-gw[i]] + gb[i] );

		for ( int j = lg[i]; j ^ -1; j = g[j].last ){
			v = g[j].id;
			lpi ( j, w[v], W ) dp[i][j] = qmax ( dp[i][j], dp[i-1][j-w[v]] + b[v] );
		}
	}

	int maxi = 0;
	lpi ( i, 0, W ) maxi = qmax ( maxi, dp[gc-1][i] );

	printf ( "%d\n", maxi );
}



void dfs ( int now, int gc )
{
	vis[now] = true;
	g[kg].setd ( now, lg[gc] );
	lg[gc] = kg++;
	gw[gc] += w[now], gb[gc] += b[now];
	for ( int i = la[now]; i ^ -1; i = edge[i].last ){
		if ( !vis[edge[i].v] ){
			dfs ( edge[i].v, gc );
		}
	}
}