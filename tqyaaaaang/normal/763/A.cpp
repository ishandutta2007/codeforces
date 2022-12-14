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
/*
struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}

	int u, v, last;
}edge[MAXN*2];*/

int n;
int u[MAXN], v[MAXN];
int c[MAXN];
int dd[MAXN];

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
	lp ( i, 1, n ) scanf ( "%d%d", &u[i], &v[i] );
	lpi ( i, 1, n ) scanf ( "%d", &c[i] );
}

void work ()
{
	// main work

	INIT ( dd, 0 );
	lp ( i, 1, n ) if ( c[u[i]] ^ c[v[i]] ) ++dd[u[i]], ++dd[v[i]];

	bool f0 = true;
	int cfb1 = 0, c1 = 0, b1v = 0, b1p;
	lpi ( i, 1, n ){
		if ( dd[i] ){
			f0 = false;
			if ( dd[i] > 1 ) ++cfb1, b1v = dd[i], b1p = i;
			else ++c1;
		}
	}

	if ( f0 ){
		printf ( "YES\n1\n" );
	}else if ( cfb1 > 1 ){
		printf ( "NO\n" );
	}else{
		if ( !cfb1 && c1 == 2 ){
			lpi ( i, 1, n ){
				if ( dd[i] ){
					printf ( "YES\n%d\n", i );
					return;
				}
			}
		}else if ( cfb1 && b1v == c1 ){
			printf ( "YES\n%d\n", b1p );
		}else
			printf ( "NO\n" );
	}
}