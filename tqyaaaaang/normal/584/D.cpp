#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( int loop = start; loop < end; loop++ )
#define lpd(loop,start,end) for ( int loop = start; loop > end; loop-- )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; loop++ )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; loop-- )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 1e9+7;
const int MAXSQRT = 1e5;

bool prime[MAXSQRT];

bool isPrime ( int x );

int main()
{
	ios::sync_with_stdio ( false );
	
	lp ( i, 0, MAXSQRT ) prime[i] = true;
	prime[0] = prime[1] = false;
	lp ( i, 2, MAXSQRT )
		if ( prime[i] )
			for ( LL j = SC(LL,i) * SC(LL,i); j < MAXSQRT; j += i )
				prime[j] = false;

	int n;

	cin >> n;

	switch ( n ){
	case 3:
		printf ( "1\n3\n" );
		break;

	case 4:
		printf ( "2\n2 2\n" );
		break;

	case 5:
		printf ( "1\n5\n" );
		break;

	case 6:
		printf ( "3\n2 2 2\n" );
		break;

	default:   // n >= 7
		printf ( "3\n3 " );
		n -= 3;
		lp ( i, 2, MAXSQRT )
			if ( prime[i] && isPrime ( n - i ) ){
				printf ( "%d %d\n", i, n-i );
				break;
			}
	}
}

bool isPrime ( int x )
{
	int size = SC(int,sqrt(SC(LD,x)));

	lpi ( i, 2, size )
		if ( x % i == 0 ) return false;

	return true;
}