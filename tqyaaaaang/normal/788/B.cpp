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

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];

int n, m, cl;
int ke, la[MAXN];
int deg[MAXN], ne[MAXN];
bool vis[MAXN];

void init ();
void input ();
void work ();

void dfs ( int now )
{
	vis[now] = true;

	for ( int i = la[now]; ~i; i = edge[i].last ){
		if ( !vis[edge[i].v] ){
			dfs ( edge[i].v );
		}
	}
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

	scanf ( "%d%d", &n, &m );
	int u, v;
	ke = 0;
	INIT ( la, -1 );
	lp ( i, 0, m ){
		scanf ( "%d%d", &u, &v );
		edge[ke].setd ( u, v, la[u] );
		la[u] = ke++;
		edge[ke].setd ( v, u, la[v] );
		la[v] = ke++;
		if ( u ^ v ) ++deg[u], ++deg[v], ++ne[u], ++ne[v];
		else ++deg[u], ++cl;
//		++deg[u], ++deg[v];
	}
}

void work ()
{
	// main work

//	dfs ( 1, -1 );
	lpi ( i, 1, n ){
		if ( deg[i] ){
			dfs ( i );
			break;
		}
	}

	lpi ( i, 1, n ) if ( !vis[i] && deg[i] ){ printf ( "0\n" ); return; }

/*	LL cc = 0;
	lp ( i, 0, m ){
		if ( edge[i<<1].u ^ edge[i<<1].v ) cc += deg[edge[i<<1].u] - 1, cc += deg[edge[i<<1].v] - 1;
		else cc += deg[edge[i<<1].u] - 1;
	}*/

	LL cc = 0;
	lpi ( i, 1, n ){
		cc += 1LL * ne[i] * ( ne[i] - 1 );
	}

	cc += 1LL * cl * ( cl - 1 ) + 1LL * cl * ( m - cl ) * 2;

	printf ( "%I64d\n", cc >> 1 );
}