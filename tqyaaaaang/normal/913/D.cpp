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
const int MAXN = 200007;

struct iT
{
	bool operator < ( const iT &x ) const
	{
		return t < x.t;
	}

	int a, t, id;
}it[MAXN];

int n, T;

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

	scanf ( "%d%d", &n, &T );
	lpi ( i, 1, n ) scanf ( "%d%d", &it[i].a, &it[i].t ), it[i].id = i;
}

void work ()
{
	// main work

	sort ( it + 1, it + 1 + n, [] ( const iT &x, const iT &y ) { return x.a > y.a; } );

	priority_queue < iT > pq;

	int il = 1, ans = 0, nc = 0;
	iT nt;
	bool flag;
	lpi ( i, 1, n ) {
		if ( il > n || it[il].a < i ) break;
		pq.push ( it[il] ), nc += it[il].t, ++il;
		flag = true;
		while ( nc > T ) {
			nc -= pq.top ().t, pq.pop ();
			if ( il > n || it[il].a < i ) {
				flag = false;
				break;
			}
			pq.push ( it[il] ), nc += it[il].t, ++il;
		}
		if ( flag ) ans = i;
		else break;
	}

	printf ( "%d\n%d\n", ans, ans );
	while ( !pq.empty () ) {
		printf ( "%d ", pq.top ().id );
		pq.pop ();
	}
	putchar ( '\n' );
}