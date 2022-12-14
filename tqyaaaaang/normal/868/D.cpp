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
const int MAXN = 207;
const int MAXL = 107;
const int MAXA = 19;
const int ma = 15;
const int MAXS = ( 1 << 17 ) + 7;

int n, m;
int len[MAXN];
int a[MAXN][MAXL];
bool v[MAXN][MAXS];
int cl[MAXN][MAXA*2], cr[MAXN][MAXA*2];
int nl, nr;
int tmp[MAXA*2];
int tc[MAXA*2];

void init ();
void input ();
void inputq ();
void work ();

void upd ( bool v[], int now[], int len );
int con ( int a[], int b[], int c[] );



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
	char ts[MAXL];
	lpi ( i, 1, n ) {
		scanf ( "%s", ts+1 );
		len[i] = strlen ( ts+1 );
		lpi ( j, 1, len[i] ) a[i][j] = ts[j] - '0';
	}
	scanf ( "%d", &m );
}

void inputq ()
{
	// input query

	scanf ( "%d%d", &nl, &nr );
}

void work ()
{
	// main work

	INIT ( cl, -1 );
	INIT ( cr, -1 );
	lpi ( i, 1, n ) {
		lpi ( j, 1, qmin ( ma, len[i] ) ) cl[i][j] = a[i][j];
		lpi ( j, 1, qmin ( ma, len[i] ) ) cr[i][j] = a[i][len[i]-qmin ( len[i], ma )+j];
//		lpi ( j, len[i]-qmin ( len[i], ma )+1, len[i] ) cr[i][j] = a[i][j];

		upd ( v[i], a[i], len[i] );
	}

	int tl;
	int ms;
	bool flag;
	lpi ( i, n+1, n+m ) {
		inputq ();

		con ( cl[nl], cl[nr], cl[i] );
		lp ( j, ma+1, MAXA*2 ) cl[i][j] = -1;
		tl = con ( cr[nl], cr[nr], cr[i] );
		if ( tl > ma ) {
			lpi ( j, 1, ma ) cr[i][j] = cr[i][j+( tl-ma )];
		}
		lp ( j, ma+1, MAXA*2 ) cr[i][j] = -1;

		tl = con ( cr[nl], cl[nr], tmp );
		lp ( j, 0, MAXS ) v[i][j] = v[nl][j] | v[nr][j];
		upd ( v[i], tmp, tl );

		lpi ( j, 1, ma ) {
			ms = ( 1 << j );
			flag = true;
			lp ( k, 0, ms ) {
				if ( !v[i][ms|k] ) {
					flag = false;
					break;
				}
			}
			if ( !flag ) {
				printf ( "%d\n", j-1 );
				break;
			}
		}
	}
}



void upd ( bool v[], int now[], int len )
{
	int nv;
	lpi ( i, 1, ma ) {
		lpi ( j, 1, len-i+1 ) {
			nv = 0;
			lp ( k, 0, i ) {
				nv = ( nv << 1 ) | now[j+k];
			}
			v[(1<<i)|nv] = true;
		}
	}
}

int con ( int a[], int b[], int c[] )
{
	int nk = 0;
	INIT ( c, -1 );
	lp ( i, 0, MAXA ) if ( ~a[i] ) c[++nk] = a[i];
	lp ( i, 0, MAXA ) if ( ~b[i] ) c[++nk] = b[i];
	return nk;
}