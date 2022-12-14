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

#define BS bitset < MAXN >

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 10007;

int n, L, R;
int a[MAXN], b[MAXN], na, nb;
int ia[MAXN], ib[MAXN];
BS da, db[MAXN];

void init ();
void input ();
void work ();

bool check ( int tst );



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

	scanf ( "%d%d%d", &n, &L, &R );
	lpi ( i, 1, n ) scanf ( "%d", &ia[i] );
	lpi ( i, 1, n ) scanf ( "%d", &ib[i] );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) {
		if ( !ib[i] ) a[++na] = ia[i];
		else b[++nb] = ia[i];
	}

	sort ( b + 1, b + nb + 1 );

	da[0] = 1;
	lpi ( i, 1, na ) da |= da << a[i];
	db[nb+1][0] = 1;
	lpd ( i, nb, 0 ) db[i] = db[i + 1] | ( db[i + 1] << b[i] );

	int l = 0, r = nb, mid;
	while ( l < r ) {
		mid = ( l + r + 1 ) >> 1;
		if ( check ( mid ) ) l = mid;
		else r = mid - 1;
	}

	cout << l << endl;
}



bool check ( int tst )
{
	if ( !tst ) return true;

	--tst;
	int ps = 0;
	lpi ( i, 1, tst ) ps += b[i];
	int rst = 0;
	lpi ( i, tst + 1, nb ) rst += b[i];

	BS cur = da;
	lp ( i, 0, rst ) if ( db[tst + 1][i] ) cur |= ( da << i );

	lpi ( i, L, R ) {
		if ( cur[i] && ( i + ps <= R ) ) return true;
	}

	return false;
}