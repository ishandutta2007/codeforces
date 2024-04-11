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
const int MAXN = 100007;
const int MAXM = 200007;
const int MAXK = 107;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXM];

int n, m, S, K;
int a[MAXN];
int ke, la[MAXN];
int d[MAXN][MAXK];
int q[MAXN];

void init ();
void input ();
void work ();

void bfs ( int nc );



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

	scanf ( "%d%d%d%d", &n, &m, &K, &S );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
	int u, v;
	INIT ( la, -1 );
	lp ( i, 0, m ) {
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

	INIT ( d, -1 );
	lpi ( i, 1, K ) bfs ( i );

	int ans = 0;
	lpi ( i, 1, n ) {
		sort ( d[i] + 1, d[i] + 1 + K );

		ans = 0;
		lpi ( j, 1, S ) ans += d[i][j];

		printf ( "%d ", ans );
	}
	putchar ( '\n' );
}



void bfs ( int nc )
{
	int l = 0, r = 0, now, v;
	lpi ( i, 1, n ) if ( a[i] == nc ) q[r++] = i, d[i][nc] = 0;
	while ( l < r ) {
		now = q[l++];
		for ( int i = la[now]; ~i; i = edge[i].last ) {
			if ( d[v = edge[i].v][nc] == -1 ) {
				d[v][nc] = d[now][nc] + 1;
				q[r++] = v;
			}
		}
	}
}