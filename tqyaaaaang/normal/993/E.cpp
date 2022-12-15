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

#define CX complex < double >

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXL = 20;
const int MAXN = 200007;
const int MAXS = MAXN * 2;
const LD PI = acos ( -1.0 );

int n, X;
int a[MAXN];
LL ans[MAXN], tmp[MAXN];
int tl[MAXN], tr[MAXN], nl, nr;
CX cp[MAXS], cans[MAXS], rt[MAXS];
CX irt[MAXL][MAXS];

void init ();
void input ();
void work ();

void divi ( int l, int r );

void mul ( int a[], int n, int b[], int m, LL ans[] );
void fft ( CX ar[], int tn );



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

	int cn;
	lp ( j, 0, MAXL ) {
		cn = 1 << j;
		lp ( i, 0, cn ) irt[j][i] = CX ( cos ( 2 * PI * i / cn ), sin ( 2 * PI * i / cn ) );
	}
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &X );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] ), a[i] = a[i] < X;
}

void work ()
{
	// main work

	lpi ( i, 1, n ) ++ans[a[i]];

	divi ( 1, n );

	lpi ( i, 0, n ) printf ( "%I64d ", ans[i] );
	putchar ( '\n' );
}



void divi ( int l, int r )
{
	if ( l == r ) return;

	int mid = ( l + r ) >> 1;
	nl = nr = 0;
	tl[0] = tr[0] = 0;
	lpdi ( i, mid, l ) {
		if ( a[i] ) ++nl, tl[nl] = 0;
		++tl[nl];
	}
	lpi ( i, mid + 1, r ) {
		if ( a[i] ) ++nr, tr[nr] = 0;
		++tr[nr];
	}

	mul ( tl, nl, tr, nr, tmp );
	lpi ( i, 0, nl + nr ) ans[i] += tmp[i];

	divi ( l, mid );
	divi ( mid + 1, r );
}



void fft ( CX ar[], int tn )
{
	for ( int i = 0, j = 0; i < tn; ++i ) {
		if ( i > j ) swap ( ar[i], ar[j] );
		for ( int bt = tn >> 1; bt && ( !( ( j ^= bt ) & bt ) ); bt >>= 1 );
	}

	int m;
	CX x, y;
	for ( int i = 2; i <= tn; i <<= 1 ) {
		m = i >> 1;
		for ( int j = 0; j < tn; j += i ) {
			lp ( k, 0, m ) {
				x = ar[j + k], y = ar[j + k + m] * rt[tn / i * k];
				ar[j + k] = x + y;
				ar[j + k + m] = x - y;
			}
		}
	}
}

void mul ( int a[], int n, int b[], int m, LL ans[] )
{
	int nm = n + m;
	if ( SC ( LL, n ) * m <= 1000 ) {
		lpi ( i, 0, nm ) ans[i] = 0;
		lpi ( i, 0, n ) {
			lpi ( j, 0, m ) {
				ans[i+j] += SC ( LL, a[i] ) * b[j];
			}
		}
		return;
	}

	int tn = 1, tb = 0, ub = qmax ( n, m );
	while ( tn <= nm ) tn <<= 1, ++tb;
	lp ( i, 0, tn ) rt[i] = irt[tb][i];
	lpi ( i, n + 1, ub ) a[i] = 0;
	lpi ( i, m + 1, ub ) b[i] = 0;
	lpi ( i, 0, ub ) cp[i] = CX ( a[i], b[i] );
	lp ( i, ub + 1, tn ) cp[i] = 0;
	fft ( cp, tn );
	cp[tn] = cp[0];
	lp ( i, 0, tn ) cans[i] = ( ( cp[i] + conj ( cp[tn - i] ) ) / CX ( 2, 0 ) ) * ( ( conj ( cp[tn - i] ) - cp[i] ) * CX ( 0, 0.5 ) ), rt[i] = conj ( rt[i] );
	fft ( cans, tn );
	lpi ( i, 0, nm ) ans[i] = SC ( LL, floor ( cans[i].real () / tn + 0.5 ) );
}