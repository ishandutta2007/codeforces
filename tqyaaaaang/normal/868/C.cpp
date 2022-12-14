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
const int MAXK = 7;
const int MAXS = 19;

int n, k;
int a[MAXN][MAXK];
int c[MAXS];

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

	scanf ( "%d%d", &n, &k );
	lpi ( i, 1, n ) lpi ( j, 1, k ) scanf ( "%d", &a[i][j] );
}

void work ()
{
	// main work

	int ns;
	lpi ( i, 1, n ) {
		ns = 0;
		lpi ( j, 1, k ) if ( a[i][j] ) ns |= ( 1 << ( j - 1 ) );
		++c[ns];
	}

	int ks = ( 1 << k );
	int ms = ( 1 << ks );
	bool flag;
	lp ( i, 1, ms ) {
		flag = true;
		lp ( j, 0, ks ) {
			if ( ( i >> j & 1 ) && !c[j] ) {
				flag = false;
				break;
			}
		}
		if ( flag ) {
			int cc[4] = { 0 };
			lp ( j, 0, ks ) {
				if ( ( i >> j & 1 ) ) {
					lp ( a, 0, k ) {
						if ( j >> a & 1 ) ++cc[a];
						else --cc[a];
					}
				}
			}

			lp ( a, 0, k ) {
				if ( cc[a] > 0 ) {
					flag = false;
					break;
				}
			}
		}

		if ( flag ) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}