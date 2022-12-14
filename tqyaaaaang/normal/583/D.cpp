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
const int MAXN = 107;
const int MAX = 303;

int a[MAXN];
int ex[MAXN*MAXN];
int lis[MAXN*MAXN];
int cc[MAX];

int main()
{
	ios::sync_with_stdio ( false );
	
	int n, T, ext, exed, l, r, mid;

	memset ( cc, 0, sizeof ( cc ) );

	cin >> n >> T;
	lp ( i, 0, n ) cin >> a[i];
	lp ( i, 0, n ) cc[a[i]]++;

	ext = qmin ( n+3, T );

	int k = 0;
	lp ( i, 0, ext )
		lp ( j, 0, n ) ex[k] = a[j], k++;

	exed = 1;
	lp ( i, 0, k ){
		l = 1, r = exed;
		
		while ( l < r ){
			mid = ( l + r ) / 2;
			if ( ex[i] < lis[mid] ){
				r = mid;
			}else{
				l = mid + 1;
			}
		}

		lis[l] = ex[i];
		if ( l == exed ) exed++;
	}

	int maxi = 0;
	lp ( i, 0, MAX ){
		maxi = qmax ( maxi, cc[i] );
	}

	maxi = maxi * ( T-ext ) + exed-1;

	cout << maxi << endl;
}