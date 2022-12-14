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
const LD DINF = pow ( 2, 100 );
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;
const LD EPS = 1e-7;

int sgn ( int x )
{
	return ( x > 0 ) ? 1 : ( x < 0 ) ? -1 : 0;
}

struct iT
{
	bool operator < ( const iT &a ) const
	{
		return ( sgn ( x ) ^ sgn ( a.x ) ) ? ( sgn ( x ) < sgn ( a.x ) ) : ( x > a.x );
	}

	int v, x;
}it[MAXN];

class ftT
{
public:
	void upd ( int p, int x )
	{
		for ( ; p < MAXN; p += p & -p ) data[p] += x;
	}

	int sum ( int p )
	{
		int ans = 0;
		for ( ; p; p ^= p & -p ) ans += data[p];
		return ans;
	}

private:
	int data[MAXN];
}ft;

int n, w;
LD a[MAXN];
int dl[MAXN], dr[MAXN];
int rl[MAXN];

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

	scanf ( "%d%d", &n, &w );
	lpi ( i, 1, n ) scanf ( "%d%d", &it[i].x, &it[i].v );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) a[i] = SC ( LD, it[i].x ) / ( - it[i].v - w - EPS );
	lpi ( i, 1, n ) dl[i] = i;
	sort ( dl + 1, dl + 1 + n, [] ( const int x, const int y ) { return a[x] < a[y]; } );

	lpi ( i, 1, n ) a[i] = SC ( LD, it[i].x ) / ( - it[i].v + w + EPS );
	lpi ( i, 1, n ) dr[i] = i;
	sort ( dr + 1, dr + 1 + n, [] ( const int x, const int y ) { return a[x] < a[y]; } );

	lpi ( i, 1, n ) rl[dl[i]] = i;
	lpi ( i, 1, n ) dr[i] = rl[dr[i]];

	LL ans = 0;
	lpd ( i, n, 0 ) {
		ans += ft.sum ( dr[i] );
		ft.upd ( dr[i], 1 );
	}

	cout << ans << endl;
}