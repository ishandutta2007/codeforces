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
const int MAXN = 53;
const int MAXL = 13;
const int SIZE = 20000;

const char s[4][MAXL] =
{
	"South",
	"East",
	"North",
	"West"
};

int n, nx, dist;
char dir[MAXL];

void init ();
void input ();
void inputq ();
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
}

void inputq ()
{
	scanf ( "%d%s", &dist, dir );
}

void work ()
{
	// main work

	nx = 0;
	lp ( _n, 0, n ){
		inputq ();

		if ( !strcmp ( dir, s[0] ) ){
			nx += dist;

			if ( nx > SIZE ){
				printf ( "NO\n" );
				return;
			}
		}else if ( !strcmp ( dir, s[2] ) ){
			nx -= dist;

			if ( nx < 0 ){
				printf ( "NO\n" );
				return;
			}
		}else{
			if ( ( !nx ) || ( nx == SIZE ) ){
				printf ( "NO\n" );
				return;
			}
		}
	}

	printf ( ( nx == 0 ) ? "YES\n" : "NO\n" );
}