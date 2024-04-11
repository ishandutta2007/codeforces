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
const int MAXN = 300007;

int n;
int p[MAXN], c[MAXN];
int a[3][MAXN], kc[3];
int cnd[3][MAXN];

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

	scanf ( "%d", &n );
	char ts[5];
	lpi ( i, 1, n ) {
		scanf ( "%d%s", &p[i], ts );
		c[i] = ( ts[0] == 'G' ) ? 0 : ( ts[0] == 'R' ) ? 1 : 2;
	}
}

void work ()
{
	// main work

	int mini[3] = { INF, INF, INF }, maxi[3] = { -INF, -INF, -INF };
	lpi ( i, 1, n ) {
		mini[c[i]] = qmin ( mini[c[i]], p[i] ), maxi[c[i]] = qmax ( maxi[c[i]], p[i] );
		a[c[i]][++kc[c[i]]] = p[i];
	}

	if ( mini[0] == INF ) {
		int ans = 0;
		if ( mini[1] ^ INF ) ans += maxi[1] - mini[1];
		if ( mini[2] ^ INF ) ans += maxi[2] - mini[2];
		cout << ans << endl;
		return;
	}

	LL ans = maxi[0] - mini[0];
	lpi ( nc, 1, 2 ) {
		ans += qmax ( mini[0] - mini[nc], 0 );
		ans += qmax ( maxi[nc] - maxi[0], 0 );
		int ni = 1;
		for ( ; ni <= kc[nc] && a[nc][ni] < mini[0]; ++ni );
		int nmax, nl;
		lp ( i, 1, kc[0] ) {
			if ( ni <= kc[nc] && a[nc][ni] < a[0][i + 1] ) {
				nmax = a[nc][ni] - a[0][i];
				nl = a[nc][ni];
				++ni;
				for ( ; ni <= kc[nc] && a[nc][ni] < a[0][i + 1]; ++ni ) nmax = qmax ( nmax, a[nc][ni] - a[nc][ni - 1] ), nl = a[nc][ni];
				nmax = qmax ( nmax, a[0][i + 1] - nl );
				cnd[nc][i] = a[0][i + 1] - a[0][i] - nmax;
			}
		}
	}

	lp ( i, 1, kc[0] ) {
		if ( a[0][i + 1] - a[0][i] <= cnd[1][i] + cnd[2][i] ) ans += a[0][i + 1] - a[0][i];
		else ans += cnd[1][i] + cnd[2][i];
	}

	cout << ans << endl;
}