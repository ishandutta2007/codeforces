#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
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

int n, m, k;
LL c[MAXN];
LL p[MAXN][MAXN];
LL dp[MAXN][MAXN][MAXN];

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

	cin >> n >> m >> k;
	lpi ( i, 1, n ) cin >> c[i];
	lpi ( i, 1, n )
		lpi ( j, 1, m )
			cin >> p[i][j];
}

void work ()
{
	// main work

	lp ( i, 0, MAXN )
		lp ( j, 0, MAXN )
			lp ( a, 0, MAXN )
				dp[i][j][a] = LINF;

//	lp ( i, 1, MAXN ) dp[0][i][1] = 0;
	if ( c[1] ){
		dp[1][c[1]][1] = 0;
	}else{
		lpi ( i, 1, m )
			dp[1][i][1] = p[1][i];
	}

	lpi ( i, 2, n ){
		lpi ( a, 1, k ){
			if ( c[i] ){
				lpi ( b, 1, m )
					dp[i][c[i]][a] = qmin ( dp[i][c[i]][a], dp[i-1][b][(b^c[i])?(a-1):a] );
			}else{
				lpi ( j, 1, m ){
					lpi ( b, 1, m )
						dp[i][j][a] = qmin ( dp[i][j][a], dp[i-1][b][(b^j)?(a-1):a] );
					if ( dp[i][j][a] ^ LINF ) dp[i][j][a] += p[i][j];
				}
			}
		}
	}

	LL mini = LINF;
	lpi ( i, 1, m ) mini = qmin ( mini, dp[n][i][k] );

	cout << ( ( mini ^ LINF ) ? mini : -1 ) << endl;
}