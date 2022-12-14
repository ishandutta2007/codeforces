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
const int MAX = 1000007;

struct fT
{
	void setd ( int _v, int _t, int _c )
	{
		v = _v, t = _t, c = _c;
	}

	int v, t, c;
}to[MAXN], from[MAXN];

int n, m, k;
int kt, kf;
int nc[MAXN];
LL ct[MAX], _cf[MAX], cf[MAX];

void init ();
void input ();
void work ();

void calc ( fT f[], int kf, LL mc[] );



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

	scanf ( "%d%d%d", &n, &m, &k );
	int d, u, v, c;
	lpi ( i, 1, m ) {
		scanf ( "%d%d%d%d", &d, &u, &v, &c );
		if ( !u ) from[++kf].setd ( v, MAX-d-1, c );
		else to[++kt].setd ( u, d, c );
	}
}

void work ()
{
	// main work

	calc ( to, kt, ct );
	calc ( from, kf, _cf );
	lp ( i, 0, MAX ) cf[i] = _cf[MAX-i-1];

	LL ans = LINF;
	lp ( i, k+1, MAX ) {
		ans = qmin ( ans, ct[i-k-1] + cf[i] );
	}

	cout << ( ( ans ^ LINF ) ? ans : -1 ) << endl;
}



void calc ( fT f[], int kf, LL mc[] )
{
	sort ( f+1, f+1+kf, [] ( const fT &a, const fT &b ) { return a.t < b.t; } );

	INIT ( nc, -1 );

	int cc = 0, ni = 1;
	LL ans = 0;
	lp ( i, 0, MAX ) {
		for ( ; ni <= kf && f[ni].t == i; ++ni ) {
			if ( ~nc[f[ni].v] ) {
				if ( f[ni].c < nc[f[ni].v] ) {
					ans -= nc[f[ni].v] - f[ni].c;
					nc[f[ni].v] = f[ni].c;
				}
			} else {
				++cc;
				nc[f[ni].v] = f[ni].c;
				ans += f[ni].c;
			}
		}

		mc[i] = ( cc == n ) ? ans : LINF;
	}
}