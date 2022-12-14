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
const int MAXS = 2000007;

int OK[3*3*3*3];

class ftT
{
public:
	void upd ( int p, int x )
	{
		for ( ; p < MAXN; p += p&-p ) data[p] += x;
	}

	int sum ( int p )
	{
		int ans = 0;
		for ( ; p; p ^= p&-p ) ans += data[p];
		return ans;
	}

private:
	int data[MAXN];
}ft;

struct qT
{
	int l, d, r, u;
}que[MAXN];

struct oT
{
	void setd ( int _id, int _x, int _y )
	{
		id = _id, x = _x, y = _y;
	}

	int id, x, y, ans;
}nq[MAXS];

int n, q;
int nk;
int cp[MAXN], p[MAXN];
int nt[3][3];

void init ();
void input ();
void work ();

void presolve ();



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

	lp ( a, 0, 3 ) {
		lp ( b, 0, 3 ) {
			lp ( c, 0, 3 ) {
				lp ( d, 0, 3 ) {
					if ( a * 3 + b < c * 3 + d ) {
						if ( ( qmin ( a, c ) <= 1 && qmax ( a, c ) >= 1 ) && ( qmin ( b, d ) <= 1 && qmax ( b, d ) >= 1 ) ) {
							OK[a*27+b*9+c*3+d] = 1;
						}
					}
				}
			}
		}
	}
}

void input ()
{
	// input method

	scanf ( "%d%d", &n, &q );
	lpi ( i, 1, n ) scanf ( "%d", &cp[i] );
	lpi ( i, 1, q ) scanf ( "%d%d%d%d", &que[i].l, &que[i].d, &que[i].r, &que[i].u );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) p[cp[i]] = i;

	nk = 0;
	int nx, ny;
	lpi ( i, 1, q ) {
		lp ( j, 0, 3 ) {
			nx = ( j == 0 ) ? ( que[i].d - 1 ) : ( j == 1 ) ? ( que[i].u ) : n;
			lp ( k, 0, 3 ) {
				ny = ( k == 0 ) ? ( que[i].l - 1 ) : ( k == 1 ) ? ( que[i].r ) : n;
				nq[++nk].setd ( nk, nx, ny );
			}
		}
	}

	presolve ();

	nk = 0;
	LL ans = 0;
	int na, nb, nc, nd;
	lpi ( i, 1, q ) {
		lp ( j, 0, 3 ) {
			lp ( k, 0, 3 ) {
				nt[j][k] = nq[++nk].ans;
			}
		}

		lp ( a, 0, 3 ) {
			na = a * 27;
			lp ( b, 0, 3 ) {
				nb = na + b * 9;
				lp ( c, 0, 3 ) {
					nc = nb + c * 3;
					lp ( d, 0, 3 ) {
						nd = nc + d;
						if ( c <= a && d <= b && ( ( a ^ c ) || ( b ^ d ) ) ) {
							nt[a][b] -= nt[c][d];
						}
					}
				}
			}
		}

		ans = 0;

		lp ( a, 0, 3 ) {
			na = a * 27;
			lp ( b, 0, 3 ) {
				nb = na + b * 9;
				lp ( c, 0, 3 ) {
					nc = nb + c * 3;
					lp ( d, 0, 3 ) {
						nd = nc + d;
						if ( OK[nd] ) {
							ans += SC ( LL, nt[a][b] ) * nt[c][d];
						}
					}
				}
			}
		}

		ans += SC ( LL, nt[1][1] ) * ( nt[1][1] - 1 ) >> 1;

		printf ( "%I64d\n", ans );
	}
}



void presolve ()
{
	sort ( nq+1, nq+1+nk, [] ( const oT &a, const oT &b ) { return ( a.x ^ b.x ) ? ( a.x < b.x ) : ( a.y < b.y ); } );

	int iq = 1;
	for ( ; iq <= nk && nq[iq].x == 0; ++iq );
	lpi ( i, 1, n ) {
		ft.upd ( p[i], 1 );

		for ( ; iq <= nk && nq[iq].x == i; ++iq ) {
			nq[iq].ans = ft.sum ( nq[iq].y );
		}
	}

	sort ( nq+1, nq+1+nk, [] ( const oT &a, const oT &b ) { return a.id < b.id; } );
}