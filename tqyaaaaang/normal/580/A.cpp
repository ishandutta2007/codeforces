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

int main()
{
	ios::sync_with_stdio ( false );

	int n, last, now, nlen, mlen;

	cin >> n;

	last = 0, nlen = mlen = 0;
	lp ( i, 0, n ){
		cin >> now;
		if ( now >= last ){
			nlen++;
		}else{
			mlen = qmax ( mlen, nlen );
			nlen = 1;
		}

		last = now;
	}

	mlen = qmax ( mlen, nlen );

	cout << mlen << endl;
}