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

const int MOVE[4][2] =
{
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

int n, m;
PII S, T;
char gd[MAXN][MAXN];
int tag[MAXN][MAXN];

void init ();
void input ();
void work ();

void move ( int x, int y, int d, int nt );
AR(PII) move ( int x, int y, int d );



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
	lpi ( i, 1, n ) scanf ( "%s", gd[i]+1 );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) lpi ( j, 1, m ){
		if ( gd[i][j] == 'S' ) S = MP ( i, j );
		if ( gd[i][j] == 'T' ) T = MP ( i, j );
	}

	lp ( i, 0, 4 ) move ( S.first, S.second, i, 1 );
	lp ( i, 0, 4 ) move ( T.first, T.second, i, 2 );

	AR( PII ) ret;
	lpi ( i, 1, n ){
		lpi ( j, 1, m ){
			if ( tag[i][j] == 3 ){
				printf ( "YES\n" );
				return;
			} else if ( tag[i][j] == 1 ){
				lp ( k, 0, 4 ){
					ret = move ( i, j, k );
					for ( auto x : ret ){
						if ( tag[x.first][x.second] >> 1 & 1 ){
							printf ( "YES\n" );
							return;
						}
					}
				}
			}
		}
	}

	printf ( "NO\n" );
}



void move ( int x, int y, int d, int nt )
{
	AR( PII ) ret = move ( x, y, d );
	for ( auto x : ret ) tag[x.first][x.second] |= nt;
}

AR( PII ) move ( int x, int y, int d )
{
	AR( PII ) ans;
	while ( x > 0 && x <= n && y > 0 && y <= m && gd[x][y] ^ '*' ){
		ans.push_back ( MP ( x, y ) );
		x += MOVE[d][0], y += MOVE[d][1];
	}
	return ans;
}