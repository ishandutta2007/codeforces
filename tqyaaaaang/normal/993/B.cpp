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
const int MAXN = 33;

int n, m;
PII a[MAXN], b[MAXN];

void init ();
void input ();
void work ();

int getnum ( PII a, PII b )
{
	int x[2], y[2];
	x[0] = a.first, x[1] = a.second, y[0] = b.first, y[1] = b.second;
	lp ( i, 0, 2 ) {
		lp ( j, 0, 2 ) {
			if ( x[i] == y[j] && ( x[i ^ 1] ^ y[j ^ 1] ) ) {
				return x[i];
			}
		}
	}
	return 0;
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
}

void input ()
{
	// input method

	cin >> n >> m;
	lpi ( i, 1, n ) cin >> a[i].first >> a[i].second;
	lpi ( i, 1, m ) cin >> b[i].first >> b[i].second;
}

void work ()
{
	// main work

	int ans = -1, cur = 0;
	lpi ( i, 1, n ) {
		lpi ( j, 1, m ) {
			cur = getnum ( a[i], b[j] );
			if ( cur ) {
				if ( ans == -1 ) ans = cur;
				else if ( ans && ( ans ^ cur ) ) ans = 0;
			}
		}
	}

	if ( ans ) {
		cout << ans << endl;
		return;
	}

	lpi ( i, 1, n ) {
		ans = -1;
		lpi ( j, 1, m ) {
			cur = getnum ( a[i], b[j] );
			if ( cur ) {
				if ( ans == -1 ) ans = cur;
				else if ( ans && ( ans ^ cur ) ) ans = 0;
			}
		}
		if ( ans == 0 ) {
			cout << -1 << endl;
			return;
		}
	}
	lpi ( j, 1, m ) {
		ans = -1;
		lpi ( i, 1, n ) {
			cur = getnum ( a[i], b[j] );
			if ( cur ) {
				if ( ans == -1 ) ans = cur;
				else if ( ans && ( ans ^ cur ) ) ans = 0;
			}
		}
		if ( ans == 0 ) {
			cout << -1 << endl;
			return;
		}
	}

	cout << 0 << endl;
}