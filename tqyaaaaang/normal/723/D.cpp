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
const int MAXN = 53;

const int MOVE[4][2] =
{
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

struct lT
{
	bool operator < ( const lT &a ) const
	{
		return ( ( size ^ a.size ) ? ( size < a.size ) : ( id < a.id ) );
	}

	int id, size;
}lake[MAXN*MAXN];

int n, m, k, kk = 0;
char mmap[MAXN][MAXN];
int vis[MAXN][MAXN];
bool v1[MAXN][MAXN];
bool fil[MAXN*MAXN];

void init ();
void input ();
void work ();

bool dfs1 ( int a, int b );
int dfs2 ( int a, int b, int c );



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
	lp ( i, 0, n ) cin >> mmap[i];
}

void work ()
{
	// main work

	memset ( vis, 0, sizeof ( vis ) );
	memset ( v1, false, sizeof ( v1 ) );

	int c;
	lp ( i, 0, n ){
		lp ( j, 0, m ){
			if ( !v1[i][j] && mmap[i][j] == '.' ){
				if ( dfs1 ( i, j ) ){
					lake[kk].id = kk + 1;
					lake[kk].size = dfs2 ( i, j, kk+1 );
					++kk;
				}
			}
		}
	}

	sort ( lake, lake+kk );

	int sum = 0;
	memset ( fil, false, sizeof ( fil ) );
	lp ( i, 0, kk-k ) fil[lake[i].id] = true, sum += lake[i].size;

	lp ( i, 0, n )
		lp ( j, 0, m )
			if ( vis[i][j] > 0 && fil[vis[i][j]] )
				mmap[i][j] = '*';

	cout << sum << endl;
	lp ( i, 0, n ) cout << mmap[i] << endl;
}



bool dfs1 ( int a, int b )
{
	if ( a < 0 || a >= n || b < 0 || b >= m ) return true;
	if ( v1[a][b] ) return true;
	if ( mmap[a][b] == '*' ) return true;

	v1[a][b] = true;
	
	bool suc = true;
	lp ( i, 0, 4 ){
		suc &= dfs1 ( a+MOVE[i][0], b+MOVE[i][1] );
	}

	if ( !suc || a == 0 || a == n-1 || b == 0 || b == m-1 ) return false;
	else return true;
}

int dfs2 ( int a, int b, int c )
{
	if ( a < 0 || a >= n || b < 0 || b >= m ) return 0;
	if ( vis[a][b] ) return 0;
	if ( mmap[a][b] == '*' ) return 0;

	vis[a][b] = c;

	int size = 0;
	lp ( i, 0, 4 ){
		size += dfs2 ( a+MOVE[i][0], b+MOVE[i][1], c );
	}

	return size + 1;
}