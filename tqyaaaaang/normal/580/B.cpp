#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( LL loop = start; loop < end; loop++ )
#define lpd(loop,start,end) for ( LL loop = start; loop > end; loop-- )
#define lpi(loop,start,end) for ( LL loop = start; loop <= end; loop++ )
#define lpdi(loop,start,end) for ( LL loop = start; loop >= end; loop-- )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const LL INF = 0x3fffffff;
const LL SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const LL MAXN = 1e5+7;

struct pT
{
	bool operator < ( const pT &a ) const
	{
		return m < a.m;
	}

	LL m, s;
}p[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	LL n, d, l, r, ns, ms;

	cin >> n >> d;
	lp ( i, 0, n ) cin >> p[i].m >> p[i].s;

	sort ( p, p+n );

	l = 0, r = 0;
	ns = ms = 0;
	while ( r < n ){
		ns += p[r].s;
		
		while ( p[r].m - p[l].m >= d ) ns -= p[l].s, l++;

		ms = qmax ( ms, ns );

		r++;
	}

	cout << ms << endl;
}