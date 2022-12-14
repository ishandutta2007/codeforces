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
const int MAXN = 1000007;

int n;
int a[MAXN];
int ch[MAXN];


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
}

void input ()
{
	// input method

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) ++ch[( i-a[i]+n )%n];

	int c1 = 0, c2 = 0;
	LL nv = 0, mini = LINF, mp = -1;
	lpi ( i, 1, n ){
		if ( i <= a[i] ) ++c1;
		else ++c2;

		nv += qabs ( i - a[i] );
	}

	mini = nv, mp = 0;
	lp ( i, 1, n ){
		nv += qabs ( a[i] - n ) - qabs ( a[i] - 1 );
		--c1;
		nv += c1 - c2;
		++c2;
		if ( nv < mini ) mini = nv, mp = i;

		c1 += ch[i], c2 -= ch[i];
	}

	mp = ( n - mp ) % n;

	printf ( "%I64d %I64d\n", mini, mp );
}