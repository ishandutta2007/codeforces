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
const int MAXN = 105;

int cho[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	int n, m;
	cin >> n >> m;

	int ans = 0, maxi, x, mp, ap = 1;
	lpi ( i, 1, m ){
		maxi = 0;
		mp = 1;
		lpi ( j, 1, n ){
			cin >> x;
			if ( x > maxi ) mp = j, maxi = x;
		}

		cho[mp]++;
	}

	lpi ( i, 1, n ){
		if ( cho[i] > ans ) ans = cho[i], ap = i;
	}

	cout << ap << endl;
}