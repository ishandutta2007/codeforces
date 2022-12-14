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
const int MAXN = 1005;

int a[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	int n;

	cin >> n;
	lp ( i, 0, n ) cin >> a[i];

	int p = -1, k = 0, delta = 1, ans = 0;
	while ( k < n ){
		p += delta;

		if ( delta == 1 && p == n ){
			delta = -1;
			ans++;
			continue;
		}
		if ( delta == -1 && p == -1 ){
			delta = 1;
			ans++;
			continue;
		}

		if ( a[p] <= k ) a[p] = INF, k++;
	}

	cout << ans << endl;
}