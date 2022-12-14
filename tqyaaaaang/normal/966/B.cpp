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
const int MAXN = 300007;

int n, v1, v2;
int a[MAXN];
int ord[MAXN];
int c1[MAXN], c2[MAXN], p1[MAXN], p2[MAXN];

void init ();
void input ();
void work ();

bool work ( int v1, int v2, int c1[], int c2[], int p1[], int p2[], AR ( int ) &a1, AR ( int ) &a2 );



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

	scanf ( "%d%d%d", &n, &v1, &v2 );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) ord[i] = i;
	sort ( ord + 1, ord + 1 + n, [] ( int x, int y ) { return a[x] < a[y]; } );
	sort ( a + 1, a + 1 + n );

	int nc;
	lpi ( i, 1, n ) {
		c1[i] = ( v1 + a[i] - 1 ) / a[i];
		if ( i + c1[i] - 1 > n ) c1[i] = INF;
		c2[i] = ( v2 + a[i] - 1 ) / a[i];
		if ( i + c2[i] - 1 > n ) c2[i] = INF;
	}

	p1[n + 1] = p2[n + 1] = INF;
	lpd ( i, n, 0 ) p1[i] = qmin ( p1[i + 1], c1[i] ), p2[i] = qmin ( p2[i + 1], c2[i] );

	AR ( int ) a1, a2;
	bool ans = false;
	if ( work ( v1, v2, c1, c2, p1, p2, a1, a2 ) ) ans = true;
	else if ( work ( v2, v1, c2, c1, p2, p1, a2, a1 ) ) ans = true;

	if ( ans ) {
		printf ( "Yes\n" );
		printf ( "%d %d\n", a1.size (), a2.size () );
		for ( auto x : a1 ) printf ( "%d ", x );
		putchar ( '\n' );
		for ( auto x : a2 ) printf ( "%d ", x );
		putchar ( '\n' );
	} else printf ( "No\n" );
}



bool work ( int v1, int v2, int c1[], int c2[], int p1[], int p2[], AR ( int ) &a1, AR ( int ) &a2 )
{
	int r1, l2;
	lpi ( i, 1, n ) {
		r1 = i + c1[i] - 1;
		l2 = r1 + 1;
		if ( l2 <= n ) {
			if ( l2 + p2[l2] - 1 <= n ) {
				lp ( j, 0, c1[i] ) a1.push_back ( ord[i + j] );
				lpi ( j, l2, n ) {
					if ( c2[j] == p2[l2] ) {
						lp ( k, 0, c2[j] ) a2.push_back ( ord[j + k] );
						break;
					}
				}
				return true;
			}
		}
	}
	return false;
}