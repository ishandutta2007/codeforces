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
const int MAXL = 21;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];

int n, ke;
int la[MAXN];
int lca[MAXN][MAXL];
LL sum[MAXN][MAXL];
int a[MAXN];
int fa[MAXN];
int dist[MAXN];
int tag[MAXN];
int ans[MAXN];

void init ();
void input ();
void work ();

int dfs ( int now );



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
	lpi ( i, 1, n )
		scanf ( "%d", &a[i] );
	lpi ( i, 2, n )
		scanf ( "%d%d", &fa[i], &dist[i] );
}

void work ()
{
	// main work

	fa[1] = 0;
	INIT ( la, -1 );
	ke = 0;
	lpi ( i, 2, n ){
		edge[ke].setd ( fa[i], i, la[fa[i]] );
		la[fa[i]] = ke++;
	}

	lpi ( i, 1, n ) lca[i][0] = fa[i], sum[i][0] = dist[i];

	lp ( j, 1, MAXL ){
		lpi ( i, 1, n ){
			if ( lca[i][j-1] ){
				lca[i][j] = lca[lca[i][j-1]][j-1];
				sum[i][j] = sum[i][j-1] + sum[lca[i][j-1]][j-1];
			}
		}
	}

	int to;
	LL ns;
	INIT ( tag, 0 );
	lpi ( i, 1, n ){
		to = i;
		ns = 0;
		lpdi ( j, MAXL-1, 0 ){
			if ( lca[to][j] && ns + sum[to][j] <= a[i] ){
				ns += sum[to][j];
				to = lca[to][j];
			}
		}

		++tag[fa[i]];
		--tag[fa[to]];
	}

	INIT ( ans, 0 );

	dfs ( 1 );

	lpi ( i, 1, n ) printf ( "%d ", ans[i] );
	printf ( "\n" );
}



int dfs ( int now )
{
	int cc = tag[now];
	for ( int i = la[now]; i ^ -1; i = edge[i].last )
		cc += dfs ( edge[i].v );

	ans[now] = cc;

	return cc;
}