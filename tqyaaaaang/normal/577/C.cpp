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
const int MAXN = 1007;

bool isp[MAXN];
int primes[MAXN];
int cc[MAXN];
int nc[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	memset ( isp, true, sizeof ( isp ) );

	int n, p = 0, k, t;
	cin >> n;
	lpi ( i, 2, n ){
		if ( isp[i] ){
			primes[p++] = i;
			for ( int j = i*i; j <= n; j += i ) isp[j] = false;
		}
	}

	lpi ( i, 1, n ){
		memset ( nc, 0, sizeof ( nc ) );
		k = 0;
		t = i;
		while ( k < p ){
			if ( t % primes[k] == 0 ) nc[k]++, t /= primes[k];
			else k++;
		}

		lp ( i, 0, p ) cc[i] = qmax ( cc[i], nc[i] );
	}

	int sum = 0;
	lp ( i, 0, p ) sum += cc[i];
	cout << sum << endl;

	lp ( i, 0, p ){
		t = primes[i];
		lp ( j, 0, cc[i] ){
			cout << t << " ";
			t *= primes[i];
		}
	}

	cout << endl;
}