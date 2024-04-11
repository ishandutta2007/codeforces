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
const int MAXN = 107;
const int MAXK = 53;
const int MOD = 1e9 + 7;

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];

int n, k, mk, ke;
int la[MAXN];
int deg[MAXN];
int dp[MAXN][MAXK];

void init ();
void input ();
void work ();

void dfs ( int now, int fa );



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

	scanf ( "%d%d", &n, &k );
	ke = 0;
	INIT ( la, -1 );
	INIT ( deg, 0 );
	int u, v;
	lp ( i, 1, n ){
		scanf ( "%d%d", &u, &v );
		edge[ke].setd ( u, v, la[u] );
		la[u] = ke++;
		++deg[u];
		edge[ke].setd ( v, u, la[v] );
		la[v] = ke++;
		++deg[v];
	}
}

void work ()
{
	// main work

	if ( !k ){
		printf ( "1\n" );
		return;
	}

	if ( n == 2 ){
		printf ( "3\n" );
		return;
	}

	mk = k * 2;

	lp ( i, 1, n ){
		if ( deg[i] == 1 ){
			dfs ( i, -1 );
			
/*			int cc = 0;
			lpi ( j, 0, k ){
				cc += dp[i][j];
				cc %= MOD;
			}*/

			printf ( "%d\n", dp[i][0] );

			return;
		}
	}
}



void dfs ( int now, int fa )
{
	int t[MAXK], lt[MAXK];

	bool flag = false;
	INIT ( t, 0 );
	int v, tc, tv;
	for ( int ei = la[now]; ei ^ -1; ei = edge[ei].last ){
		if ( edge[ei].v != fa ){
			v = edge[ei].v;

			dfs ( v, now );

			if ( !flag ){
				flag = true;
				lp ( i, 0, mk ){
					t[i+1] = dp[v][i];
					t[0] += dp[v][i];
					t[0] %= MOD;
				}
				t[0] += dp[v][mk];
				t[0] %= MOD;
			}else{
				INIT ( t, 0 );
				tc = 0;
				lp ( i, 0, mk ){
					if ( dp[v][i] ){
						tc += dp[v][i];
						tc %= MOD;
						lpi ( j, 1, mk ){
//							if ( i + j <= mk ){
							if ( i + j > mk ) tv = qmax ( i+1, j );
							else tv = qmin ( i+1, j );
							t[tv] += ( SC ( LL, dp[v][i] ) * lt[j] ) % MOD;
							t[tv] %= MOD;
//							}
						}
					}
				}
				tc += dp[v][mk];
				tc %= MOD;
				t[0] = ( lt[0] * SC ( LL, tc ) ) % MOD;
			}

			lpi ( i, 0, mk ) lt[i] = t[i];
		}
	}

	lpi ( i, 0, mk ) dp[now][i] = t[i];

	if ( !flag ){
		INIT ( dp[now], 0 );
		dp[now][0] = dp[now][k+1] = 1;
	}else if ( fa == -1 ){
		dp[now][0] = t[0];
		lpi ( i, 1, k ){
			dp[now][0] += t[i];
			dp[now][0] %= MOD;
		}
	}
}