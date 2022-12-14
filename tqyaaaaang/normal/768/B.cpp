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
const int MAXN = 57;

int lev;
LL n, l, r;
LL c1[MAXN], len[MAXN];

void init ();
void input ();
void work ();

void dps ( LL now, int nl );
LL getans ( LL now, int nl = 1 );



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

	cin >> n >> l >> r;
}

void work ()
{
	// main work

	dps ( n, 1 );

	cout << ( getans ( r ) - getans ( l - 1 ) ) << endl;
}



void dps ( LL now, int nl )
{
	lev = nl;
	c1[nl] = now & 1;
	len[nl] = 1;
	if ( now > 1 ){
		dps ( now>>1, nl+1 );
		c1[nl] += c1[nl+1]<<1;
		len[nl] += len[nl+1]<<1;
	}
}

LL getans ( LL now, int nl )
{
	if ( !now ) return 0;
//	if ( len[nl] == 1 ) return c1[nl];
	if ( now <= len[nl] ) return getans ( now, nl+1 );
	else if ( now == len[nl] + 1 ) return c1[nl-1] - c1[nl];
	else return getans ( now-len[nl]-1, nl+1 ) + ( c1[nl-1] - c1[nl] );
}