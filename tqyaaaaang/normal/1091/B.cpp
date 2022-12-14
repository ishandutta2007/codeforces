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

int n;
int x[MAXN], y[MAXN];
int dx[MAXN], dy[MAXN];
set < PII > sd;

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
	lpi ( i, 1, n ) scanf ( "%d%d", &x[i], &y[i] );
	lpi ( i, 1, n ) scanf ( "%d%d", &dx[i], &dy[i] );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) sd.insert ( MP ( dx[i], dy[i] ) );

	int tx, ty;
	bool flag;
	lpi ( i, 1, n ) {
		tx = x[1] + dx[i], ty = y[1] + dy[i];
		flag = true;
		lpi ( j, 2, n ) {
			if ( sd.find ( MP ( tx - x[j], ty - y[j] ) ) == sd.end () ) {
				flag = false;
				break;
			}
		}
		if ( flag ) {
			cout << tx << " " << ty << endl;
			return;
		}
	}
}