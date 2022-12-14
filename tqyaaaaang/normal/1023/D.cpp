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

int n, q;
int a[MAXN];
int pre[MAXN];
int stk[MAXN], top;

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

	scanf ( "%d%d", &n, &q );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	bool hmx = ( *max_element ( a + 1, a + 1 + n ) == q );
	int pmn = min_element ( a + 1, a + 1 + n ) - a;

	if ( !hmx ) {
		if ( a[pmn] ) {
			printf ( "NO\n" );
			return;
		} else {
			a[pmn] = q;
		}
	}

	stk[++top] = 0;
	lpi ( i, 1, n ) {
		if ( a[i] ) {
			while ( a[stk[top]] >= a[i] ) --top;
			if ( pre[a[i]] && stk[top] > pre[a[i]] ) {
				printf ( "NO\n" );
				return;
			}
			pre[a[i]] = i;
			stk[++top] = i;
		}
	}

	a[0] = 1;
	lpi ( i, 1, n ) if ( !a[i] ) a[i] = a[i - 1];

	printf ( "YES\n" );
	lpi ( i, 1, n ) printf ( "%d ", a[i] );
	putchar ( '\n' );
}