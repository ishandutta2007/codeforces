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
const int MAX = 100007;

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

int n;
int a[MAXN];
AR( int ) p[MAX];

void init ();
void input ();
void work ();

int move ( int l, int r );



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

	lpi ( i, 1, n ) p[a[i]].push_back ( i ), ft.upd ( i, 1 );

	int np = 0;
	LL ans = 0;
	int ni, size;

	lp ( i, 1, MAX ){
		if ( !p[i].size () ) continue;

		size = p[i].size ();

		if ( np >= *p[i].rbegin () ) ni = 0;
		else ni = upper_bound ( p[i].begin (), p[i].end (), np ) - p[i].begin ();

		lp ( j, ni, size ){
			ans += move ( np, p[i][j] );
			ft.upd ( p[i][j], -1 );
			np = p[i][j];
		}

		lp ( j, 0, ni ){
			ans += move ( np, p[i][j] );
			ft.upd ( p[i][j], -1 );
			np = p[i][j];
		}
	}

	cout << ans << endl;
}



int move ( int l, int r )
{
	if ( l <= r ){
		return ft.sum ( r ) - ft.sum ( l );
	} else{
		return ft.sum ( r ) + ft.sum ( n ) - ft.sum ( l );
	}
}