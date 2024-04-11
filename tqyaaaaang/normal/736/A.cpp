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
const LL MAXN = 1e18 + 7;
const LL MAXL = 10000007;

int nn;
LL n;
LL f[MAXL];

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

	f[0] = 1;
	f[1] = 2;
	lp ( i, 2, MAXL ){
		f[i] = f[i-2] + f[i-1];

		if ( f[i] > MAXN ){
			nn = i;
			break;
		}
	}
}

void input ()
{
	// input method

	scanf ( "%I64d", &n );
}

void work ()
{
	// main work

//	lp ( i, 1, nn ) printf ( "%d: %I64d\n", i, f[i] );

/*	LL l = 1, r = MAXL, mid;
	while ( l < r ){
		mid = ( l + r + 1 ) >> 1;
		if ( 2 + ( ( mid * ( mid - 1 ) ) >> 1 ) <= n )
			l = mid;
		else
			r = mid - 1;
	}*/

	int ans;
	lpi ( i, 1, nn ){
		if ( f[i] > n ){
			ans = i - 1;
			break;
		}
	}

	printf ( "%d\n", ans );
}