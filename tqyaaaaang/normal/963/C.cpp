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
int MOD[10];

int n, cw, ch;
LL w[MAXN], h[MAXN], c[MAXN];
LL aw[MAXN], ah[MAXN];
AR ( AR ( LL ) ) a;

void init ();
void input ();
void work ();

LL gcd ( LL x, LL y )
{
	return y ? gcd ( y, x%y ) : x;
}

bool iseq ( LL ax, LL ay, LL bx, LL by )
{
	lp ( i, 0, 10 ) {
		if ( ( ( ax % MOD[i] ) * ( by % MOD[i] ) % MOD[i] ) != ( ( bx % MOD[i] ) * ( ay % MOD[i] ) % MOD[i] ) ) return false;
	}
	return true;
}



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

	srand ( ( unsigned ) time ( NULL ) );

	MOD[0] = 998244353;
	MOD[1] = SC ( int, 1e9 + 7 );
	MOD[2] = SC ( int, 1e9 + 9 );
	MOD[3] = 1004535809;
	MOD[4] = 104857601;
	lp ( i, 5, 10 ) MOD[i] = rand () * RAND_MAX + rand ();
}

void input ()
{
	// input method

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%I64d%I64d%I64d", &w[i], &h[i], &c[i] );
}

void work ()
{
	// main work

	set < LL > sw, sh;
	lpi ( i, 1, n ) sw.insert ( w[i] ), sh.insert ( h[i] );

	cw = sw.size (), ch = sh.size ();
	if ( ( SC ( LL, cw ) * ch ) > n ) {
		cout << 0 << endl;
		return;
	}

	int kc = 0;
	for ( auto x : sw ) aw[++kc] = x;
	kc = 0;
	for ( auto x : sh ) ah[++kc] = x;

	a.resize ( cw + 1 );
	lpi ( i, 1, cw ) a[i].resize ( ch + 1, 0 );

	int iw, ih;
	lpi ( i, 1, n ) {
		iw = lower_bound ( aw + 1, aw + 1 + cw, w[i] ) - aw;
		ih = lower_bound ( ah + 1, ah + 1 + ch, h[i] ) - ah;
		a[iw][ih] += c[i];
	}

	lpi ( i, 1, cw ) {
		lpi ( j, 1, ch ) {
			if ( !a[i][j] ) {
				cout << 0 << endl;
				return;
			}
		}
	}

	lpi ( i, 2, cw ) {
		lpi ( j, 2, ch ) {
			if ( !iseq ( a[i][j], a[i][1], a[1][j], a[1][1] ) ) {
				cout << 0 << endl;
				return;
			}
		}
	}

	LL gw = a[1][1];
	lpi ( i, 2, cw ) gw = gcd ( gw, a[i][1] );
	LL gh = a[1][1];
	lpi ( i, 2, ch ) gh = gcd ( gh, a[1][i] );
	if ( gw % ( a[1][1] / gh ) ) {
		cout << 0 << endl;
	}
	LL g = gw / ( a[1][1] / gh );

	int ans = 0;
	for ( int i = 1; SC ( LL, i ) * i <= g; ++i ) {
		if ( g % i == 0 ) {
			++ans;
			if ( ( SC ( LL, i ) * i ) != g ) ++ans;
		}
	}

	cout << ans << endl;
}