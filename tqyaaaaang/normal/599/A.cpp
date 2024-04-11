#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

int main()
{
	ios::sync_with_stdio ( false );

	int d1, d2, d3;

	cin >> d1 >> d2 >> d3;

	if ( d1 + d2 <= d3 )
		cout << ( 2 * ( d1 + d2 ) ) << endl;
	else if ( d2 + d3 <= d1 )
		cout << ( 2 * ( d2 + d3 ) ) << endl;
	else if ( d1 + d3 <= d2 )
		cout << ( 2 * ( d1 + d3 ) ) << endl;
	else
		cout << ( d1 + d2 + d3 ) << endl;
}