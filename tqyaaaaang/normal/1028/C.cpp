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
const int MAXN = 133007;

struct rT
{
	int xl, xr, yl, yr;
}rd[MAXN];

int n;
multiset < int > sxl, sxr, syl, syr;

void init ();
void input ();
void work ();



int main ()
{
	init ();
	input ();
	work ();
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
	lpi ( i, 1, n ) scanf ( "%d%d%d%d", &rd[i].xl, &rd[i].yl, &rd[i].xr, &rd[i].yr );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) {
		sxl.insert ( rd[i].xl );
		sxr.insert ( rd[i].xr );
		syl.insert ( rd[i].yl );
		syr.insert ( rd[i].yr );
	}

	int xl, xr, yl, yr;
	lpi ( i, 1, n ) {
		sxl.erase ( sxl.find ( rd[i].xl ) );
		sxr.erase ( sxr.find ( rd[i].xr ) );
		syl.erase ( syl.find ( rd[i].yl ) );
		syr.erase ( syr.find ( rd[i].yr ) );

		xl = *sxl.rbegin (), xr = *sxr.begin (), yl = *syl.rbegin (), yr = *syr.begin ();
		if ( xl <= xr && yl <= yr ) {
			cout << xl << " " << yl << endl;
			return;
		}

		sxl.insert ( rd[i].xl );
		sxr.insert ( rd[i].xr );
		syl.insert ( rd[i].yl );
		syr.insert ( rd[i].yr );
	}
}