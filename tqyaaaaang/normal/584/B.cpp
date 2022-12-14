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
const int MOD = 1e9+7;

int main()
{
	ios::sync_with_stdio ( false );

	int n;
	cin >> n;
	
	LL ans1 = 1, ans2 = 1;

	lp ( i, 0, n ){
		ans1 *= 27;
		ans1 %= MOD;
		ans2 *= 7;
		ans2 %= MOD;
	}

	cout << ( ( ( ans1 + MOD ) - ans2 ) % MOD ) << endl;
}