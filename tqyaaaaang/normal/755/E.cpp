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

int n, k;
bool edge[MAXN][MAXN];

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

	scanf ( "%d%d", &n, &k );
}

void work ()
{
	// main work

	if ( k >= n ){
		printf ( "-1\n" );
		return;
	}

	if ( k == 1 ){
		printf ( "-1\n" );
		return;
	}

	if ( k == 2 ){
		if ( n <= 4 ){
			printf ( "-1\n" );
			return;
		}
		printf ( "%d\n", n-1 );
		lp ( i, 1, n ) printf ( "%d %d\n", i, i+1 );
		return;
	}

	INIT ( edge, false );
	lpi ( i, 1, k ) edge[i][i+1] = edge[i+1][i] = true;
	int beg = k + 2;
	lpi ( i, beg,n ) lpi ( j, i+1, n ) edge[i][j] = edge[j][i] = true;

	if ( k > 3 ){
		printf ( "-1\n" );
		return;
	}

	lpi ( i, beg, n ) edge[2][i] = edge[i][2] = true;

	int kk = 0;
	lpi ( i, 1, n ) lpi ( j, i+1, n ) kk += edge[i][j];

	printf ( "%d\n", kk );
	lpi ( i, 1, n ) lpi ( j, i+1, n ) if ( edge[i][j] ) printf ( "%d %d\n", i, j );
}