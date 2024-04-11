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
const int MAXN = 107;
const int MAX = 507;

int n, m;
int a[MAXN][MAXN];
int r[MAXN], c[MAXN];

void init ();
void input ();
void work ();

int check ( int cn );



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

	scanf ( "%d%d", &n, &m );
	lpi ( i, 1, n ) lpi ( j, 1, m ) scanf ( "%d", &a[i][j] );
}

void work ()
{
	// main work

	int mini = INF, mp = -1, ret;
	lpi ( i, 0, MAX ){
		ret = check ( i );
		if ( ret < mini ) mini =ret, mp = i;
	}

	if ( ~mp ){
		check ( mp );
		printf ( "%d\n", mini );
		lpi ( i, 1, n ) lp ( j, 0, r[i] ) printf ( "row %d\n", i );
		lpi ( i, 1, m ) lp ( j, 0, c[i] ) printf ( "col %d\n", i );
	} else printf ( "-1\n" );
}



int check ( int cn )
{
	r[1] = cn;
	lpi ( i, 1, m ){
		if ( a[1][i] < r[1] ) return INF;
		c[i] = a[1][i] - r[1];
	}
	lpi ( i, 2, n ){
		if ( a[i][1] < c[1] ) return INF;
		r[i] = a[i][1] - c[1];
		lpi ( j, 1, m ){
			if ( ( a[i][j] - c[j] ) ^ r[i] ) return INF;
		}
	}

	int ans = 0;
	lpi ( i, 1, n ) ans += r[i];
	lpi ( i, 1, m ) ans += c[i];
	return ans;
}