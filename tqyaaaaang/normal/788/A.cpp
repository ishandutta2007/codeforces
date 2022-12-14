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

int n;
int a[MAXN];
int d[MAXN];
LL ps[2][MAXN];

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

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	lp ( i, 1, n ) d[i] = qabs ( a[i+1] - a[i] );

	lp ( i, 0, 2 ){
		ps[i][0] = 0;
		lp ( j, 1, n ){
			ps[i][j] = ps[i][j-1] + ( ( ( j & 1 ) == i ) ? 1 : -1 ) * d[j];
		}
	}

	LL nv, maxi = 0;
	set < LL > s;
	lp ( j, 0, 2 ){
		s.clear ();
		lp ( i, 1, n ){
			s.insert ( ps[j][i-1] );
			if ( ( i & 1 ) == j ){
				nv = ps[j][i] - *s.begin ();
				maxi = qmax ( maxi, nv );
			}
		}
	}

	printf ( "%I64d\n", maxi );
}