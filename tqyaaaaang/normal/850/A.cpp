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
const int MAXN = 1007;
const int DIVI = 107;
const int DIM = 5;

struct vT
{
	void input ()
	{
		lp ( i, 0, DIM ) scanf ( "%d", &x[i] );
	}

	int operator * ( const vT &a ) const
	{
		int ans = 0;
		lp ( i, 0, DIM ) {
			ans += x[i] * a.x[i];
		}
		return ans;
	}

	vT operator - ( const vT &a ) const
	{
		vT ans;
		lp ( i, 0, DIM ) ans.x[i] = x[i] - a.x[i];
		return ans;
	}

	int x[DIM];
}cr[MAXN], tv[MAXN];

int n;
bool ok[MAXN];

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
	lpi ( i, 1, n ) cr[i].input ();
}

void work ()
{
	// main work

	if ( n > DIVI ) {
		printf ( "0\n" );
		return;
	}

	bool flag;
	int ans = 0;
	lpi ( i, 1, n ) {
		lpi ( j, 1, n ) {
			tv[j] = cr[i] - cr[j];
		}

		flag = true;
		lpi ( j, 1, n ) {
			lpi ( k, j+1, n ) {
				if ( ( j ^ i ) && ( k ^ i ) ) {
					if ( tv[j] * tv[k] > 0 ) {
						flag = false;
						break;
					}
				}
			}
			if ( !flag ) break;
		}

		if ( flag ) ++ans;
		ok[i] = flag;
	}

	printf ( "%d\n", ans );
	lpi ( i, 1, n ) {
		if ( ok[i] ) printf ( "%d\n", i );
	}
}