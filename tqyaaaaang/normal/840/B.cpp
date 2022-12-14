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
const int MAXN = 1200007;

struct eT
{
	void setd ( int _u, int _v, int _i, int _l )
	{
		u = _u, v = _v, id = _i, last = _l;
	}

	int u, v, id, last;
}edge[MAXN];

int n, m;
int ke, la[MAXN];
int d[MAXN];
int eu[MAXN], ev[MAXN];
int fa[MAXN];
int fi[MAXN];
int il[MAXN], ir[MAXN], ki;
int nv[MAXN];
int ans[MAXN], ka;

void init ();
void input ();
void work ();

int getfa ( int now )
{
	return ( fa[now] ? ( fa[now] = getfa ( fa[now] ) ) : now );
}

void dfs ( int now, int fa );

void add ( int u, int v );



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
	lpi ( i, 1, n ) scanf ( "%d", &d[i] );
	ke = 0;
	INIT ( la, -1 );
	lpi ( i, 1, m ){
		scanf ( "%d%d", &eu[i], &ev[i] );
	}
}

void work ()
{
	// main work

	bool flag = false;
	int nt = 0;
	lpi ( i, 1, n ){
		if ( ~d[i] ) nt ^= d[i];
		else flag = true;
	}

	if ( nt && !flag ){
		printf ( "-1\n" );
		return;
	}

	int u, v, ru, rv;
	lpi ( i, 1, m ){
		u = eu[i], v = ev[i];
		ru = getfa ( u ), rv = getfa ( v );
		if ( ru ^ rv ){
			fa[ru] = rv;
			edge[ke].setd ( u, v, i, la[u] );
			la[u] = ke++;
			edge[ke].setd ( v, u, i, la[v] );
			la[v] = ke++;
		}
	}

	dfs ( 1, -1 );

	int pi = -1;
	lpi ( i, 1, n ){
		if ( ( d[i] == 1 ) || ( d[i] == -1 && flag && nt ) ){
			if ( pi == -1 ) pi = i;
			else{
				add ( pi, i );
				pi = -1;
			}
			if ( d[i] == -1 && flag ) flag = false;
		}
	}

	lpi ( i, 1, ki ) nv[i] ^= nv[i-1];

	lpi ( i, 1, n ) if ( nv[il[i]] ^ nv[ir[i]] ) ans[++ka] = fi[i];

	printf ( "%d\n", ka );
	lpi ( i, 1, ka ) printf ( "%d\n", ans[i] );
}



void dfs ( int now, int fa )
{
	int v;
	il[now] = ++ki;
	for ( int i = la[now]; ~i; i = edge[i].last ){
		if ( ( v = edge[i].v ) ^ fa ){
			dfs ( v, now );
			fi[v] = edge[i].id;
		}
	}
	ir[now] = ++ki;
}

void add ( int u, int v )
{
	if ( il[u] > il[v] ) swap ( u, v );

	if ( ir[u] < il[v] ){
		nv[ir[u]] ^= 1, nv[il[v]+1] ^= 1;
	} else{
		nv[il[u]+1] ^= 1, nv[il[v]+1] ^= 1;
	}
}