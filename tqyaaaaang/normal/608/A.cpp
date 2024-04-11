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

	int n, s, f, t, maxi, now = 0;
	cin >> n >> s;
	vector < int > floor ( s+1 );

	lp ( i, 0, n ){
		cin >> f >> t;
		floor[f] = max ( floor[f], t );
	}

	for ( int i = s; i > 0; i--, now++ ){
		if ( now < floor[i] ) now = floor[i];
	}

	cout << now << endl;
}