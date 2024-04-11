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

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN];

int n;
int ke, la[MAXN];
int fa[MAXN];
bool in[MAXN];
int ans[MAXN], ka;

void init ();
void input ();
void work ();

void dfs ( int now );
void dfs2 ( int now );



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
	lpi ( i, 1, n ) scanf ( "%d", &fa[i] );
}

void work ()
{
	// main work

	int rt;
	INIT ( la, -1 );
	lpi ( i, 1, n ) {
		if ( fa[i] ) {
			edge[ke].setd ( fa[i], i, la[fa[i]] );
			la[fa[i]] = ke++;
		}else rt = i;
	}

	dfs ( rt );

	if ( ka == n ) {
		printf ( "YES\n" );
		lpi ( i, 1, n ) printf ( "%d\n", ans[i] );
	} else printf ( "NO\n" );
}



void dfs ( int now )
{
	int nd = fa[now] ? 1 : 0;
	for ( int i = la[now]; ~i; i = edge[i].last ) {
		dfs ( edge[i].v );
		if ( !in[edge[i].v] ) ++nd;
	}

	if ( !( nd & 1 ) ) {
		dfs2 ( now );
	}
}

void dfs2 ( int now )
{
	in[now] = true;
	ans[++ka] = now;
	for ( int i = la[now]; ~i; i = edge[i].last ) if ( !in[edge[i].v] ) dfs2 ( edge[i].v );
}