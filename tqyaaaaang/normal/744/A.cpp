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

int n, m, k, ke;
int la[MAXN];
int c[MAXN];
int inb[MAXN];
int cc[MAXN];
int ans[MAXN];

void init ();
void input ();
void work ();

void dfs ( int now, int id );



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

	scanf ( "%d%d%d", &n, &m, &k );
	lpi ( i, 1, k ) scanf ( "%d", &c[i] );
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

	INIT ( inb, 0 );
	INIT ( cc, 0 );
	lpi ( i, 1, k ) dfs ( c[i], i );

	lpi ( i, 1, n ) if ( !inb[i] ) ++cc[0];

	int maxi = 0, sum = 0;
	lpi ( i, 0, k ){
		ans[i] = cc[i] * ( cc[i] - 1 ) / 2;
		sum += ans[i];
		if ( i ) maxi = qmax ( maxi, cc[i] );
	}
	sum += maxi * cc[0];
	sum -= m;
	printf ( "%d\n", sum );
}



void dfs ( int now, int id )
{
	if ( inb[now] ) return;
	inb[now] = id;
	++cc[id];

	for ( int i = la[now]; i ^ -1; i = edge[i].last ) dfs ( edge[i].v, id );
}