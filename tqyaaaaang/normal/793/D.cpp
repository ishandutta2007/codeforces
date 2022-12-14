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
const int MAXN = 83;
const int MAXM = 4007;

struct eT
{
	void setd ( int _u, int _v, int _w, int _l )
	{
		u = _u, v = _v, w = _w, last = _l;
	}

	int u, v, w, last;
}edge[MAXM];

int n, tk;
int m;
int ke, la[MAXN];
int dp[2][MAXN][MAXN][2];

void init ();
void input ();
void work ();



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

	scanf ( "%d%d", &n, &tk );
	scanf ( "%d", &m );
	int u, v, w;
	ke = 0;
	INIT ( la, -1 );
	lp ( i, 0, m ){
		scanf ( "%d%d%d", &u, &v, &w );
		edge[ke].setd ( u, v, w, la[u] );
		la[u] = ke++;
//		edge[ke].setd ( v, u, w, la[v] );
//		la[v] = ke++;
	}
}

void work ()
{
	// main work

	INIT ( dp, 0x3f3f3f3f );
	lpi ( i, 0, n+1 ) lpi ( j, i, n+1 ) dp[1][i][j][0] = dp[1][i][j][1] = 0;
//	lpi ( i, 0, n+1 ) dp[1][i][i+1][0] = dp[1][i][i+1][1] = 0;
	int t, now, v;
	lpi ( nk, 2, tk ){
		t = nk & 1;
		INIT ( dp[t], 0x3f3f3f3f );
		lpi ( l, 0, n+1 ){
			lpi ( r, l+1, n+1 ){
				lp ( d, 0, 2 ){
					now = d ? r : l;
					for ( int i = la[now]; ~i; i = edge[i].last ){
						v = edge[i].v;
						if ( v > l && v < r ){
							dp[t][l][r][d] = min ( dp[t][l][r][d], edge[i].w + qmin ( dp[t^1][l][v][1], dp[t^1][v][r][0] ) );
						}
					}
				}
			}
		}
//		lpi ( l, 0, n+1 ) lpi ( r, l+1, n+1 ) dp[t][l][r][0] = qmin ( dp[t][l][r][0], dp[t][l][r-1][0] );
//		lpi ( r, 0, n+1 ) lpdi ( l, r-1, 0 ) dp[t][l][r][1] = qmin ( dp[t][l][r][1], dp[t][l+1][r][1] );
	}

	int ans = INF;
	t = tk & 1;
	lpi ( l, 0, n+1 ) lpi ( r, l+1, n+1 ) lp ( d, 0, 2 ) ans = qmin ( ans, dp[t][l][r][d] );
	printf ( "%d\n", ( ans < 1e9 ) ? ans : -1 );
}