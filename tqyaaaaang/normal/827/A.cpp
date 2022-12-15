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
const int MAXL = 1000007;

struct eT
{
	void setd ( int _t, int _i, int _j )
	{
		t = _t, id = _i, nj = _j;
	}

	bool operator < ( const eT &a ) const
	{
		return t < a.t;
	}

	int t, id, nj;
}ev[MAXL];

int n;
string s[MAXN];
AR( int ) ar[MAXN];
char buf[MAXL];

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
	int ts;
	lpi ( i, 1, n ){
		scanf ( "%s%d", buf, &ts );
		s[i] = buf, ar[i].resize ( ts );
		lp ( j, 0, ts ) scanf ( "%d", &ar[i][j] );
	}
}

void work ()
{
	// main work

	int ml = 0, ts, ke = 0;
	lpi ( i, 1, n ){
		ml = qmax ( ml, *ar[i].rbegin () + s[i].size () - 1 );
		ts = ar[i].size ();
		lp ( j, 0, ts ) ev[++ke].setd ( ar[i][j], i, j );
	}

	sort ( ev+1, ev+1+ke );

	int nt = 0, mi = 0, mj = 0, ie = 1, ni, nj;
	lpi ( i, 1, ml ){
		while ( ie <= ke && ev[ie].t == i ){
			ni = ev[ie].id, nj = ev[ie].nj;
			if ( ar[ni][nj] + s[ni].size () - 1 > nt ){
				nt = ar[ni][nj] + s[ni].size () - 1;
				mi = ni, mj = nj;
			}
			++ie;
		}

		if ( i <= nt ){
			putchar ( s[mi][i-ar[mi][mj]] );
		} else putchar ( 'a' );
	}

	putchar ( '\n' );
}