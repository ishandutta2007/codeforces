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

int n, m, cl, ce, v, q;
int l[MAXN];
int e[MAXN];
int sx, sy, tx, ty;

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

	scanf ( "%d%d%d%d%d", &n, &m, &cl, &ce, &v );
	lpi ( i, 1, cl ) scanf ( "%d", &l[i] );
	lpi ( i, 1, ce ) scanf ( "%d", &e[i] );
	scanf ( "%d", &q );
}

void work ()
{
	// main work

	int ni, ans;
	lp ( _q, 0, q ) {
		scanf ( "%d%d%d%d", &sx, &sy, &tx, &ty );

		if ( sx == tx ) {
			printf ( "%d\n", qabs ( sy - ty ) );
			continue;
		}

		ans = INF;
		ni = upper_bound ( l + 1, l + 1 + cl, sy ) - l;
		if ( ni <= cl ) ans = min ( ans, qabs ( l[ni] - sy ) + qabs ( l[ni] - ty ) + qabs ( sx - tx ) );
		--ni;
		if ( ni > 0 ) ans = min ( ans, qabs ( l[ni] - sy ) + qabs ( l[ni] - ty ) + qabs ( sx - tx ) );

		ni = upper_bound ( e + 1, e + 1 + ce, sy ) - e;
		if ( ni <= ce ) ans = min ( ans, qabs ( e[ni] - sy ) + qabs ( e[ni] - ty ) + ( qabs ( sx - tx ) + v - 1 ) / v );
		--ni;
		if ( ni > 0 ) ans = min ( ans, qabs ( e[ni] - sy ) + qabs ( e[ni] - ty ) + ( qabs ( sx - tx ) + v - 1 ) / v );

		printf ( "%d\n", ans );
	}
}