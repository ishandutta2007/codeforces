// CodeForces
// Contest - Codeforces Round #323 (Div. 2)
// Contest code: 583
// Problem A
// Problem name: Asphalting Roads
// Problem link: http://codeforces.com/contest/583/problem/A
// Programmed by Tianqi Yang
// 4/26/2016

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
const int MAXN = 55;

bool v[MAXN], h[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	lp ( i, 0, MAXN ) v[i] = true, h[i] = true;

	int n, x, y;
	cin >> n;

	lpi ( i, 1, n*n ){
		cin >> x >> y;

		if ( h[x] && v[y] ){
			cout << i << " ";
			h[x] = v[y] = false;
		}
	}

	cout << endl;
}