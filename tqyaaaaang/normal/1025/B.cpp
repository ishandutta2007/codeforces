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
const int MAXN = 150007;

int n;
int a[MAXN], b[MAXN];

void init ();
void input ();
void work ();

AR ( int ) getfrac ( int x )
{
	AR ( int ) ans;
	int t = x;
	for ( int i = 2; i * i <= x; ++i ) {
		if ( t % i == 0 ) {
			ans.push_back ( i );
			while ( t % i == 0 ) t /= i;
		}
	}
	if ( t ^ 1 ) ans.push_back ( t );
	return ans;
}

void trynum ( int x )
{
	AR ( int ) f = getfrac ( x );
	bool flag;
	for ( auto x : f ) {
		flag = true;
		lpi ( i, 1, n ) {
			if ( a[i] % x && b[i] % x ) {
				flag = false;
				break;
			}
		}
		if ( flag ) {
			cout << x << endl;
			exit ( 0 );
		}
	}
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

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d%d", &a[i], &b[i] );
}

void work ()
{
	// main work

	trynum ( a[1] );
	trynum ( b[1] );

	cout << -1 << endl;
}