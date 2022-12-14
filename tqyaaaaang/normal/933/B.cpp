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
const int MAXN = 2007;

int n, m;
LL p;
int a[MAXN];

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

	cin >> p >> n;
}

void work ()
{
	// main work

	for ( LL t = p; t; t /= n, ++m ) a[m] = t % n;
	--m;

	lpi ( i, 0, m ) if ( i & 1 ) a[i] = -a[i];

	for ( int i = 0; ( i < MAXN ) && ( ( i <= m ) || ( a[i] >= n || a[i] < 0 ) ); ++i ) {
		while ( a[i] >= n ) {
			a[i] -= n;
			--a[i + 1];
		}
		while ( a[i] < 0 ) {
			a[i] += n;
			++a[i + 1];
		}
	}
	lpdi ( i, MAXN - 1, 0 ) {
		if ( a[i] ) {
			m = i;
			break;
		}
	}

	printf ( "%d\n", m + 1 );
	lpi ( i, 0, m ) printf ( "%d ", a[i] );
	putchar ( '\n' );
}