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
const int MAXN = 600007;

int n, L;
int a[MAXN], b[MAXN];
LL cb[MAXN];
int al[MAXN], ar[MAXN];

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

	scanf ( "%d%d", &n, &L );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
	lpi ( i, 1, n ) scanf ( "%d", &b[i] );
}

void work ()
{
	// main work

	sort ( a + 1, a + 1 + n );
	sort ( b + 1, b + 1 + n );

	lpi ( i, 1, n ) cb[i + n] = b[i], cb[i] = cb[i + n] - L, cb[i + n + n] = cb[i + n] + L;
	cb[n * 3 + 1] = LINF;

	int l = 0, r = L, mid;
	while ( l < r ) {
		mid = ( l + r ) >> 1;
		if ( check ( mid ) ) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
}



bool check ( int tst )
{
	int cl = 1, cr = 1;
	lpi ( i, 1, n ) {
		while ( a[i] - cb[cl] > tst ) ++cl;
		al[i] = cl - n;
		while ( cb[cr + 1] - a[i] <= tst ) ++cr;
		ar[i] = cr - n;
	}

	int beg = n + 1;
	lpi ( i, 1, n ) {
		if ( al[i] <= 0 ) {
			al[i + n] = al[i] + n, ar[i + n] = ar[i] + n;
		} else {
			beg = i;
			break;
		}
	}
	lpi ( i, 1, n ) al[i] = al[i + beg - 1], ar[i] = ar[i + beg - 1];

	int maxi = 1;
	lpi ( i, 1, n ) {
		maxi = qmax ( maxi, al[i] - i + 1 );
	}

	lpi ( i, 1, n ) {
		if ( maxi + i - 1 > ar[i] ) {
			return false;
		}
	}

	return true;
}