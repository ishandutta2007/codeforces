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
LL a[MAXN];
char stp[MAXN];
int tp[MAXN];

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
	lpi ( i, 1, n ) scanf ( "%I64d", &a[i] );
	scanf ( "%s", stp + 1 );
}

void work ()
{
	// main work

	LL lm = 0;
	lpi ( i, 1, n ) if ( stp[i] == 'L' ) lm += a[i];

	LL rem = lm, del, c1 = 0, c3 = 0, c5 = 0, f5 = 0, a1 = 0, a3 = 0, a5 = 0, ad = 0, cr;
	lpd ( i, n, 0 ) {
		if ( stp[i] == 'L' ) {
			a1 += a[i];
			rem -= a[i];
			c1 += a[i];
		} else if ( stp[i] == 'G' ) {
			a5 += a[i];
			del = qmin ( lm - rem, a[i] );
			c5 += del;
			lm -= del;
		} else {
			a3 += a[i];
			cr = a[i];
			del = qmin ( lm - rem, a[i] );
			c3 += del;
			lm -= del;
			cr -= del;
			del = qmin ( c5, cr );
			c3 += del;
			c5 -= del;
			cr -= del;
			del = qmin ( a5 - c5 - f5, cr );
			c3 += del;
			f5 += del;
			cr -= del;
		}
	}
	if ( lm ) {
		LL cd = 0, mx = 0, mp = 0;
		lpi ( i, 1, n ) {
			if ( stp[i] == 'W' ) break;
			else if ( stp[i] == 'G' ) cd += a[i];
			else if ( stp[i] == 'L' ) cd -= a[i];
			if ( -cd > mx ) mx = -cd, mp = i;
		}
		ad += mx * 5 + ( lm - mx ) * 3;
	}

	cout << c1 + c3 * 3 + ( a3 - c3 ) * 2 + c5 * 5 + ( a5 - c5 - f5 ) * 3 + f5 + ad << endl;
}