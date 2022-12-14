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

	int n;
	cin >> n;
	AR ( int ) h ( n );
	AR ( int ) sufmin ( n );
	
	lp ( i, 0, n )
		cin >> h[i];

	sufmin[n-1] = h[n-1];
	for ( int i = n-2; i >= 0; i-- ){
		sufmin[i] = min ( sufmin[i+1], h[i] );
	}

	int maxi = 0, cc = 0;
	lp ( i, 1, n ){
		if ( sufmin[i] >= h[maxi] ){
			cc++;
			maxi = i;
		}else{
			if ( h[maxi] < h[i] ) maxi = i;
		}
	}

	if ( maxi != n ) cc++;


	cout << cc << endl;
}