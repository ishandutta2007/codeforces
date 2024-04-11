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
const int MAX = 1027;

int n, k, x;
int a[MAXN];
int cc[2][MAX];

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

	scanf ( "%d%d%d", &n, &k, &x );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

/*	if ( k ){
		lpi ( i, 1, n ) if ( ( a[i] ^ x ) > a[i] ) a[i] = a[i] ^ x;
	}

	int mini = INF, maxi = -INF;
	lpi ( i, 1, n ) mini = qmin ( mini, a[i] ), maxi = qmax ( maxi, a[i] );

	printf ( "%d %d\n", maxi, mini );*/

	INIT ( cc, 0 );
	lpi ( i, 1, n ) ++cc[1][a[i]];

	int nt, nn = 0;
	lp ( j, 0, k ){
		nt = 1;
		INIT ( cc[nn], 0 );
		lp ( i, 0, MAX ){
			if ( cc[nn^1][i] ){
				cc[nn][i] += cc[nn^1][i] >> 1;
				cc[nn][i^x] += cc[nn^1][i] >> 1;
				if ( cc[nn^1][i] & 1 ){
					if ( nt ) ++cc[nn][i^x];
					else ++cc[nn][i];
					nt ^= 1;
				}
			}
		}
		nn ^= 1;
	}

	int mini = INF, maxi = -INF;
	lp ( i, 0, MAX ) if ( cc[nn^1][i] ) mini = qmin ( mini, i ), maxi = qmax ( maxi, i );

	printf ( "%d %d\n", maxi, mini );
}