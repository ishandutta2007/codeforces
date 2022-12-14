// CodeForces
// Contest - Educational Codeforces Round 11
// Contest code: 660
// Problem B
// Problem name: Seating On Bus
// Problem link: http://codeforces.com/contest/660/problem/B
// Programmed by Tianqi Yang
// 4/8/2016

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;
const int a[4] = { 1, 0, 2, 3 };

int main()
{
	ios::sync_with_stdio ( false );

	int n, m, num;
	cin >> n >> m;

	int p[101][4];
	memset ( p, 0, sizeof ( p ) );

	lp ( i, 1, (n+1) ){
		p[i][0] = 2 * i - 1;
		p[i][1] = 2 * n + 2 * i - 1;
		p[i][2] = 2 * n + 2 * i;
		p[i][3] = 2 * i;
	}

	lp ( i, 1, (n+1) ){
		lp ( j, 0, 4 ){
			if ( p[i][a[j]] <= m ) cout << p[i][a[j]] << " ";
		}
	}

	cout << endl;
}